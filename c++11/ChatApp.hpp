

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ChatApp.idl
using RTI Code Generator (rtiddsgen) version 4.3.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ChatApp_1451509760_hpp
#define ChatApp_1451509760_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/External.hpp"
#include "rti/core/LongDouble.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/core/array.hpp"
#include "rti/topic/TopicTraits.hpp"

#include "omg/types/string_view.hpp"

#include "rti/core/BoundedSequence.hpp"
#include "dds/core/Optional.hpp"

#ifndef NDDS_STANDALONE_TYPE
#include "cdr/cdr_typeCode.h"
#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

static const uint32_t MAX_ID_LEN = 100UL;

static const uint32_t MAX_NAME_LEN = 100UL;

static const uint32_t MAX_MSG_ID_LEN = 64UL;

static const uint32_t MAX_MSG_TXT_LEN = 1000UL;

static const uint32_t MAX_MSG_USER_LEN = 100UL;

class NDDSUSERDllExport ChatUser {
  public:

    ChatUser();

    ChatUser(const std::string& user_id_,const std::string& user_group_,const std::string& user_firstName_,const std::string& user_lastName_);

    std::string& user_id() noexcept {
        return m_user_id_;
    }

    const std::string& user_id() const noexcept {
        return m_user_id_;
    }

    void user_id(const std::string& value) {

        m_user_id_ = value;
    }

    void user_id(std::string&& value) {
        m_user_id_ = std::move(value);
    }
    std::string& user_group() noexcept {
        return m_user_group_;
    }

    const std::string& user_group() const noexcept {
        return m_user_group_;
    }

    void user_group(const std::string& value) {

        m_user_group_ = value;
    }

    void user_group(std::string&& value) {
        m_user_group_ = std::move(value);
    }
    std::string& user_firstName() noexcept {
        return m_user_firstName_;
    }

    const std::string& user_firstName() const noexcept {
        return m_user_firstName_;
    }

    void user_firstName(const std::string& value) {

        m_user_firstName_ = value;
    }

    void user_firstName(std::string&& value) {
        m_user_firstName_ = std::move(value);
    }
    std::string& user_lastName() noexcept {
        return m_user_lastName_;
    }

    const std::string& user_lastName() const noexcept {
        return m_user_lastName_;
    }

    void user_lastName(const std::string& value) {

        m_user_lastName_ = value;
    }

    void user_lastName(std::string&& value) {
        m_user_lastName_ = std::move(value);
    }
    bool operator == (const ChatUser& other_) const;
    bool operator != (const ChatUser& other_) const;

    void swap(ChatUser& other_) noexcept ;

  private:

    std::string m_user_id_;
    std::string m_user_group_;
    std::string m_user_firstName_;
    std::string m_user_lastName_;

};

inline void swap(ChatUser& a, ChatUser& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ChatUser& sample);

class NDDSUSERDllExport ChatMessage {
  public:

    ChatMessage();

    ChatMessage(const std::string& msg_id_,const std::string& msg_content_,const std::string& msg_from_,const std::string& msg_to_,int64_t msg_time_);

    std::string& msg_id() noexcept {
        return m_msg_id_;
    }

    const std::string& msg_id() const noexcept {
        return m_msg_id_;
    }

    void msg_id(const std::string& value) {

        m_msg_id_ = value;
    }

    void msg_id(std::string&& value) {
        m_msg_id_ = std::move(value);
    }
    std::string& msg_content() noexcept {
        return m_msg_content_;
    }

    const std::string& msg_content() const noexcept {
        return m_msg_content_;
    }

    void msg_content(const std::string& value) {

        m_msg_content_ = value;
    }

    void msg_content(std::string&& value) {
        m_msg_content_ = std::move(value);
    }
    std::string& msg_from() noexcept {
        return m_msg_from_;
    }

    const std::string& msg_from() const noexcept {
        return m_msg_from_;
    }

    void msg_from(const std::string& value) {

        m_msg_from_ = value;
    }

    void msg_from(std::string&& value) {
        m_msg_from_ = std::move(value);
    }
    std::string& msg_to() noexcept {
        return m_msg_to_;
    }

    const std::string& msg_to() const noexcept {
        return m_msg_to_;
    }

    void msg_to(const std::string& value) {

        m_msg_to_ = value;
    }

    void msg_to(std::string&& value) {
        m_msg_to_ = std::move(value);
    }
    int64_t& msg_time() noexcept {
        return m_msg_time_;
    }

    const int64_t& msg_time() const noexcept {
        return m_msg_time_;
    }

    void msg_time(int64_t value) {

        m_msg_time_ = value;
    }

    bool operator == (const ChatMessage& other_) const;
    bool operator != (const ChatMessage& other_) const;

    void swap(ChatMessage& other_) noexcept ;

  private:

    std::string m_msg_id_;
    std::string m_msg_content_;
    std::string m_msg_from_;
    std::string m_msg_to_;
    int64_t m_msg_time_;

};

inline void swap(ChatMessage& a, ChatMessage& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ChatMessage& sample);

#ifdef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace topic {
    }
}
#else

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ::ChatUser > {
            NDDSUSERDllExport static std::string value() {
                return "ChatUser";
            }
        };

        template<>
        struct is_topic_type< ::ChatUser > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::ChatUser > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::ChatUser& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::ChatUser& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::ChatUser& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::ChatUser& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::ChatMessage > {
            NDDSUSERDllExport static std::string value() {
                return "ChatMessage";
            }
        };

        template<>
        struct is_topic_type< ::ChatMessage > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::ChatMessage > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::ChatMessage& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::ChatMessage& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::ChatMessage& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::ChatMessage& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {

        template<>
        struct dynamic_type< ::ChatUser > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::ChatUser > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::ChatMessage > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::ChatMessage > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // ChatApp_1451509760_hpp

