#ifndef APPLICATION_H
#define APPLICATION_H
#include <dds/dds.hpp>
#include "ChatApp.hpp"

extern void ChatAppUser_WriterThread(dds::pub::DataWriter<ChatUser>, ChatUser);
extern void ChatAppUser_ShowActiveUsers(dds::sub::DataReader<ChatUser>);

#endif
