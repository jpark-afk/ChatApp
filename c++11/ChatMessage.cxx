/* ChatApp Message functions
*/
#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <openssl/sha.h>

#include <dds/pub/ddspub.hpp>

#include "Application.hpp"

extern std::ostream& chatapp_prompt(std::ostream&);

void ChatMessage_ReaderThread(dds::sub::DataReader<ChatMessage> reader) {
	// Read Condition
	dds::sub::cond::ReadCondition read_condition(
		reader,
		dds::sub::status::DataState::new_data(),
		[&reader]() {
		auto samples = reader.take();
		for (const auto& sample : samples) {
			if (sample.info().valid()) {
				std::cout << std::endl;
				std::cout << "* " << sample.data().msg_from() << ">" << sample.data().msg_content() << chatapp_prompt;
			}
		}
	}
	);

	// Wait until connection	
	do {
		dds::core::status::SubscriptionMatchedStatus status = reader.subscription_matched_status();
		if (status.current_count() > 0) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	} while (true);

	// WaitSet
	dds::core::cond::WaitSet waitset;
	waitset += read_condition;

	while (true) {
		waitset.dispatch(dds::core::Duration(1));
	}
}

int32_t ChatMessage_SendMessage(ChatUser user_info, std::string receiver, std::string contents, dds::pub::DataWriter<ChatMessage> * p_writer)
{
	/* IDL definition
		string<MAX_MSG_ID_LEN> msg_id
		string<MAX_MSG_TXT_LEN> msg_content
		string<MAX_MSG_USER_LEN> msg_from
		string<MAX_MSG_USER_LEN> msg_to
		int64 msg_time
	*/
	//msg_time
	using namespace std::chrono;
	auto now = system_clock::now();
	int64_t msg_time = std::chrono::duration_cast<std::chrono::milliseconds>(
		now.time_since_epoch()
		).count();

	//msg_id
	std::ostringstream oss;
	oss << msg_time;
	std::string input = oss.str();
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
	std::ostringstream hash_str;
	for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
		hash_str << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	std::string msg_id = hash_str.str();

	//msg_content
	std::string msg_content = contents;
	//msg_from
	std::string msg_from = user_info.user_id();
	//msg_to
	std::string msg_to = receiver;

	//populate ChatMessage
	ChatMessage sample = ChatMessage(msg_id, msg_content, msg_from, msg_to, msg_time);

	//send message
	p_writer->write(sample);
	
	return 0;
}

