/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip> // For std::quoted
#include <thread>
#include <unordered_map>

#include "Application.hpp"
#include "ndds/ndds_cpp.h"
#include <rti/domain/find.hpp>
#include <dds/domain/discovery.hpp>
#include <dds/topic/BuiltinTopic.hpp>

/*****************************************************************************/
/* Unify some common functions and types between Unix and Windows            */
/*****************************************************************************/

#include <string>
#define RTI_SNPRINTF(src, srcSize, format, ...) \
	_snprintf_s(src, srcSize, _TRUNCATE, format, __VA_ARGS__)
#define RTI_STRCASECMP      _stricmp
#define RTI_STRNCASECMP     _strnicmp
#define RTI_STRTOULL        _strtoui64
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp

#define MAX_EX_STRENGTH (1000000)

/* Global variables */

//////

class ChatUserListener : public dds::sub::NoOpDataReaderListener<ChatUser> {
public:
	void on_data_available(dds::sub::DataReader<ChatUser>& reader) override {
		auto samples = reader.take();
		for (const auto& sample : samples) {
			// New instance
			if (sample.info().valid() &&
				sample.info().state().view_state() == dds::sub::status::ViewState::new_view()) {

				std::string pid_str("None");
				std::string ip_str("None");

				// find PID and IP
				auto writer_handle = sample.info().publication_handle();		
				try {
					auto participant_data = rti::sub::matched_publication_participant_data(reader, writer_handle);

					//PID
					auto all_props = participant_data.extensions().property().get_all();
					auto pid_it = all_props.find("dds.sys_info.process_id");
					if (pid_it != all_props.end()) {
						pid_str = pid_it->second;
					}

					// IP address
					for (const auto& locator : participant_data.extensions().default_unicast_locators()) {
						const auto& addr = locator.address();
						if (locator.kind() == DDS_LOCATOR_KIND_UDPv4 && (int)addr[12] == 192) {
							std::ostringstream oss;
							oss << "IP: "
								<< (int)addr[12] << "."
								<< (int)addr[13] << "."
								<< (int)addr[14] << "."
								<< (int)addr[15];
							ip_str = oss.str();
						}
					}
					
					std::cout << "# Discovered [" << sample.data().user_id() << "] running chat app in IP [" << ip_str
						<< "] with Process ID [" << pid_str << "]." << std::endl;
				}
				catch (const dds::core::Exception& e) {
					// do nothing
				}

			}
			// Instance dispose or unregister
			if (!sample.info().valid()) {
				auto istate = sample.info().state().instance_state();
				ChatUser key_holder;
				reader.key_value(key_holder, sample.info().instance_handle());
				if (istate == dds::sub::status::InstanceState::not_alive_disposed()) {
					std::cout << "# Dropped [" << key_holder.user_id() << "]."<< std::endl;
				}
				else if (istate == dds::sub::status::InstanceState::not_alive_no_writers()) { //unregistered
					std::cout << "# Dropped [" << key_holder.user_id() << "]." << std::endl;
				}
			}
		}
	}
};

/* maps [0, UINT32_MAX] -> [0, 1,000,000] with rounding, no overflow */
uint32_t map_u32_to_1e6(uint32_t x) {
	return static_cast<uint32_t>(
		(static_cast<uint64_t>(x) * MAX_EX_STRENGTH + (UINT32_MAX / 2ull)) / UINT32_MAX
		);
}

/* local time to strength */
uint32_t make_strength_from_now() {
	using namespace std::chrono;
	auto now = system_clock::now();
	auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
	auto now_c = system_clock::to_time_t(now);
	std::tm now_tm;
	localtime_s(&now_tm, &now_c);
	// strength = (h*10000000) + (m*100000) + (s*1000) + ms
	int32_t time_converted = now_tm.tm_hour * 10000000
		+ now_tm.tm_min * 100000
		+ now_tm.tm_sec * 1000
		+ static_cast<int32_t>(ms.count());

	/* ealier timestamp has a higher strength */
	uint32_t strength = MAX_EX_STRENGTH - map_u32_to_1e6(time_converted);
	return strength;
}

/* termination of dds */
void terminate_participants(void) {
	std::vector<dds::domain::DomainParticipant> participants;
	rti::domain::find_participants(std::back_inserter(participants));
	for (auto& participant : participants) {
		participant.close(); //implies dispose & unregister relevant to my App's instances
	}
}

/* Command processor in a chatApp prompt session */
void processCommand(const std::string& input) {
	std::stringstream ss(input);
	std::string cmd;
	ss >> cmd;

	if (cmd == "exit") {
		// application shutdown
		terminate_participants();
		dds::domain::DomainParticipant::finalize_participant_factory();

		exit(0);
	}
	else if (cmd == "list") {
		std::cout << "[System] Listing items..." << std::endl;
		// Logic for list goes here
	}
	else if (cmd == "send") {
		std::string target, message;
		ss >> target;

		// std::quoted handles strings with spaces wrapped in " "
		ss >> std::quoted(message);

		if (target.empty() || message.empty()) {
			std::cout << "Usage: send <target> \"message\"" << std::endl;
		}
		else {
			std::cout << ">> Sending to [" << target << "]: " << message << std::endl;
		}
	}
	else if (!cmd.empty()) {
		std::cout << "Unknown command: " << cmd << std::endl;
	}
}

/* Main Function */
int main(int argc, char* argv[]) {
	unsigned int domain_id = 0;

	rti::config::Logger::instance().verbosity(rti::config::Verbosity::SILENT);

	// --- 1. Parsing Startup Arguments ---
	std::map<std::string, std::string> args;
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg[0] == '-') {
			if (i + 1 < argc) {
				args[arg] = argv[++i];
			}
			else if (arg[1] == 'd') {
				args[arg] = "debug";
			}
			else { continue; }
		}
	}

	//Validation of arguments
	if (args.count("-u") == 0 || args.count("-g") == 0 || args.count("-f") == 0 || args.count("-l") == 0) {
		std::cout << "Please input all mandatory arguments : -u <UserName> -g <GroupName> -f <FirstName> -l <LastName>" << std::endl;
		exit(1);
	}

	// Display parsed arguments
	std::cout << "--- Session Started ---" << std::endl;
	std::cout << "User: " << args["-u"] << std::endl;
	std::cout << "Group: " << args["-g"] << std::endl;
	std::cout << "FirstName: " << args["-f"] << std::endl;
	std::cout << "LastName: " << args["-l"] << std::endl;
	if (args.count("-d") > 0) {
		std::cout << "Debug Option ENABLED." << std::endl;
	}

	// DDS initialization
	dds::domain::DomainParticipant participant(domain_id);
	dds::topic::Topic<ChatUser> topic_user(participant, "ChatUserTopic");
	dds::topic::Topic<ChatMessage> topic_message(participant, "ChatMessageTopic");

	dds::pub::Publisher publisher(participant);
	dds::sub::Subscriber subscriber(participant);	
		
	// Reader-ChatUser
	dds::sub::DataReader<ChatUser> reader_user(subscriber, topic_user);
	auto readerListener = std::make_shared<ChatUserListener>();
	reader_user.set_listener(readerListener, dds::core::status::StatusMask::all());

	// Qos setting for Writer
	dds::pub::qos::DataWriterQos writer_qos = publisher.default_datawriter_qos();
	writer_qos << dds::core::policy::Ownership::Exclusive();
	uint32_t strength = make_strength_from_now();
	writer_qos << dds::core::policy::OwnershipStrength(strength);

	dds::pub::DataWriter<ChatUser> writer_user(publisher, topic_user, writer_qos);

	// Thread for Writer-ChatUser
	ChatUser user_info(args["-u"], args["-f"], args["-l"]);
	std::thread t_user_w(ChatAppUser_WriterThread, writer_user, user_info);

	t_user_w.detach();

	// --- Main Interactive Loop ---
	std::string line;
	while (true) {
		std::cout << "chatApp> ";
		if (!std::getline(std::cin, line)) break; // Handle Ctrl+C or EOF

		if (!line.empty()) {
			processCommand(line);
		}
	}

	return 0;
}
