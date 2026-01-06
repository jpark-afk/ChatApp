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

#endif
