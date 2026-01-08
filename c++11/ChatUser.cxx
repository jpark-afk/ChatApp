/* ChatAppUser functions 
*/
#include <iostream>
#include <chrono>

#include <dds/pub/ddspub.hpp>

#include "Application.hpp"

/* Simple Writer of ChatUser */
void ChatUser_WriterThread(dds::pub::DataWriter<ChatUser> writer, ChatUser user_info) {
	// Wait until connection	
	do {
		dds::core::status::PublicationMatchedStatus status = writer.publication_matched_status();
		if (status.current_count() > 0) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	} while (true);	

	writer.write(user_info);

	//Auto send message
	while (g_writer_msg == NULL) {}
	ChatMessage_SendMessage(user_info, "all", "hi", g_writer_msg);
}

/* list all active users */
void ChatUser_ShowActiveUsers(dds::sub::DataReader<ChatUser> reader)
{
	auto samples = reader.read();

	for (const auto& sample : samples) {
		// SampleInfo is valid, and the instance is alive
		if (sample.info().valid() &&
			sample.info().state().instance_state() == dds::sub::status::InstanceState::alive()) {
			// print all members
			std::cout << "# " << sample.data().user_id() << "  "
				<< sample.data().user_group() << "  "
				<< sample.data().user_firstName() << "  "
				<< sample.data().user_lastName() << "  "
				<< std::endl;
		}
	}
}

