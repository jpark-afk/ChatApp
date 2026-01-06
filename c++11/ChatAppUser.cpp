/* ChatAppUser functions 
*/
#include <iostream>
#include <chrono>

#include <dds/pub/ddspub.hpp>

#include "Application.hpp"

void ChatAppUser_WriterThread(dds::pub::DataWriter<ChatUser> writer, ChatUser user_info) {
	// Wait until connection	
	do {
		dds::core::status::PublicationMatchedStatus status = writer.publication_matched_status();
		if (status.current_count() > 0) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	} while (true);	

	writer.write(user_info);

	while (true) {		
		std::cout << "Waiting in the User Writer Thread" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}