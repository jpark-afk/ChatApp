

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ChatApp.idl
using RTI Code Generator (rtiddsgen) version 4.3.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>
#include <atomic>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "ChatAppPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "ChatApp.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- ChatUser: 

ChatUser::ChatUser() :
    m_user_id_ ("") ,
    m_user_group_ ("") ,
    m_user_firstName_ ("") ,
    m_user_lastName_ ("")  {

}   

ChatUser::ChatUser (const std::string& user_id_,const std::string& user_group_,const std::string& user_firstName_,const std::string& user_lastName_):
    m_user_id_(user_id_), 
    m_user_group_(user_group_), 
    m_user_firstName_(user_firstName_), 
    m_user_lastName_(user_lastName_) {
}

void ChatUser::swap(ChatUser& other_)  noexcept 
{
    using std::swap;
    swap(m_user_id_, other_.m_user_id_);
    swap(m_user_group_, other_.m_user_group_);
    swap(m_user_firstName_, other_.m_user_firstName_);
    swap(m_user_lastName_, other_.m_user_lastName_);
}  

bool ChatUser::operator == (const ChatUser& other_) const {
    if (m_user_id_ != other_.m_user_id_) {
        return false;
    }
    if (m_user_group_ != other_.m_user_group_) {
        return false;
    }
    if (m_user_firstName_ != other_.m_user_firstName_) {
        return false;
    }
    if (m_user_lastName_ != other_.m_user_lastName_) {
        return false;
    }
    return true;
}

bool ChatUser::operator != (const ChatUser& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const ChatUser& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "user_id: " << sample.user_id ()<<", ";
    o << "user_group: " << sample.user_group ()<<", ";
    o << "user_firstName: " << sample.user_firstName ()<<", ";
    o << "user_lastName: " << sample.user_lastName ();
    o <<"]";
    return o;
}

// ---- ChatMessage: 

ChatMessage::ChatMessage() :
    m_msg_id_ ("") ,
    m_msg_content_ ("") ,
    m_msg_from_ ("") ,
    m_msg_to_user_ ("") ,
    m_msg_to_group_ ("") ,
    m_msg_time_ (0ll)  {

}   

ChatMessage::ChatMessage (const std::string& msg_id_,const std::string& msg_content_,const std::string& msg_from_,const std::string& msg_to_user_,const std::string& msg_to_group_,int64_t msg_time_):
    m_msg_id_(msg_id_), 
    m_msg_content_(msg_content_), 
    m_msg_from_(msg_from_), 
    m_msg_to_user_(msg_to_user_), 
    m_msg_to_group_(msg_to_group_), 
    m_msg_time_(msg_time_) {
}

void ChatMessage::swap(ChatMessage& other_)  noexcept 
{
    using std::swap;
    swap(m_msg_id_, other_.m_msg_id_);
    swap(m_msg_content_, other_.m_msg_content_);
    swap(m_msg_from_, other_.m_msg_from_);
    swap(m_msg_to_user_, other_.m_msg_to_user_);
    swap(m_msg_to_group_, other_.m_msg_to_group_);
    swap(m_msg_time_, other_.m_msg_time_);
}  

bool ChatMessage::operator == (const ChatMessage& other_) const {
    if (m_msg_id_ != other_.m_msg_id_) {
        return false;
    }
    if (m_msg_content_ != other_.m_msg_content_) {
        return false;
    }
    if (m_msg_from_ != other_.m_msg_from_) {
        return false;
    }
    if (m_msg_to_user_ != other_.m_msg_to_user_) {
        return false;
    }
    if (m_msg_to_group_ != other_.m_msg_to_group_) {
        return false;
    }
    if (m_msg_time_ != other_.m_msg_time_) {
        return false;
    }
    return true;
}

bool ChatMessage::operator != (const ChatMessage& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const ChatMessage& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "msg_id: " << sample.msg_id ()<<", ";
    o << "msg_content: " << sample.msg_content ()<<", ";
    o << "msg_from: " << sample.msg_from ()<<", ";
    o << "msg_to_user: " << sample.msg_to_user ()<<", ";
    o << "msg_to_group: " << sample.msg_to_group ()<<", ";
    o << "msg_time: " << sample.msg_time ();
    o <<"]";
    return o;
}

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::ChatUser > {

            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static std::atomic_bool is_initialized {false};

                static DDS_TypeCode ChatUser_g_tc_user_id_string;
                static DDS_TypeCode ChatUser_g_tc_user_group_string;
                static DDS_TypeCode ChatUser_g_tc_user_firstName_string;
                static DDS_TypeCode ChatUser_g_tc_user_lastName_string;

                static DDS_TypeCode_Member ChatUser_g_tc_members[4]=
                {

                    {
                        (char *)"user_id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"user_group",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"user_firstName",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"user_lastName",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ChatUser_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ChatUser", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        ChatUser_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ChatUser*/

                if (is_initialized.load(std::memory_order_acquire)) {
                    return &ChatUser_g_tc;
                }

                ChatUser_g_tc_user_id_string = initialize_string_typecode(((MAX_ID_LEN)));
                ChatUser_g_tc_user_group_string = initialize_string_typecode(((MAX_NAME_LEN)));
                ChatUser_g_tc_user_firstName_string = initialize_string_typecode(((MAX_NAME_LEN)));
                ChatUser_g_tc_user_lastName_string = initialize_string_typecode(((MAX_NAME_LEN)));

                ChatUser_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ChatUser_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_user_id_string;
                ChatUser_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_user_group_string;
                ChatUser_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_user_firstName_string;
                ChatUser_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&ChatUser_g_tc_user_lastName_string;

                /* Initialize the values for member annotations. */
                ChatUser_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatUser_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatUser_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatUser_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatUser_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatUser_g_tc_members[2]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatUser_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatUser_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ChatUser_g_tc._data._sampleAccessInfo = sample_access_info();
                ChatUser_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized.store(true, std::memory_order_release);

                return &ChatUser_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static std::atomic_bool is_initialized {false};

                ::ChatUser *sample;

                static RTIXCdrMemberAccessInfo ChatUser_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ChatUser_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized.load(std::memory_order_acquire)) {
                    return (RTIXCdrSampleAccessInfo*) &ChatUser_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::ChatUser);
                if (sample == NULL) {
                    return NULL;
                }

                ChatUser_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->user_id() - (char *)sample);

                ChatUser_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->user_group() - (char *)sample);

                ChatUser_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->user_firstName() - (char *)sample);

                ChatUser_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->user_lastName() - (char *)sample);

                ChatUser_g_sampleAccessInfo.memberAccessInfos = 
                ChatUser_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::ChatUser);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ChatUser_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ChatUser_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ChatUser_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ChatUser_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::ChatUser >;

                ChatUser_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized.store(true, std::memory_order_release);
                return (RTIXCdrSampleAccessInfo*) &ChatUser_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ChatUser_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ChatUser_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::ChatUser >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::ChatUser >::get())));
        }

        template<>
        struct native_type_code< ::ChatMessage > {

            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static std::atomic_bool is_initialized {false};

                static DDS_TypeCode ChatMessage_g_tc_msg_id_string;
                static DDS_TypeCode ChatMessage_g_tc_msg_content_string;
                static DDS_TypeCode ChatMessage_g_tc_msg_from_string;
                static DDS_TypeCode ChatMessage_g_tc_msg_to_user_string;
                static DDS_TypeCode ChatMessage_g_tc_msg_to_group_string;

                static DDS_TypeCode_Member ChatMessage_g_tc_members[6]=
                {

                    {
                        (char *)"msg_id",/* Member name */
                        {
                            186499852,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"msg_content",/* Member name */
                        {
                            79613173,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"msg_from",/* Member name */
                        {
                            47368626,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"msg_to_user",/* Member name */
                        {
                            7632562,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"msg_to_group",/* Member name */
                        {
                            150755201,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"msg_time",/* Member name */
                        {
                            76134714,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ChatMessage_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ChatMessage", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        ChatMessage_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ChatMessage*/

                if (is_initialized.load(std::memory_order_acquire)) {
                    return &ChatMessage_g_tc;
                }

                ChatMessage_g_tc_msg_id_string = initialize_string_typecode(((MAX_MSG_ID_LEN)));
                ChatMessage_g_tc_msg_content_string = initialize_string_typecode(((MAX_MSG_TXT_LEN)));
                ChatMessage_g_tc_msg_from_string = initialize_string_typecode(((MAX_MSG_USER_LEN)));
                ChatMessage_g_tc_msg_to_user_string = initialize_string_typecode(((MAX_MSG_USER_LEN)));
                ChatMessage_g_tc_msg_to_group_string = initialize_string_typecode(((MAX_MSG_USER_LEN)));

                ChatMessage_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ChatMessage_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_msg_id_string;
                ChatMessage_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_msg_content_string;
                ChatMessage_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_msg_from_string;
                ChatMessage_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_msg_to_user_string;
                ChatMessage_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&ChatMessage_g_tc_msg_to_group_string;
                ChatMessage_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;

                /* Initialize the values for member annotations. */
                ChatMessage_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatMessage_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatMessage_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[2]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatMessage_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatMessage_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ChatMessage_g_tc_members[4]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                ChatMessage_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                ChatMessage_g_tc_members[5]._annotations._defaultValue._u.long_long_value = 0ll;
                ChatMessage_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                ChatMessage_g_tc_members[5]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                ChatMessage_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                ChatMessage_g_tc_members[5]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;

                ChatMessage_g_tc._data._sampleAccessInfo = sample_access_info();
                ChatMessage_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized.store(true, std::memory_order_release);

                return &ChatMessage_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static std::atomic_bool is_initialized {false};

                ::ChatMessage *sample;

                static RTIXCdrMemberAccessInfo ChatMessage_g_memberAccessInfos[6] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ChatMessage_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized.load(std::memory_order_acquire)) {
                    return (RTIXCdrSampleAccessInfo*) &ChatMessage_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::ChatMessage);
                if (sample == NULL) {
                    return NULL;
                }

                ChatMessage_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg_id() - (char *)sample);

                ChatMessage_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg_content() - (char *)sample);

                ChatMessage_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg_from() - (char *)sample);

                ChatMessage_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg_to_user() - (char *)sample);

                ChatMessage_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg_to_group() - (char *)sample);

                ChatMessage_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg_time() - (char *)sample);

                ChatMessage_g_sampleAccessInfo.memberAccessInfos = 
                ChatMessage_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::ChatMessage);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ChatMessage_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ChatMessage_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ChatMessage_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ChatMessage_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::ChatMessage >;

                ChatMessage_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized.store(true, std::memory_order_release);
                return (RTIXCdrSampleAccessInfo*) &ChatMessage_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ChatMessage_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ChatMessage_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::ChatMessage >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::ChatMessage >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::ChatUser >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::ChatUserPlugin_new,
                ::ChatUserPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::ChatUser >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::ChatUser& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ChatUserPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ChatUserPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::ChatUser >::from_cdr_buffer(::ChatUser& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ChatUserPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::ChatUser from cdr buffer");
        }

        void topic_type_support< ::ChatUser >::reset_sample(::ChatUser& sample) 
        {
            sample.user_id("");
            sample.user_group("");
            sample.user_firstName("");
            sample.user_lastName("");
        }

        void topic_type_support< ::ChatUser >::allocate_sample(::ChatUser& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.user_id(),  -1, (MAX_ID_LEN));
            ::rti::topic::allocate_sample(sample.user_group(),  -1, (MAX_NAME_LEN));
            ::rti::topic::allocate_sample(sample.user_firstName(),  -1, (MAX_NAME_LEN));
            ::rti::topic::allocate_sample(sample.user_lastName(),  -1, (MAX_NAME_LEN));
        }
        void topic_type_support< ::ChatMessage >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::ChatMessagePlugin_new,
                ::ChatMessagePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::ChatMessage >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::ChatMessage& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ChatMessagePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ChatMessagePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::ChatMessage >::from_cdr_buffer(::ChatMessage& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ChatMessagePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::ChatMessage from cdr buffer");
        }

        void topic_type_support< ::ChatMessage >::reset_sample(::ChatMessage& sample) 
        {
            sample.msg_id("");
            sample.msg_content("");
            sample.msg_from("");
            sample.msg_to_user("");
            sample.msg_to_group("");
            sample.msg_time(0ll);
        }

        void topic_type_support< ::ChatMessage >::allocate_sample(::ChatMessage& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.msg_id(),  -1, (MAX_MSG_ID_LEN));
            ::rti::topic::allocate_sample(sample.msg_content(),  -1, (MAX_MSG_TXT_LEN));
            ::rti::topic::allocate_sample(sample.msg_from(),  -1, (MAX_MSG_USER_LEN));
            ::rti::topic::allocate_sample(sample.msg_to_user(),  -1, (MAX_MSG_USER_LEN));
            ::rti::topic::allocate_sample(sample.msg_to_group(),  -1, (MAX_MSG_USER_LEN));
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
