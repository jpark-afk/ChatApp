

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ChatApp.idl
using RTI Code Generator (rtiddsgen) version 4.3.1.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <string.h>

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "dds_c/dds_c_typecode_impl.h"

#include "rti/topic/cdr/Serialization.hpp"

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "ChatAppPlugin.hpp"

/* ----------------------------------------------------------------------------
*  Type ChatUser
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

ChatUser *
ChatUserPluginSupport_create_data(void)
{
    try {
        ChatUser *sample = new ChatUser();
        ::rti::topic::allocate_sample(*sample);
        return sample;
    } catch (...) {
        return NULL;
    }
}

void 
ChatUserPluginSupport_destroy_data(
    ChatUser *sample) 
{
    delete sample;
}

RTIBool 
ChatUserPluginSupport_copy_data(
    ChatUser *dst,
    const ChatUser *src)
{
    try {
        *dst = *src;
    } catch (...) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

ChatUser *
ChatUserPluginSupport_create_key(void)
{
    return ChatUserPluginSupport_create_data();
}

void 
ChatUserPluginSupport_destroy_key(
    ChatUserKeyHolder *key) 
{
    ChatUserPluginSupport_destroy_data(key);
}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
ChatUserPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    try {
        struct RTIXCdrInterpreterPrograms *programs = NULL;
        struct PRESTypePluginDefaultParticipantData *pd = NULL;
        struct RTIXCdrInterpreterProgramsGenProperty programProperty =
        RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
        if (registration_data) {} /* To avoid warnings */
        if (participant_info) {} /* To avoid warnings */
        if (top_level_registration) {} /* To avoid warnings */
        if (container_plugin_context) {} /* To avoid warnings */
        if (type_code) {} /* To avoid warnings */

        if (!RTIXCdrXTypesComplianceMask_verifyGeneratedXTypesMask(0x0000068C)) {
            return NULL;
        }

        pd = (struct PRESTypePluginDefaultParticipantData *)
        PRESTypePluginDefaultParticipantData_new(participant_info);

        programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
        programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
        programProperty.resolveAlias = RTI_XCDR_TRUE;
        programProperty.inlineStruct = RTI_XCDR_TRUE;
        programProperty.optimizeEnum = RTI_XCDR_TRUE;
        programProperty.unboundedSize = RTIXCdrLong_MAX;

        programProperty.externalReferenceSize = 
        (RTIXCdrUnsignedShort) sizeof(::dds::core::external<char>);
        programProperty.getExternalRefPointerFcn = 
        ::rti::topic::interpreter::get_external_value_pointer;

        programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
            DDS_TypeCodeFactory_get_instance(),
            (DDS_TypeCode *) (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ChatUser >::get().native()
            ,
            &programProperty,
            RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);

        if (programs == NULL) {
            PRESTypePluginDefaultParticipantData_delete(
                (PRESTypePluginParticipantData)pd);
            return NULL;
        }

        pd->programs = programs;
        return (PRESTypePluginParticipantData)pd;
    } catch (...) {
        return NULL;
    }
}

void 
ChatUserPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{
    if (participant_data != NULL) {
        struct PRESTypePluginDefaultParticipantData *pd = 
        (struct PRESTypePluginDefaultParticipantData *)participant_data;

        if (pd->programs != NULL) {
            DDS_TypeCodeFactory_remove_programs_from_global_list(
                DDS_TypeCodeFactory_get_instance(),
                pd->programs);
            pd->programs = NULL;
        }
        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }
}

PRESTypePluginEndpointData
ChatUserPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    try {
        PRESTypePluginEndpointData epd = NULL;
        unsigned int serializedSampleMaxSize = 0;

        unsigned int serializedKeyMaxSize = 0;
        unsigned int serializedKeyMaxSizeV2 = 0;

        if (top_level_registration) {} /* To avoid warnings */
        if (containerPluginContext) {} /* To avoid warnings */

        if (participant_data == NULL) {
            return NULL;
        } 

        epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ChatUserPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ChatUserPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::ChatUserPluginSupport_create_key ,                (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::ChatUserPluginSupport_destroy_key);

        if (epd == NULL) {
            return NULL;
        } 

        serializedKeyMaxSize =  ::ChatUserPlugin_get_serialized_key_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
        serializedKeyMaxSizeV2 = ChatUserPlugin_get_serialized_key_max_size_for_keyhash(
            epd,
            RTI_CDR_ENCAPSULATION_ID_CDR2_BE,
            0);

        if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
            epd,
            endpoint_info,
            serializedKeyMaxSize,
            serializedKeyMaxSizeV2))  
        {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            serializedSampleMaxSize = ::ChatUserPlugin_get_serialized_sample_max_size(
                epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
            PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

            if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::ChatUserPlugin_get_serialized_sample_max_size, epd,
                (PRESTypePluginGetSerializedSampleSizeFunction)
                PRESTypePlugin_interpretedGetSerializedSampleSize,
                epd) == RTI_FALSE) {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }
        }

        return epd;
    } catch (...) {
        return NULL;
    }
}

void 
ChatUserPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
ChatUserPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser *sample,
    void *handle)
{
    try {
        ::rti::topic::reset_sample(*sample);
    } catch(const std::exception& ex) {
        RTICdrLog_logWithFunctionName(
            RTI_LOG_BIT_EXCEPTION,
            "ChatUserPlugin_return_sample",
            &RTI_LOG_ANY_FAILURE_ss,
            "exception: ",
            ex.what());
    }

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
ChatUserPlugin_copy_sample(
    PRESTypePluginEndpointData,
    ChatUser *dst,
    const ChatUser *src)
{
    return ::ChatUserPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
ChatUserPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool
ChatUserPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ChatUser *sample,
    ::dds::core::policy::DataRepresentationId representation)
{
    using namespace ::dds::core::policy;

    try{
        RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
        struct RTICdrStream cdrStream;
        struct PRESTypePluginDefaultEndpointData epd;
        RTIBool result;
        struct PRESTypePluginDefaultParticipantData pd;
        struct RTIXCdrTypePluginProgramContext defaultProgramContext =
        RTIXCdrTypePluginProgramContext_INTIALIZER;
        struct PRESTypePlugin plugin = PRES_TYPEPLUGIN_DEFAULT;

        if (length == NULL) {
            return RTI_FALSE;
        }

        RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
        epd.programContext = defaultProgramContext;
        epd._participantData = &pd;
        epd.typePlugin = &plugin;
        epd.programContext.endpointPluginData = &epd;
        try {
            plugin.typeCode = (struct RTICdrTypeCode *)
            (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ChatUser >::get().native()
            ;
        } catch (...) {
            return RTI_FALSE;
        }
        pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
        ChatUser, 
        true, true, true>();

        encapsulationId = DDS_TypeCode_get_native_encapsulation(
            (DDS_TypeCode *) plugin.typeCode,
            representation);

        if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
            return RTI_FALSE;
        }

        epd._maxSizeSerializedSample =
        ChatUserPlugin_get_serialized_sample_max_size(
            (PRESTypePluginEndpointData)&epd, 
            RTI_TRUE, 
            encapsulationId,
            0);

        if (buffer == NULL) {
            *length = 
            PRESTypePlugin_interpretedGetSerializedSampleSize(
                (PRESTypePluginEndpointData)&epd,
                RTI_TRUE,
                encapsulationId,
                0,
                sample);

            if (*length == 0) {
                return RTI_FALSE;
            }

            return RTI_TRUE;
        }    

        RTICdrStream_init(&cdrStream);
        RTICdrStream_set(&cdrStream, buffer, *length);

        result = PRESTypePlugin_interpretedSerialize(
            (PRESTypePluginEndpointData)&epd, 
            sample, 
            &cdrStream, 
            RTI_TRUE, 
            encapsulationId,
            RTI_TRUE, 
            NULL);  

        *length = (unsigned int) RTICdrStream_getCurrentPositionOffset(&cdrStream);
        return result;
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool
ChatUserPlugin_deserialize_from_cdr_buffer(
    ChatUser *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream cdrStream;
    struct PRESTypePluginDefaultParticipantData pd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePlugin plugin;
    struct PRESTypePluginDefaultEndpointData epd;

    RTICdrStream_init(&cdrStream);
    /*
    * The buffer is constant because this is a deserialization function
    * (the buffer is an input parameter, not an output parameter).
    * However, the buffer member in the stream is a (char *) so coverity
    * complains in case something else modifies the buffer's contents later.
    *
    * We don't currently have a stream type with a constant buffer.
    * Therefore, we suppress the warning after making sure that this function
    * doesn't modify the contents of the stream's buffer.
    */
    /* coverity[cert_exp40_c_violation : FALSE] */
    RTICdrStream_set(&cdrStream, (char *) buffer, length);

    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    try {
        plugin.typeCode = (struct RTICdrTypeCode *)
        (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ChatUser >::get().native()
        ;
    } catch (...) {
        return RTI_FALSE;
    }
    pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
    ChatUser, 
    true, true, true>();

    RTIXCdrSampleAssignabilityProperty_setFromGlobalComplianceMask(
        &epd._assignabilityProperty);

    ::rti::topic::reset_sample(*sample);
    return PRESTypePlugin_interpretedDeserialize( 
        (PRESTypePluginEndpointData)&epd,
        sample,
        &cdrStream,
        RTI_TRUE, 
        RTI_TRUE, 
        NULL);
}

unsigned int 
ChatUserPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return 0;
    }
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
ChatUserPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

RTIBool ChatUserPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        if (drop_sample) {} /* To avoid warnings */
        cdrStream->_xTypesState.unassignable = RTI_FALSE;
        result= PRESTypePlugin_interpretedDeserializeKey( 
            endpoint_data, (sample != NULL)?*sample:NULL, cdrStream,
            deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
        if (result) {
            if (cdrStream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }
        return result;    
    } catch (...) {
        return RTI_FALSE;
    }     
}

unsigned int
ChatUserPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return RTI_FALSE;
    }    
}

unsigned int
ChatUserPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        &overflow,
        encapsulation_id,
        current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
ChatUserPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatUserKeyHolder *dst, 
    const ChatUser *src)
{
    try {
        if (endpoint_data) {} /* To avoid warnings */   

        dst->user_id() = src->user_id();
        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }    
}

RTIBool 
ChatUserPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ChatUser *dst, const
    ChatUserKeyHolder *src)
{
    try {
        if (endpoint_data) {} /* To avoid warnings */   
        dst->user_id() = src->user_id();
        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }    
}

RTIBool 
ChatUserPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *cdrStream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos)
{
    ChatUser * sample = NULL;
    sample = (ChatUser *)
    PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);
    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (!PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        cdrStream, 
        deserialize_encapsulation, 
        RTI_TRUE,
        endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
    if (!PRESTypePlugin_interpretedInstanceToKeyHash(
        endpoint_data,
        keyhash,
        sample,
        RTICdrStream_getEncapsulationKind(cdrStream))) {
        return RTI_FALSE;
    }
    return RTI_TRUE;   
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *ChatUserPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    ::ChatUserPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    ::ChatUserPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    ::ChatUserPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    ::ChatUserPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    ::ChatUserPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    ChatUserPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    ChatUserPlugin_destroy_sample;

    plugin->serializeFnc = 
    (PRESTypePluginSerializeFunction) PRESTypePlugin_interpretedSerialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction) PRESTypePlugin_interpretedDeserializeWithAlloc;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    ::ChatUserPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    PRESTypePlugin_interpretedGetSerializedSampleMinSize;
    plugin->getDeserializedSampleMaxSizeFnc = NULL; 
    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    ChatUserPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    ChatUserPlugin_return_sample;
    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    ::ChatUserPlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    ::ChatUserPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    PRESTypePlugin_interpretedSerializeKey;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    ::ChatUserPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    PRESTypePlugin_interpretedDeserializeKey;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    PRESTypePlugin_interpretedInstanceToKeyHash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    ::ChatUserPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    ChatUserPlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    ChatUserPlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    ::ChatUserPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    ::ChatUserPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    #ifdef NDDS_STANDALONE_TYPE
    plugin->typeCode = NULL; 
    #else
    try {
        plugin->typeCode = (struct RTICdrTypeCode *)
        &::rti::topic::dynamic_type< ::ChatUser >::get().native();
    } catch (...) {
        ::ChatUserPlugin_delete(plugin);
        return NULL;
    }
    #endif
    plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    ChatUserPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    ChatUserPlugin_return_buffer;
    plugin->getBufferWithParams = NULL;
    plugin->returnBufferWithParams = NULL;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    PRESTypePlugin_interpretedGetSerializedSampleSize;

    plugin->getWriterLoanedSampleFnc = NULL; 
    plugin->returnWriterLoanedSampleFnc = NULL;
    plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
    plugin->validateWriterLoanedSampleFnc = NULL;
    plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

    static const char * TYPE_NAME = "ChatUser";
    plugin->endpointTypeName = TYPE_NAME;
    plugin->isMetpType = RTI_FALSE;
    return plugin;
}

void
ChatUserPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* ----------------------------------------------------------------------------
*  Type ChatMessage
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

ChatMessage *
ChatMessagePluginSupport_create_data(void)
{
    try {
        ChatMessage *sample = new ChatMessage();
        ::rti::topic::allocate_sample(*sample);
        return sample;
    } catch (...) {
        return NULL;
    }
}

void 
ChatMessagePluginSupport_destroy_data(
    ChatMessage *sample) 
{
    delete sample;
}

RTIBool 
ChatMessagePluginSupport_copy_data(
    ChatMessage *dst,
    const ChatMessage *src)
{
    try {
        *dst = *src;
    } catch (...) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

ChatMessage *
ChatMessagePluginSupport_create_key(void)
{
    return ChatMessagePluginSupport_create_data();
}

void 
ChatMessagePluginSupport_destroy_key(
    ChatMessageKeyHolder *key) 
{
    ChatMessagePluginSupport_destroy_data(key);
}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
ChatMessagePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    try {
        struct RTIXCdrInterpreterPrograms *programs = NULL;
        struct PRESTypePluginDefaultParticipantData *pd = NULL;
        struct RTIXCdrInterpreterProgramsGenProperty programProperty =
        RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
        if (registration_data) {} /* To avoid warnings */
        if (participant_info) {} /* To avoid warnings */
        if (top_level_registration) {} /* To avoid warnings */
        if (container_plugin_context) {} /* To avoid warnings */
        if (type_code) {} /* To avoid warnings */

        if (!RTIXCdrXTypesComplianceMask_verifyGeneratedXTypesMask(0x0000068C)) {
            return NULL;
        }

        pd = (struct PRESTypePluginDefaultParticipantData *)
        PRESTypePluginDefaultParticipantData_new(participant_info);

        programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
        programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
        programProperty.resolveAlias = RTI_XCDR_TRUE;
        programProperty.inlineStruct = RTI_XCDR_TRUE;
        programProperty.optimizeEnum = RTI_XCDR_TRUE;
        programProperty.unboundedSize = RTIXCdrLong_MAX;

        programProperty.externalReferenceSize = 
        (RTIXCdrUnsignedShort) sizeof(::dds::core::external<char>);
        programProperty.getExternalRefPointerFcn = 
        ::rti::topic::interpreter::get_external_value_pointer;

        programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
            DDS_TypeCodeFactory_get_instance(),
            (DDS_TypeCode *) (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ChatMessage >::get().native()
            ,
            &programProperty,
            RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);

        if (programs == NULL) {
            PRESTypePluginDefaultParticipantData_delete(
                (PRESTypePluginParticipantData)pd);
            return NULL;
        }

        pd->programs = programs;
        return (PRESTypePluginParticipantData)pd;
    } catch (...) {
        return NULL;
    }
}

void 
ChatMessagePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{
    if (participant_data != NULL) {
        struct PRESTypePluginDefaultParticipantData *pd = 
        (struct PRESTypePluginDefaultParticipantData *)participant_data;

        if (pd->programs != NULL) {
            DDS_TypeCodeFactory_remove_programs_from_global_list(
                DDS_TypeCodeFactory_get_instance(),
                pd->programs);
            pd->programs = NULL;
        }
        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }
}

PRESTypePluginEndpointData
ChatMessagePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    try {
        PRESTypePluginEndpointData epd = NULL;
        unsigned int serializedSampleMaxSize = 0;

        unsigned int serializedKeyMaxSize = 0;
        unsigned int serializedKeyMaxSizeV2 = 0;

        if (top_level_registration) {} /* To avoid warnings */
        if (containerPluginContext) {} /* To avoid warnings */

        if (participant_data == NULL) {
            return NULL;
        } 

        epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ChatMessagePluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ChatMessagePluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::ChatMessagePluginSupport_create_key ,                (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::ChatMessagePluginSupport_destroy_key);

        if (epd == NULL) {
            return NULL;
        } 

        serializedKeyMaxSize =  ::ChatMessagePlugin_get_serialized_key_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
        serializedKeyMaxSizeV2 = ChatMessagePlugin_get_serialized_key_max_size_for_keyhash(
            epd,
            RTI_CDR_ENCAPSULATION_ID_CDR2_BE,
            0);

        if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
            epd,
            endpoint_info,
            serializedKeyMaxSize,
            serializedKeyMaxSizeV2))  
        {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }

        if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
            serializedSampleMaxSize = ::ChatMessagePlugin_get_serialized_sample_max_size(
                epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
            PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

            if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
                (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::ChatMessagePlugin_get_serialized_sample_max_size, epd,
                (PRESTypePluginGetSerializedSampleSizeFunction)
                PRESTypePlugin_interpretedGetSerializedSampleSize,
                epd) == RTI_FALSE) {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }
        }

        return epd;
    } catch (...) {
        return NULL;
    }
}

void 
ChatMessagePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
ChatMessagePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage *sample,
    void *handle)
{
    try {
        ::rti::topic::reset_sample(*sample);
    } catch(const std::exception& ex) {
        RTICdrLog_logWithFunctionName(
            RTI_LOG_BIT_EXCEPTION,
            "ChatMessagePlugin_return_sample",
            &RTI_LOG_ANY_FAILURE_ss,
            "exception: ",
            ex.what());
    }

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
ChatMessagePlugin_copy_sample(
    PRESTypePluginEndpointData,
    ChatMessage *dst,
    const ChatMessage *src)
{
    return ::ChatMessagePluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
ChatMessagePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool
ChatMessagePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ChatMessage *sample,
    ::dds::core::policy::DataRepresentationId representation)
{
    using namespace ::dds::core::policy;

    try{
        RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
        struct RTICdrStream cdrStream;
        struct PRESTypePluginDefaultEndpointData epd;
        RTIBool result;
        struct PRESTypePluginDefaultParticipantData pd;
        struct RTIXCdrTypePluginProgramContext defaultProgramContext =
        RTIXCdrTypePluginProgramContext_INTIALIZER;
        struct PRESTypePlugin plugin = PRES_TYPEPLUGIN_DEFAULT;

        if (length == NULL) {
            return RTI_FALSE;
        }

        RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
        epd.programContext = defaultProgramContext;
        epd._participantData = &pd;
        epd.typePlugin = &plugin;
        epd.programContext.endpointPluginData = &epd;
        try {
            plugin.typeCode = (struct RTICdrTypeCode *)
            (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ChatMessage >::get().native()
            ;
        } catch (...) {
            return RTI_FALSE;
        }
        pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
        ChatMessage, 
        true, true, true>();

        encapsulationId = DDS_TypeCode_get_native_encapsulation(
            (DDS_TypeCode *) plugin.typeCode,
            representation);

        if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
            return RTI_FALSE;
        }

        epd._maxSizeSerializedSample =
        ChatMessagePlugin_get_serialized_sample_max_size(
            (PRESTypePluginEndpointData)&epd, 
            RTI_TRUE, 
            encapsulationId,
            0);

        if (buffer == NULL) {
            *length = 
            PRESTypePlugin_interpretedGetSerializedSampleSize(
                (PRESTypePluginEndpointData)&epd,
                RTI_TRUE,
                encapsulationId,
                0,
                sample);

            if (*length == 0) {
                return RTI_FALSE;
            }

            return RTI_TRUE;
        }    

        RTICdrStream_init(&cdrStream);
        RTICdrStream_set(&cdrStream, buffer, *length);

        result = PRESTypePlugin_interpretedSerialize(
            (PRESTypePluginEndpointData)&epd, 
            sample, 
            &cdrStream, 
            RTI_TRUE, 
            encapsulationId,
            RTI_TRUE, 
            NULL);  

        *length = (unsigned int) RTICdrStream_getCurrentPositionOffset(&cdrStream);
        return result;
    } catch (...) {
        return RTI_FALSE;
    }
}

RTIBool
ChatMessagePlugin_deserialize_from_cdr_buffer(
    ChatMessage *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream cdrStream;
    struct PRESTypePluginDefaultParticipantData pd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePlugin plugin;
    struct PRESTypePluginDefaultEndpointData epd;

    RTICdrStream_init(&cdrStream);
    /*
    * The buffer is constant because this is a deserialization function
    * (the buffer is an input parameter, not an output parameter).
    * However, the buffer member in the stream is a (char *) so coverity
    * complains in case something else modifies the buffer's contents later.
    *
    * We don't currently have a stream type with a constant buffer.
    * Therefore, we suppress the warning after making sure that this function
    * doesn't modify the contents of the stream's buffer.
    */
    /* coverity[cert_exp40_c_violation : FALSE] */
    RTICdrStream_set(&cdrStream, (char *) buffer, length);

    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    try {
        plugin.typeCode = (struct RTICdrTypeCode *)
        (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ChatMessage >::get().native()
        ;
    } catch (...) {
        return RTI_FALSE;
    }
    pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
    ChatMessage, 
    true, true, true>();

    RTIXCdrSampleAssignabilityProperty_setFromGlobalComplianceMask(
        &epd._assignabilityProperty);

    ::rti::topic::reset_sample(*sample);
    return PRESTypePlugin_interpretedDeserialize( 
        (PRESTypePluginEndpointData)&epd,
        sample,
        &cdrStream,
        RTI_TRUE, 
        RTI_TRUE, 
        NULL);
}

unsigned int 
ChatMessagePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return 0;
    }
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
ChatMessagePlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

RTIBool ChatMessagePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    try {
        RTIBool result;
        if (drop_sample) {} /* To avoid warnings */
        cdrStream->_xTypesState.unassignable = RTI_FALSE;
        result= PRESTypePlugin_interpretedDeserializeKey( 
            endpoint_data, (sample != NULL)?*sample:NULL, cdrStream,
            deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
        if (result) {
            if (cdrStream->_xTypesState.unassignable) {
                result = RTI_FALSE;
            }
        }
        return result;    
    } catch (...) {
        return RTI_FALSE;
    }     
}

unsigned int
ChatMessagePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    try {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
            endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    } catch (...) {
        return RTI_FALSE;
    }    
}

unsigned int
ChatMessagePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        &overflow,
        encapsulation_id,
        current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
ChatMessagePlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessageKeyHolder *dst, 
    const ChatMessage *src)
{
    try {
        if (endpoint_data) {} /* To avoid warnings */   

        dst->msg_id() = src->msg_id();
        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }    
}

RTIBool 
ChatMessagePlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ChatMessage *dst, const
    ChatMessageKeyHolder *src)
{
    try {
        if (endpoint_data) {} /* To avoid warnings */   
        dst->msg_id() = src->msg_id();
        return RTI_TRUE;
    } catch (...) {
        return RTI_FALSE;
    }    
}

RTIBool 
ChatMessagePlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *cdrStream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos)
{
    ChatMessage * sample = NULL;
    sample = (ChatMessage *)
    PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);
    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (!PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        cdrStream, 
        deserialize_encapsulation, 
        RTI_TRUE,
        endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
    if (!PRESTypePlugin_interpretedInstanceToKeyHash(
        endpoint_data,
        keyhash,
        sample,
        RTICdrStream_getEncapsulationKind(cdrStream))) {
        return RTI_FALSE;
    }
    return RTI_TRUE;   
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *ChatMessagePlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    ::ChatMessagePlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    ::ChatMessagePlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    ::ChatMessagePlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    ::ChatMessagePlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    ::ChatMessagePlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    ChatMessagePlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    ChatMessagePlugin_destroy_sample;

    plugin->serializeFnc = 
    (PRESTypePluginSerializeFunction) PRESTypePlugin_interpretedSerialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction) PRESTypePlugin_interpretedDeserializeWithAlloc;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    ::ChatMessagePlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    PRESTypePlugin_interpretedGetSerializedSampleMinSize;
    plugin->getDeserializedSampleMaxSizeFnc = NULL; 
    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    ChatMessagePlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    ChatMessagePlugin_return_sample;
    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    ::ChatMessagePlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    ::ChatMessagePlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    PRESTypePlugin_interpretedSerializeKey;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    ::ChatMessagePlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    PRESTypePlugin_interpretedDeserializeKey;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    PRESTypePlugin_interpretedInstanceToKeyHash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    ::ChatMessagePlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    ChatMessagePlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    ChatMessagePlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    ::ChatMessagePlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    ::ChatMessagePlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    #ifdef NDDS_STANDALONE_TYPE
    plugin->typeCode = NULL; 
    #else
    try {
        plugin->typeCode = (struct RTICdrTypeCode *)
        &::rti::topic::dynamic_type< ::ChatMessage >::get().native();
    } catch (...) {
        ::ChatMessagePlugin_delete(plugin);
        return NULL;
    }
    #endif
    plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    ChatMessagePlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    ChatMessagePlugin_return_buffer;
    plugin->getBufferWithParams = NULL;
    plugin->returnBufferWithParams = NULL;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    PRESTypePlugin_interpretedGetSerializedSampleSize;

    plugin->getWriterLoanedSampleFnc = NULL; 
    plugin->returnWriterLoanedSampleFnc = NULL;
    plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
    plugin->validateWriterLoanedSampleFnc = NULL;
    plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

    static const char * TYPE_NAME = "ChatMessage";
    plugin->endpointTypeName = TYPE_NAME;
    plugin->isMetpType = RTI_FALSE;
    return plugin;
}

void
ChatMessagePlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 
