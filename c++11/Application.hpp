#ifndef APPLICATION_H
#define APPLICATION_H
#include <dds/dds.hpp>
#include "ChatApp.hpp"

/* globals */
extern dds::pub::DataWriter<ChatUser> * g_writer_user;
extern dds::pub::DataWriter<ChatMessage> * g_writer_msg;

/* ChatUser functions */
extern void ChatUser_WriterThread(dds::pub::DataWriter<ChatUser>, ChatUser);
extern void ChatUser_ShowActiveUsers(dds::sub::DataReader<ChatUser>);

/* ChatMessage functions */
extern void ChatMessage_ReaderThread(dds::sub::DataReader<ChatMessage>);
extern void ChatMessage_SendMessage(ChatUser, std::string, std::string, dds::pub::DataWriter<ChatMessage> *);

/* Util functions */
inline std::ostream& chatapp_prompt(std::ostream& os) {
	return os << std::endl << "chatApp>";
}
// print debug
extern bool g_debug_enabled;
inline void print_debug() {
	if (g_debug_enabled) {
		std::cout << chatapp_prompt;
	}
}
// print template function
template <typename T, typename... Args>
void print_debug(T first, Args... args) {
	if (g_debug_enabled) {
		std::cout << first;
		print_debug(args...); // recursive calls here
	}
}
#endif
