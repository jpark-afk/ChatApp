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
std::chrono::time_point<std::chrono::system_clock> g_reader_creation_time_ChatUser;

dds::pub::DataWriter<ChatUser> * g_writer_user;
dds::sub::DataReader<ChatMessage> * g_reader_msg;
dds::pub::DataWriter<ChatMessage> * g_writer_msg;
ChatUser g_current_user;
bool g_debug_enabled = false;
//////

/* Listener for ChatUser Reader */
class ChatUserListener : public dds::sub::NoOpDataReaderListener<ChatUser> {
public:
	void on_data_available(dds::sub::DataReader<ChatUser>& reader) override {
		auto samples = reader.read();
		for (const auto& sample : samples) {
			// New instance
			if (sample.info().valid() &&
				sample.info().state().view_state() == dds::sub::status::ViewState::new_view()) {
				
				// exclude current user info
				if (sample.info().publication_handle() == g_writer_user->instance_handle()) {
					continue;
				}

				//Time filtering : only accept samples were created after me.
				auto ns = std::chrono::nanoseconds(sample.info().source_timestamp().to_nanosecs());
				std::chrono::system_clock::time_point src_time(
					std::chrono::duration_cast<std::chrono::system_clock::duration>(ns)
				);
				if (src_time >= g_reader_creation_time_ChatUser)
				{
					std::string pid_str("None");
					std::string ip_str("None");

					try {
						auto participant_data = rti::sub::matched_publication_participant_data(reader, sample.info().publication_handle());
					
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
						print_debug("# Discovered [", sample.data().user_id(), "] running chat app in IP [", ip_str,
							"] with Process ID [", pid_str, "].");
					}
					catch (...) {
						continue;
					}					
				}
			}

			// if Instance disposed or unregistered
			if (!sample.info().valid()) {
				auto istate = sample.info().state().instance_state();
				ChatUser key_holder;
				reader.key_value(key_holder, sample.info().instance_handle());
				if (istate == dds::sub::status::InstanceState::not_alive_disposed()) {
					print_debug("# Dropped [", key_holder.user_id(), "].");
				}
				else if (istate == dds::sub::status::InstanceState::not_alive_no_writers()) { //unregistered
					print_debug("# Dropped [", key_holder.user_id(), "].");
				}

				//delete the sample from queue
				auto handle = sample.info().instance_handle();
				auto instance_samples = reader.select().instance(handle).take();
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

	int32_t time_converted = now_tm.tm_hour * 10000000
		+ now_tm.tm_min * 100000
		+ now_tm.tm_sec * 1000
		+ static_cast<int32_t>(ms.count());

	/* latest timestamp has a higher strength */
	uint32_t strength = map_u32_to_1e6(time_converted);
	return strength;
}

/* Command processor in a chatApp prompt session */
int processCommand(const std::string& input, dds::sub::DataReader<ChatUser> reader_user) {
	std::stringstream ss(input);
	std::string cmd;
	ss >> cmd;

	if (cmd == "quit") {
		reader_user.close();

		dds::core::InstanceHandle handle = g_writer_user->lookup_instance(g_current_user);
		g_writer_user->dispose_instance(handle);
		g_writer_user->unregister_instance(handle);

		return -1;
	}
	else if (cmd == "list") {
		// Logic for list goes here
		ChatUser_ShowActiveUsers(reader_user);
	}
	else if (cmd == "send") {
		std::string target, message;
		ss >> target;

		ss >> std::quoted(message);

		if (target.empty() || message.empty()) {
			std::cout << "Usage: send <target> \"message\"" << std::endl;
		}
		else {
			// Send a message to the Writer_ChatMessage
			ChatMessage_SendMessage(g_current_user, target, message, g_writer_msg);
		}
	}
	else if (!cmd.empty()) {
		std::cout << "Unknown command: " << cmd << std::endl;
	}

	return 0;
}

/* Main Function */
int main(int argc, char* argv[]) {
	unsigned int domain_id = 0;

	//rti::config::Logger::instance().verbosity(rti::config::Verbosity::SILENT);

	///* Parsing Startup Arguments */
	std::map<std::string, std::string> args;
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg[0] == '-') {
			if (i + 1 < argc) {
				args[arg] = argv[++i];
			}
			else if (arg[1] == 'd') {
				args[arg] = "debug"; //dummy value
			}
			else { continue; }
		}
	}

	// Validation of arguments
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
		g_debug_enabled = true;
	}

	///* DDS initialization */
	dds::domain::DomainParticipant participant(domain_id);
	dds::topic::Topic<ChatUser> topic_user(participant, "ChatUserTopic");
	dds::topic::Topic<ChatMessage> topic_message(participant, "ChatMessageTopic");
	dds::core::QosProvider qos_provider = dds::core::QosProvider::Default();

	dds::pub::Publisher publisher(participant);
	dds::sub::Subscriber subscriber(participant);	
	
	///* Writer-ChatUser */
	auto writer_user_qos = qos_provider.extensions().datawriter_qos_w_topic_name("ChatApp_Library::ChatApp_Profile", "ChatUser");
	uint32_t strength = make_strength_from_now(); //assign a strength value based on time_now
	writer_user_qos << dds::core::policy::OwnershipStrength(strength);
	dds::pub::DataWriter<ChatUser> writer_user(publisher, topic_user, writer_user_qos);
	// Thread for Writer-ChatUser
	ChatUser user_info(args["-u"], args["-g"], args["-f"], args["-l"]);
	g_current_user = user_info;
	std::thread t_user_w(ChatUser_WriterThread, writer_user, user_info);
	t_user_w.detach();
	g_writer_user = &writer_user;

	///* Reader-ChatUser */
	auto reader_user_qos = qos_provider.extensions().datareader_qos_w_topic_name("ChatApp_Library::ChatApp_Profile", "ChatUser");
	dds::sub::DataReader<ChatUser> reader_user(subscriber, topic_user, reader_user_qos);
	auto readerListener = std::make_shared<ChatUserListener>();
	reader_user.set_listener(readerListener, dds::core::status::StatusMask::all());
	g_reader_creation_time_ChatUser = std::chrono::system_clock::now();
	
	///* Reader-ChatMessage */
	auto reader_msg_qos = qos_provider.extensions().datareader_qos_w_topic_name("ChatApp_Library::ChatApp_Profile", "ChatMessage");		
	// ContentFilteredTopic
	std::string filter_expr = "(msg_to = %0 OR msg_to = %1) AND msg_from <> %2";
	std::vector<std::string> filter_params = {
		"'" + user_info.user_id() + "'",
		"'" + user_info.user_group() + "'",
		"'" + user_info.user_id() + "'"
	};
	dds::topic::ContentFilteredTopic<ChatMessage> filtered_topic(
		topic_message,
		"FilteredChatMessage",
		dds::topic::Filter(filter_expr, filter_params)
	);
	dds::sub::DataReader<ChatMessage> reader_msg(subscriber, filtered_topic, reader_msg_qos);
	// Thread for Reader-ChatMessage
	std::thread t_msg_r(ChatMessage_ReaderThread, reader_msg);
	t_msg_r.detach();
	g_reader_msg = &reader_msg;

	///* Writer-ChatMessage */
	auto writer_msg_qos = qos_provider.extensions().datawriter_qos_w_topic_name("ChatApp_Library::ChatApp_Profile", "ChatMessage");
	writer_msg_qos << dds::core::policy::OwnershipStrength(strength);
	dds::pub::DataWriter<ChatMessage> writer_msg(publisher, topic_message, writer_msg_qos);	
	g_writer_msg = &writer_msg; // make a global reference	 
	
	// --- Main Interactive Loop ---
	std::string line;
	int return_code = 0;
	while (return_code == 0) {
		std::cout << "chatApp>";
		if (!std::getline(std::cin, line)) break; // Handle Ctrl+C or EOF

		if (!line.empty()) {
			return_code = processCommand(line, reader_user);
		}
	}

	return 0;
}
