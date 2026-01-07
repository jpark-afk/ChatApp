#ifndef APPLICATION_H
#define APPLICATION_H
#include <dds/dds.hpp>
#include "ChatApp.hpp"

/* ChatUser functions */
extern void ChatUser_WriterThread(dds::pub::DataWriter<ChatUser>, ChatUser);
extern void ChatUser_ShowActiveUsers(dds::sub::DataReader<ChatUser>);

/* ChatMessage functions */
extern void ChatMessage_ReaderThread(dds::sub::DataReader<ChatMessage>);
extern int32_t ChatMessage_SendMessage(ChatUser, std::string, std::string, dds::pub::DataWriter<ChatMessage> *);

/* Util functions */
extern std::ostream& chatapp_prompt(std::ostream&);
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
