/* ChatApp Message functions
*/
#include <iostream>
#include <chrono>
#include <string>
#include <sstream>

#include <dds/pub/ddspub.hpp>

#include "Application.hpp"

bool static g_message_found = false; // if ReadCondition captured a message

/* ChatMessage Reader - filtering by msg_from and implemented by WaitSet */
void ChatMessage_ReaderThread(dds::sub::DataReader<ChatMessage> reader) {	
	// Read Condition
	dds::sub::cond::ReadCondition read_condition(
		reader,
		dds::sub::status::DataState::new_data(),
		[&reader]() {
			auto samples = reader.take();
			for (const auto& sample : samples) {
				if (sample.info().valid()) {					
					//if (g_writer_msg!=nullptr && (sample.info().publication_handle() != g_writer_msg->instance_handle())) {
						std::cout << std::endl;
						std::cout << "* " << sample.data().msg_from() << ">" << sample.data().msg_content() << std::endl;

						g_message_found = true;
						//reader.extensions().acknowledge_sample(sample.info());
					//}
				}
			}
			//samples.return_loan();
		}
	);	
	
	// WaitSet
	dds::core::cond::WaitSet waitset;
	waitset += read_condition;

	while (true) {
		waitset.dispatch(dds::core::Duration(1));
		if (g_message_found) {
			std::cout << chatapp_prompt;
			g_message_found = false;
		}
	}
}

/* ChatMessage Writer - create necessary field information */
void ChatMessage_SendMessage(ChatUser user_info, std::string receiver, std::string contents, dds::pub::DataWriter<ChatMessage> * p_writer)
{
	/* IDL definition
		string<MAX_MSG_USER_LEN> msg_from
		string<MAX_MSG_TXT_LEN> msg_content		
		string<MAX_MSG_USER_LEN> msg_to
		int64 msg_time
	*/
	//msg_time
	using namespace std::chrono;
	auto now = system_clock::now();
	int64_t msg_time = std::chrono::duration_cast<std::chrono::milliseconds>(
		now.time_since_epoch()
		).count();

	//msg_content
	std::string msg_content = contents;
	//msg_from
	std::string msg_from = user_info.user_id();
	//msg_to
	std::string msg_to = receiver;

	//populate ChatMessage
	ChatMessage sample = ChatMessage(msg_from, msg_content, msg_to, msg_time);

	//send message
	p_writer->write(sample);

	//Auto send user info
	g_writer_user->write(user_info);
}

