/*************************************************************/
/* Copyright (C) 2023 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED.
 * THIS COPYRIGHT STATEMENT MAY NOT BE REMOVED. */

/* Generated for: Linuxlab Solucoes e Sistemas LTDA - Named User Subscription, 1 User, Expiration: April 2, 2024, License 17532 17532,
 * only for project "ANY PROJECT - only for use by Claudio Reis Lacerda". */
/* Abstract syntax: sbcap */
/* Created: Tue Jul 18 11:40:33 2023 */
/* ASN.1/C++ compiler version: 7.2 */
/* Code generated for runtime version 7.2 or later */
/* Compiler operating system: Linux with 64-bit support */
/* Compiler machine type: x86-64 */
/* Target operating system: Linux with 64-bit support */
/* Target machine type: x86-64 */
/* C++ compiler options required: -m64 */
/* ASN.1 compiler options and file names specified:
 * -per -root -autoencdec
 * ../../../../asn1studio/linux-x86-64bit/Asn1Standards/3GPP/29-series/SBCAP/v16.0.0/sbcap.asn
 */

#ifndef OSS_sbcap
#define OSS_sbcap

#include "oss.h"
#include "asn1.h"

/* Representation types */

enum Criticality {
    reject = 0,
    ignore = 1,
    notify = 2
};

enum Concurrent_Warning_Message_Indicator {
    Concurrent_Warning_Message_Indicator_true = 0
};

enum RAT_Selector_5GS {
    RAT_Selector_5GS_true = 0
};

enum Send_Write_Replace_Warning_Indication {
    Send_Write_Replace_Warning_Indication_true = 0
};

enum Send_Stop_Warning_Indication {
    Send_Stop_Warning_Indication_true = 0
};

enum Stop_All_Indicator {
    Stop_All_Indicator_true = 0
};

enum TriggeringMessage {
    initiating_message = 0,
    successful_outcome = 1,
    unsuccessful_outcome = 2,
    outcome = 3
};

enum TypeOfError {
    not_understood = 0,
    missing = 1
};

enum Presence {
    optional = 0,
    conditional = 1,
    mandatory = 2
};


const OSS_UINT32 message_accepted = 0;
const OSS_UINT32 parameter_not_recognised = 1;
const OSS_UINT32 parameter_value_invalid = 2;
const OSS_UINT32 valid_message_not_identified = 3;
const OSS_UINT32 tracking_area_not_valid = 4;
const OSS_UINT32 unrecognised_message = 5;
const OSS_UINT32 missing_mandatory_element = 6;
const OSS_UINT32 mME_capacity_exceeded = 7;
const OSS_UINT32 mME_memory_exceeded = 8;
const OSS_UINT32 warning_broadcast_not_supported = 9;
const OSS_UINT32 warning_broadcast_not_operational = 10;
const OSS_UINT32 message_reference_already_used = 11;
const OSS_UINT32 unspecifed_error = 12;
const OSS_UINT32 transfer_syntax_error = 13;
const OSS_UINT32 semantic_error = 14;
const OSS_UINT32 message_not_compatible_with_receiver_state = 15;
const OSS_UINT32 abstract_syntax_error_reject = 16;
const OSS_UINT32 abstract_syntax_error_ignore_and_notify = 17;
const OSS_UINT32 abstract_syntax_error_falsely_constructed_message = 18;
typedef OSS_UINT32 ProcedureCode;

class OSS_PUBLIC __seq1;

class OSS_PUBLIC __seqof1 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq1 component;

    __seqof1();
    __seqof1(const __seqof1 &);
    ~__seqof1();

    __seqof1 & operator = (const __seqof1 &);
    int operator == (const __seqof1 &) const;
    int operator != (const __seqof1 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof1 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof1 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof1 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq2;

class OSS_PUBLIC __seqof2 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq2 component;

    __seqof2();
    __seqof2(const __seqof2 &);
    ~__seqof2();

    __seqof2 & operator = (const __seqof2 &);
    int operator == (const __seqof2 &) const;
    int operator != (const __seqof2 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof2 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof2 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof2 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Write_Replace_Warning_Request   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof1 protocolIEs;
    typedef __seqof2 protocolExtensions;

    Write_Replace_Warning_Request();
    Write_Replace_Warning_Request(const Write_Replace_Warning_Request &);
    Write_Replace_Warning_Request(const protocolIEs &, const protocolExtensions &);
    Write_Replace_Warning_Request(const protocolIEs &);

    Write_Replace_Warning_Request & operator = (const Write_Replace_Warning_Request &);
    int operator == (const Write_Replace_Warning_Request &) const;
    int operator != (const Write_Replace_Warning_Request &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);

    protocolExtensions *get_protocolExtensions();
    const protocolExtensions *get_protocolExtensions() const;
    void set_protocolExtensions(const protocolExtensions &);
    int protocolExtensions_is_present() const;
    void omit_protocolExtensions();
private:
    OSS_UINT32 bit_mask;
    protocolIEs protocolIEs_field;
    protocolExtensions protocolExtensions_field;
};

class OSS_PUBLIC __seq5;

class OSS_PUBLIC __seqof5 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq5 component;

    __seqof5();
    __seqof5(const __seqof5 &);
    ~__seqof5();

    __seqof5 & operator = (const __seqof5 &);
    int operator == (const __seqof5 &) const;
    int operator != (const __seqof5 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof5 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof5 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof5 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq6;

class OSS_PUBLIC __seqof6 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq6 component;

    __seqof6();
    __seqof6(const __seqof6 &);
    ~__seqof6();

    __seqof6 & operator = (const __seqof6 &);
    int operator == (const __seqof6 &) const;
    int operator != (const __seqof6 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof6 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof6 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof6 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Stop_Warning_Request   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof5 protocolIEs;
    typedef __seqof6 protocolExtensions;

    Stop_Warning_Request();
    Stop_Warning_Request(const Stop_Warning_Request &);
    Stop_Warning_Request(const protocolIEs &, const protocolExtensions &);
    Stop_Warning_Request(const protocolIEs &);

    Stop_Warning_Request & operator = (const Stop_Warning_Request &);
    int operator == (const Stop_Warning_Request &) const;
    int operator != (const Stop_Warning_Request &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);

    protocolExtensions *get_protocolExtensions();
    const protocolExtensions *get_protocolExtensions() const;
    void set_protocolExtensions(const protocolExtensions &);
    int protocolExtensions_is_present() const;
    void omit_protocolExtensions();
private:
    OSS_UINT32 bit_mask;
    protocolIEs protocolIEs_field;
    protocolExtensions protocolExtensions_field;
};

class OSS_PUBLIC __seq17;

class OSS_PUBLIC __seqof17 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq17 component;

    __seqof17();
    __seqof17(const __seqof17 &);
    ~__seqof17();

    __seqof17 & operator = (const __seqof17 &);
    int operator == (const __seqof17 &) const;
    int operator != (const __seqof17 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof17 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof17 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof17 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Error_Indication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof17 protocolIEs;

    Error_Indication();
    Error_Indication(const Error_Indication &);
    Error_Indication(const protocolIEs &);

    Error_Indication & operator = (const Error_Indication &);
    int operator == (const Error_Indication &) const;
    int operator != (const Error_Indication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);
private:
    protocolIEs protocolIEs_field;
};

class OSS_PUBLIC __seq9;

class OSS_PUBLIC __seqof9 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq9 component;

    __seqof9();
    __seqof9(const __seqof9 &);
    ~__seqof9();

    __seqof9 & operator = (const __seqof9 &);
    int operator == (const __seqof9 &) const;
    int operator != (const __seqof9 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof9 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof9 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof9 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq10;

class OSS_PUBLIC __seqof10 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq10 component;

    __seqof10();
    __seqof10(const __seqof10 &);
    ~__seqof10();

    __seqof10 & operator = (const __seqof10 &);
    int operator == (const __seqof10 &) const;
    int operator != (const __seqof10 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof10 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof10 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof10 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Write_Replace_Warning_Indication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof9 protocolIEs;
    typedef __seqof10 protocolExtensions;

    Write_Replace_Warning_Indication();
    Write_Replace_Warning_Indication(const Write_Replace_Warning_Indication &);
    Write_Replace_Warning_Indication(const protocolIEs &, const protocolExtensions &);
    Write_Replace_Warning_Indication(const protocolIEs &);

    Write_Replace_Warning_Indication & operator = (const Write_Replace_Warning_Indication &);
    int operator == (const Write_Replace_Warning_Indication &) const;
    int operator != (const Write_Replace_Warning_Indication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);

    protocolExtensions *get_protocolExtensions();
    const protocolExtensions *get_protocolExtensions() const;
    void set_protocolExtensions(const protocolExtensions &);
    int protocolExtensions_is_present() const;
    void omit_protocolExtensions();
private:
    OSS_UINT32 bit_mask;
    protocolIEs protocolIEs_field;
    protocolExtensions protocolExtensions_field;
};

class OSS_PUBLIC __seq11;

class OSS_PUBLIC __seqof11 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq11 component;

    __seqof11();
    __seqof11(const __seqof11 &);
    ~__seqof11();

    __seqof11 & operator = (const __seqof11 &);
    int operator == (const __seqof11 &) const;
    int operator != (const __seqof11 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof11 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof11 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof11 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq12;

class OSS_PUBLIC __seqof12 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq12 component;

    __seqof12();
    __seqof12(const __seqof12 &);
    ~__seqof12();

    __seqof12 & operator = (const __seqof12 &);
    int operator == (const __seqof12 &) const;
    int operator != (const __seqof12 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof12 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof12 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof12 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Stop_Warning_Indication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof11 protocolIEs;
    typedef __seqof12 protocolExtensions;

    Stop_Warning_Indication();
    Stop_Warning_Indication(const Stop_Warning_Indication &);
    Stop_Warning_Indication(const protocolIEs &, const protocolExtensions &);
    Stop_Warning_Indication(const protocolIEs &);

    Stop_Warning_Indication & operator = (const Stop_Warning_Indication &);
    int operator == (const Stop_Warning_Indication &) const;
    int operator != (const Stop_Warning_Indication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);

    protocolExtensions *get_protocolExtensions();
    const protocolExtensions *get_protocolExtensions() const;
    void set_protocolExtensions(const protocolExtensions &);
    int protocolExtensions_is_present() const;
    void omit_protocolExtensions();
private:
    OSS_UINT32 bit_mask;
    protocolIEs protocolIEs_field;
    protocolExtensions protocolExtensions_field;
};

class OSS_PUBLIC __seq13;

class OSS_PUBLIC __seqof13 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq13 component;

    __seqof13();
    __seqof13(const __seqof13 &);
    ~__seqof13();

    __seqof13 & operator = (const __seqof13 &);
    int operator == (const __seqof13 &) const;
    int operator != (const __seqof13 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof13 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof13 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof13 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq14;

class OSS_PUBLIC __seqof14 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq14 component;

    __seqof14();
    __seqof14(const __seqof14 &);
    ~__seqof14();

    __seqof14 & operator = (const __seqof14 &);
    int operator == (const __seqof14 &) const;
    int operator != (const __seqof14 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof14 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof14 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof14 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PWS_Restart_Indication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof13 protocolIEs;
    typedef __seqof14 protocolExtensions;

    PWS_Restart_Indication();
    PWS_Restart_Indication(const PWS_Restart_Indication &);
    PWS_Restart_Indication(const protocolIEs &, const protocolExtensions &);
    PWS_Restart_Indication(const protocolIEs &);

    PWS_Restart_Indication & operator = (const PWS_Restart_Indication &);
    int operator == (const PWS_Restart_Indication &) const;
    int operator != (const PWS_Restart_Indication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);

    protocolExtensions *get_protocolExtensions();
    const protocolExtensions *get_protocolExtensions() const;
    void set_protocolExtensions(const protocolExtensions &);
    int protocolExtensions_is_present() const;
    void omit_protocolExtensions();
private:
    OSS_UINT32 bit_mask;
    protocolIEs protocolIEs_field;
    protocolExtensions protocolExtensions_field;
};

class OSS_PUBLIC __seq15;

class OSS_PUBLIC __seqof15 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq15 component;

    __seqof15();
    __seqof15(const __seqof15 &);
    ~__seqof15();

    __seqof15 & operator = (const __seqof15 &);
    int operator == (const __seqof15 &) const;
    int operator != (const __seqof15 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof15 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof15 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof15 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __seq16;

class OSS_PUBLIC __seqof16 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq16 component;

    __seqof16();
    __seqof16(const __seqof16 &);
    ~__seqof16();

    __seqof16 & operator = (const __seqof16 &);
    int operator == (const __seqof16 &) const;
    int operator != (const __seqof16 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__seqof16 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __seqof16 *);

    int remove_front();
    int remove_after(OssIndex);

    __seqof16 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC PWS_Failure_Indication   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __seqof15 protocolIEs;
    typedef __seqof16 protocolExtensions;

    PWS_Failure_Indication();
    PWS_Failure_Indication(const PWS_Failure_Indication &);
    PWS_Failure_Indication(const protocolIEs &, const protocolExtensions &);
    PWS_Failure_Indication(const protocolIEs &);

    PWS_Failure_Indication & operator = (const PWS_Failure_Indication &);
    int operator == (const PWS_Failure_Indication &) const;
    int operator != (const PWS_Failure_Indication &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);

    protocolExtensions *get_protocolExtensions();
    const protocolExtensions *get_protocolExtensions() const;
    void set_protocolExtensions(const protocolExtensions &);
    int protocolExtensions_is_present() const;
    void omit_protocolExtensions();
private:
    OSS_UINT32 bit_mask;
    protocolIEs protocolIEs_field;
    protocolExtensions protocolExtensions_field;
};

class OSS_PUBLIC SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage : public OssConstrainedOpenType
{
public:
    SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage();
    SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage(const SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage &);
    ~SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage();
    SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage & operator = (const SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage &);
    int operator == (const SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage &) const;
    int operator != (const SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Write_Replace_Warning_Request *get_Write_Replace_Warning_Request();
    const Write_Replace_Warning_Request *get_Write_Replace_Warning_Request() const;
    void set_Write_Replace_Warning_Request(const Write_Replace_Warning_Request &);
    Write_Replace_Warning_Request *release_Write_Replace_Warning_Request();
    void set_Write_Replace_Warning_Request(Write_Replace_Warning_Request *);

    Stop_Warning_Request *get_Stop_Warning_Request();
    const Stop_Warning_Request *get_Stop_Warning_Request() const;
    void set_Stop_Warning_Request(const Stop_Warning_Request &);
    Stop_Warning_Request *release_Stop_Warning_Request();
    void set_Stop_Warning_Request(Stop_Warning_Request *);

    Error_Indication *get_Error_Indication();
    const Error_Indication *get_Error_Indication() const;
    void set_Error_Indication(const Error_Indication &);
    Error_Indication *release_Error_Indication();
    void set_Error_Indication(Error_Indication *);

    Write_Replace_Warning_Indication *get_Write_Replace_Warning_Indication();
    const Write_Replace_Warning_Indication *get_Write_Replace_Warning_Indication() const;
    void set_Write_Replace_Warning_Indication(const Write_Replace_Warning_Indication &);
    Write_Replace_Warning_Indication *release_Write_Replace_Warning_Indication();
    void set_Write_Replace_Warning_Indication(Write_Replace_Warning_Indication *);

    Stop_Warning_Indication *get_Stop_Warning_Indication();
    const Stop_Warning_Indication *get_Stop_Warning_Indication() const;
    void set_Stop_Warning_Indication(const Stop_Warning_Indication &);
    Stop_Warning_Indication *release_Stop_Warning_Indication();
    void set_Stop_Warning_Indication(Stop_Warning_Indication *);

    PWS_Restart_Indication *get_PWS_Restart_Indication();
    const PWS_Restart_Indication *get_PWS_Restart_Indication() const;
    void set_PWS_Restart_Indication(const PWS_Restart_Indication &);
    PWS_Restart_Indication *release_PWS_Restart_Indication();
    void set_PWS_Restart_Indication(PWS_Restart_Indication *);

    PWS_Failure_Indication *get_PWS_Failure_Indication();
    const PWS_Failure_Indication *get_PWS_Failure_Indication() const;
    void set_PWS_Failure_Indication(const PWS_Failure_Indication &);
    PWS_Failure_Indication *release_PWS_Failure_Indication();
    void set_PWS_Failure_Indication(PWS_Failure_Indication *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC InitiatingMessage   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum Criticality criticality;
    typedef SBC_AP_ELEMENTARY_PROCEDURES_InitiatingMessage value;

    InitiatingMessage();
    InitiatingMessage(const InitiatingMessage &);
    InitiatingMessage(procedureCode, criticality, const value &);

    InitiatingMessage & operator = (const InitiatingMessage &);
    int operator == (const InitiatingMessage &) const;
    int operator != (const InitiatingMessage &) const;

    procedureCode & get_procedureCode();
    procedureCode get_procedureCode() const;
    void set_procedureCode(procedureCode);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    procedureCode procedureCode_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared24;

class OSS_PUBLIC __shared25 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared24 component;

    __shared25();
    __shared25(const __shared25 &);
    ~__shared25();

    __shared25 & operator = (const __shared25 &);
    int operator == (const __shared25 &) const;
    int operator != (const __shared25 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared25 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared25 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared25 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared26;

class OSS_PUBLIC __shared27 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared26 component;

    __shared27();
    __shared27(const __shared27 &);
    ~__shared27();

    __shared27 & operator = (const __shared27 &);
    int operator == (const __shared27 &) const;
    int operator != (const __shared27 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared27 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared27 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared27 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC __shared28   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared25 protocolIEs;
    typedef __shared27 protocolExtensions;

    __shared28();
    __shared28(const __shared28 &);
    __shared28(const protocolIEs &, const protocolExtensions &);
    __shared28(const protocolIEs &);

    __shared28 & operator = (const __shared28 &);
    int operator == (const __shared28 &) const;
    int operator != (const __shared28 &) const;

    protocolIEs & get_protocolIEs();
    const protocolIEs & get_protocolIEs() const;
    void set_protocolIEs(const protocolIEs &);

    protocolExtensions *get_protocolExtensions();
    const protocolExtensions *get_protocolExtensions() const;
    void set_protocolExtensions(const protocolExtensions &);
    int protocolExtensions_is_present() const;
    void omit_protocolExtensions();
private:
    OSS_UINT32 bit_mask;
    protocolIEs protocolIEs_field;
    protocolExtensions protocolExtensions_field;
};

typedef __shared28 Write_Replace_Warning_Response;

typedef __shared28 Stop_Warning_Response;

class OSS_PUBLIC SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome : public OssConstrainedOpenType
{
public:
    SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome();
    SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome(const SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &);
    ~SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome();
    SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome & operator = (const SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &);
    int operator == (const SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &) const;
    int operator != (const SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared28 *get_Write_Replace_Warning_Response();
    const __shared28 *get_Write_Replace_Warning_Response() const;
    void set_Write_Replace_Warning_Response(const __shared28 &);
    __shared28 *release_Write_Replace_Warning_Response();
    void set_Write_Replace_Warning_Response(__shared28 *);

    __shared28 *get_Stop_Warning_Response();
    const __shared28 *get_Stop_Warning_Response() const;
    void set_Stop_Warning_Response(const __shared28 &);
    __shared28 *release_Stop_Warning_Response();
    void set_Stop_Warning_Response(__shared28 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC SuccessfulOutcome   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum Criticality criticality;
    typedef SBC_AP_ELEMENTARY_PROCEDURES_SuccessfulOutcome value;

    SuccessfulOutcome();
    SuccessfulOutcome(const SuccessfulOutcome &);
    SuccessfulOutcome(procedureCode, criticality, const value &);

    SuccessfulOutcome & operator = (const SuccessfulOutcome &);
    int operator == (const SuccessfulOutcome &) const;
    int operator != (const SuccessfulOutcome &) const;

    procedureCode & get_procedureCode();
    procedureCode get_procedureCode() const;
    void set_procedureCode(procedureCode);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    procedureCode procedureCode_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome : public OssConstrainedOpenType
{
public:
    SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome();
    SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome(const SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &);
    ~SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome();
    SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome & operator = (const SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &);
    int operator == (const SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &) const;
    int operator != (const SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC UnsuccessfulOutcome   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum Criticality criticality;
    typedef SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome value;

    UnsuccessfulOutcome();
    UnsuccessfulOutcome(const UnsuccessfulOutcome &);
    UnsuccessfulOutcome(procedureCode, criticality, const value &);

    UnsuccessfulOutcome & operator = (const UnsuccessfulOutcome &);
    int operator == (const UnsuccessfulOutcome &) const;
    int operator != (const UnsuccessfulOutcome &) const;

    procedureCode & get_procedureCode();
    procedureCode get_procedureCode() const;
    void set_procedureCode(procedureCode);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    procedureCode procedureCode_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC SBC_AP_PDU  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	initiatingMessage_chosen = 1,
	successfulOutcome_chosen = 2,
	unsuccessfulOutcome_chosen = 3
    };
    typedef InitiatingMessage initiatingMessage;
    typedef SuccessfulOutcome successfulOutcome;
    typedef UnsuccessfulOutcome unsuccessfulOutcome;

    SBC_AP_PDU();
    SBC_AP_PDU(const SBC_AP_PDU &);
    ~SBC_AP_PDU();

    SBC_AP_PDU & operator = (const SBC_AP_PDU &);
    int operator == (const SBC_AP_PDU &) const;
    int operator != (const SBC_AP_PDU &) const;

    initiatingMessage *get_initiatingMessage();
    const initiatingMessage *get_initiatingMessage() const;
    void set_initiatingMessage(const initiatingMessage &);

    successfulOutcome *get_successfulOutcome();
    const successfulOutcome *get_successfulOutcome() const;
    void set_successfulOutcome(const successfulOutcome &);

    unsuccessfulOutcome *get_unsuccessfulOutcome();
    const unsuccessfulOutcome *get_unsuccessfulOutcome() const;
    void set_unsuccessfulOutcome(const unsuccessfulOutcome &);
private:
    union {
	initiatingMessage *initiatingMessage_field;
	successfulOutcome *successfulOutcome_field;
	unsuccessfulOutcome *unsuccessfulOutcome_field;
    };
    void cleanup();
};

typedef OSS_UINT32 Cause;

typedef OSS_UINT32 Extended_Repetition_Period;

typedef OSS_UINT32 Number_of_Broadcasts_Requested;

typedef OSS_UINT32 Repetition_Period;

typedef OssBitString Data_Coding_Scheme;

typedef OssBitString Message_Identifier;

typedef OssString Omc_Id;

typedef OssBitString Serial_Number;

typedef OssString Warning_Message_Content;

typedef OssString Warning_Area_Coordinates;

typedef OssString Warning_Security_Information;

typedef OssString Warning_Type;

typedef OSS_UINT32 ProtocolIE_ID;

class OSS_PUBLIC __seq43;

class OSS_PUBLIC __shared3 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq43 component;

    __shared3();
    __shared3(const __shared3 &);
    ~__shared3();

    __shared3 & operator = (const __shared3 &);
    int operator == (const __shared3 &) const;
    int operator != (const __shared3 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared3 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared3 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared3 *extract_after(OssIndex, OssIndex);
};

typedef __shared3 List_of_TAIs;

class OSS_PUBLIC EUTRAN_CGI;

class OSS_PUBLIC __shared4 : public OssList  /* SEQUENCE OF */
{
public:
    typedef EUTRAN_CGI component;

    __shared4();
    __shared4(const __shared4 &);
    ~__shared4();

    __shared4 & operator = (const __shared4 &);
    int operator == (const __shared4 &) const;
    int operator != (const __shared4 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared4 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared4 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared4 *extract_after(OssIndex, OssIndex);
};

typedef __shared4 ECGIList;

class OSS_PUBLIC TAI;

class OSS_PUBLIC __shared5 : public OssList  /* SEQUENCE OF */
{
public:
    typedef TAI component;

    __shared5();
    __shared5(const __shared5 &);
    ~__shared5();

    __shared5 & operator = (const __shared5 &);
    int operator == (const __shared5 &) const;
    int operator != (const __shared5 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared5 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared5 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared5 *extract_after(OssIndex, OssIndex);
};

typedef __shared5 TAI_List_for_Warning;

class OSS_PUBLIC __shared6 : public OssList  /* SEQUENCE OF */
{
public:
    typedef OssString component;

    __shared6();
    __shared6(const __shared6 &);
    ~__shared6();

    __shared6 & operator = (const __shared6 &);
    int operator == (const __shared6 &) const;
    int operator != (const __shared6 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared6 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared6 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared6 *extract_after(OssIndex, OssIndex);
};

typedef __shared6 Emergency_Area_ID_List;

class OSS_PUBLIC Warning_Area_List  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cell_ID_List_chosen = 1,
	tracking_Area_List_for_Warning_chosen = 2,
	emergency_Area_ID_List_chosen = 3
    };
    typedef __shared4 cell_ID_List;
    typedef __shared5 tracking_Area_List_for_Warning;
    typedef __shared6 emergency_Area_ID_List;

    Warning_Area_List();
    Warning_Area_List(const Warning_Area_List &);
    ~Warning_Area_List();

    Warning_Area_List & operator = (const Warning_Area_List &);
    int operator == (const Warning_Area_List &) const;
    int operator != (const Warning_Area_List &) const;

    cell_ID_List *get_cell_ID_List();
    const cell_ID_List *get_cell_ID_List() const;
    void set_cell_ID_List(const cell_ID_List &);

    tracking_Area_List_for_Warning *get_tracking_Area_List_for_Warning();
    const tracking_Area_List_for_Warning *get_tracking_Area_List_for_Warning() const;
    void set_tracking_Area_List_for_Warning(const tracking_Area_List_for_Warning &);

    emergency_Area_ID_List *get_emergency_Area_ID_List();
    const emergency_Area_ID_List *get_emergency_Area_ID_List() const;
    void set_emergency_Area_ID_List(const emergency_Area_ID_List &);
private:
    union {
	void *cell_ID_List_field;
	void *tracking_Area_List_for_Warning_field;
	void *emergency_Area_ID_List_field;
    };
    void cleanup();
};

class OSS_PUBLIC ENB_ID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	macroENB_ID_chosen = 1,
	homeENB_ID_chosen = 2,
	short_macroENB_ID_chosen = 3,
	long_macroENB_ID_chosen = 4
    };
    typedef OssBitString macroENB_ID;
    typedef OssBitString homeENB_ID;
    typedef OssBitString short_macroENB_ID;
    typedef OssBitString long_macroENB_ID;

    ENB_ID();
    ENB_ID(const ENB_ID &);
    ~ENB_ID();

    ENB_ID & operator = (const ENB_ID &);
    int operator == (const ENB_ID &) const;
    int operator != (const ENB_ID &) const;

    macroENB_ID *get_macroENB_ID();
    const macroENB_ID *get_macroENB_ID() const;
    void set_macroENB_ID(const macroENB_ID &);

    homeENB_ID *get_homeENB_ID();
    const homeENB_ID *get_homeENB_ID() const;
    void set_homeENB_ID(const homeENB_ID &);

    short_macroENB_ID *get_short_macroENB_ID();
    const short_macroENB_ID *get_short_macroENB_ID() const;
    void set_short_macroENB_ID(const short_macroENB_ID &);

    long_macroENB_ID *get_long_macroENB_ID();
    const long_macroENB_ID *get_long_macroENB_ID() const;
    void set_long_macroENB_ID(const long_macroENB_ID &);
private:
    union {
	OSSC::COssBitString macroENB_ID_field;
	OSSC::COssBitString homeENB_ID_field;
	OSSC::COssBitString short_macroENB_ID_field;
	OSSC::COssBitString long_macroENB_ID_field;
    };
    void cleanup();
};

class OSS_PUBLIC __shared1;

class OSS_PUBLIC __shared2 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared1 component;

    __shared2();
    __shared2(const __shared2 &);
    ~__shared2();

    __shared2 & operator = (const __shared2 &);
    int operator == (const __shared2 &) const;
    int operator != (const __shared2 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared2 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared2 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared2 *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Global_ENB_ID   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef ENB_ID eNB_ID;
    typedef __shared2 iE_Extensions;

    Global_ENB_ID();
    Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID(const pLMNidentity &, const eNB_ID &, const iE_Extensions &);
    Global_ENB_ID(const pLMNidentity &, const eNB_ID &);

    Global_ENB_ID & operator = (const Global_ENB_ID &);
    int operator == (const Global_ENB_ID &) const;
    int operator != (const Global_ENB_ID &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    eNB_ID & get_eNB_ID();
    const eNB_ID & get_eNB_ID() const;
    void set_eNB_ID(const eNB_ID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    eNB_ID eNB_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Write_Replace_Warning_Request_IEs_Value : public OssConstrainedOpenType
{
public:
    Write_Replace_Warning_Request_IEs_Value();
    Write_Replace_Warning_Request_IEs_Value(const Write_Replace_Warning_Request_IEs_Value &);
    ~Write_Replace_Warning_Request_IEs_Value();
    Write_Replace_Warning_Request_IEs_Value & operator = (const Write_Replace_Warning_Request_IEs_Value &);
    int operator == (const Write_Replace_Warning_Request_IEs_Value &) const;
    int operator != (const Write_Replace_Warning_Request_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Message_Identifier *get_Message_Identifier();
    const Message_Identifier *get_Message_Identifier() const;
    void set_Message_Identifier(const Message_Identifier &);
    Message_Identifier *release_Message_Identifier();
    void set_Message_Identifier(Message_Identifier *);

    Serial_Number *get_Serial_Number();
    const Serial_Number *get_Serial_Number() const;
    void set_Serial_Number(const Serial_Number &);
    Serial_Number *release_Serial_Number();
    void set_Serial_Number(Serial_Number *);

    __shared3 *get_List_of_TAIs();
    const __shared3 *get_List_of_TAIs() const;
    void set_List_of_TAIs(const __shared3 &);
    __shared3 *release_List_of_TAIs();
    void set_List_of_TAIs(__shared3 *);

    Warning_Area_List *get_Warning_Area_List();
    const Warning_Area_List *get_Warning_Area_List() const;
    void set_Warning_Area_List(const Warning_Area_List &);
    Warning_Area_List *release_Warning_Area_List();
    void set_Warning_Area_List(Warning_Area_List *);

    Repetition_Period *get_Repetition_Period();
    const Repetition_Period *get_Repetition_Period() const;
    void set_Repetition_Period(const Repetition_Period &);
    Repetition_Period *release_Repetition_Period();
    void set_Repetition_Period(Repetition_Period *);

    Extended_Repetition_Period *get_Extended_Repetition_Period();
    const Extended_Repetition_Period *get_Extended_Repetition_Period() const;
    void set_Extended_Repetition_Period(const Extended_Repetition_Period &);
    Extended_Repetition_Period *release_Extended_Repetition_Period();
    void set_Extended_Repetition_Period(Extended_Repetition_Period *);

    Number_of_Broadcasts_Requested *get_Number_of_Broadcasts_Requested();
    const Number_of_Broadcasts_Requested *get_Number_of_Broadcasts_Requested() const;
    void set_Number_of_Broadcasts_Requested(const Number_of_Broadcasts_Requested &);
    Number_of_Broadcasts_Requested *release_Number_of_Broadcasts_Requested();
    void set_Number_of_Broadcasts_Requested(Number_of_Broadcasts_Requested *);

    Warning_Type *get_Warning_Type();
    const Warning_Type *get_Warning_Type() const;
    void set_Warning_Type(const Warning_Type &);
    Warning_Type *release_Warning_Type();
    void set_Warning_Type(Warning_Type *);

    Warning_Security_Information *get_Warning_Security_Information();
    const Warning_Security_Information *get_Warning_Security_Information() const;
    void set_Warning_Security_Information(const Warning_Security_Information &);
    Warning_Security_Information *release_Warning_Security_Information();
    void set_Warning_Security_Information(Warning_Security_Information *);

    Data_Coding_Scheme *get_Data_Coding_Scheme();
    const Data_Coding_Scheme *get_Data_Coding_Scheme() const;
    void set_Data_Coding_Scheme(const Data_Coding_Scheme &);
    Data_Coding_Scheme *release_Data_Coding_Scheme();
    void set_Data_Coding_Scheme(Data_Coding_Scheme *);

    Warning_Message_Content *get_Warning_Message_Content();
    const Warning_Message_Content *get_Warning_Message_Content() const;
    void set_Warning_Message_Content(const Warning_Message_Content &);
    Warning_Message_Content *release_Warning_Message_Content();
    void set_Warning_Message_Content(Warning_Message_Content *);

    Omc_Id *get_Omc_Id();
    const Omc_Id *get_Omc_Id() const;
    void set_Omc_Id(const Omc_Id &);
    Omc_Id *release_Omc_Id();
    void set_Omc_Id(Omc_Id *);

    Concurrent_Warning_Message_Indicator *get_Concurrent_Warning_Message_Indicator();
    const Concurrent_Warning_Message_Indicator *get_Concurrent_Warning_Message_Indicator() const;
    void set_Concurrent_Warning_Message_Indicator(const Concurrent_Warning_Message_Indicator &);
    Concurrent_Warning_Message_Indicator *release_Concurrent_Warning_Message_Indicator();
    void set_Concurrent_Warning_Message_Indicator(Concurrent_Warning_Message_Indicator *);

    Send_Write_Replace_Warning_Indication *get_Send_Write_Replace_Warning_Indication();
    const Send_Write_Replace_Warning_Indication *get_Send_Write_Replace_Warning_Indication() const;
    void set_Send_Write_Replace_Warning_Indication(const Send_Write_Replace_Warning_Indication &);
    Send_Write_Replace_Warning_Indication *release_Send_Write_Replace_Warning_Indication();
    void set_Send_Write_Replace_Warning_Indication(Send_Write_Replace_Warning_Indication *);

    Global_ENB_ID *get_Global_ENB_ID();
    const Global_ENB_ID *get_Global_ENB_ID() const;
    void set_Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID *release_Global_ENB_ID();
    void set_Global_ENB_ID(Global_ENB_ID *);
private:
    void cleanup_decoded();
};

typedef OSS_UINT32 ProtocolExtensionID;

class OSS_PUBLIC TAI_5GS;

class OSS_PUBLIC __shared7 : public OssList  /* SEQUENCE OF */
{
public:
    typedef TAI_5GS component;

    __shared7();
    __shared7(const __shared7 &);
    ~__shared7();

    __shared7 & operator = (const __shared7 &);
    int operator == (const __shared7 &) const;
    int operator != (const __shared7 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared7 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared7 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared7 *extract_after(OssIndex, OssIndex);
};

typedef __shared7 List_of_5GS_TAIs;

class OSS_PUBLIC NR_CGI;

class OSS_PUBLIC __shared8 : public OssList  /* SEQUENCE OF */
{
public:
    typedef NR_CGI component;

    __shared8();
    __shared8(const __shared8 &);
    ~__shared8();

    __shared8 & operator = (const __shared8 &);
    int operator == (const __shared8 &) const;
    int operator != (const __shared8 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared8 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared8 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared8 *extract_after(OssIndex, OssIndex);
};

typedef __shared8 NR_CGIList;

class OSS_PUBLIC TAI_5GS   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssString tAC_5GS;
    typedef __shared2 iE_Extensions;

    TAI_5GS();
    TAI_5GS(const TAI_5GS &);
    TAI_5GS(const pLMNidentity &, const tAC_5GS &, const iE_Extensions &);
    TAI_5GS(const pLMNidentity &, const tAC_5GS &);

    TAI_5GS & operator = (const TAI_5GS &);
    int operator == (const TAI_5GS &) const;
    int operator != (const TAI_5GS &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    tAC_5GS & get_tAC_5GS();
    const tAC_5GS & get_tAC_5GS() const;
    void set_tAC_5GS(const tAC_5GS &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    tAC_5GS tAC_5GS_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Warning_Area_List_5GS  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	cell_ID_List_chosen = 1,
	nR_CGIList_chosen = 2,
	tAIList_5GS_chosen = 3,
	emergencyAreaIDList_chosen = 4
    };
    typedef __shared4 cell_ID_List;
    typedef __shared8 nR_CGIList;
    typedef TAI_5GS tAIList_5GS;
    typedef __shared6 emergencyAreaIDList;

    Warning_Area_List_5GS();
    Warning_Area_List_5GS(const Warning_Area_List_5GS &);
    ~Warning_Area_List_5GS();

    Warning_Area_List_5GS & operator = (const Warning_Area_List_5GS &);
    int operator == (const Warning_Area_List_5GS &) const;
    int operator != (const Warning_Area_List_5GS &) const;

    cell_ID_List *get_cell_ID_List();
    const cell_ID_List *get_cell_ID_List() const;
    void set_cell_ID_List(const cell_ID_List &);

    nR_CGIList *get_nR_CGIList();
    const nR_CGIList *get_nR_CGIList() const;
    void set_nR_CGIList(const nR_CGIList &);

    tAIList_5GS *get_tAIList_5GS();
    const tAIList_5GS *get_tAIList_5GS() const;
    void set_tAIList_5GS(const tAIList_5GS &);

    emergencyAreaIDList *get_emergencyAreaIDList();
    const emergencyAreaIDList *get_emergencyAreaIDList() const;
    void set_emergencyAreaIDList(const emergencyAreaIDList &);
private:
    union {
	void *cell_ID_List_field;
	void *nR_CGIList_field;
	tAIList_5GS *tAIList_5GS_field;
	void *emergencyAreaIDList_field;
    };
    void cleanup();
};

class OSS_PUBLIC GNB_ID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	gNB_ID_chosen = 1
    };
    typedef OssBitString gNB_ID;

    GNB_ID();
    GNB_ID(const GNB_ID &);
    ~GNB_ID();

    GNB_ID & operator = (const GNB_ID &);
    int operator == (const GNB_ID &) const;
    int operator != (const GNB_ID &) const;

    gNB_ID *get_gNB_ID();
    const gNB_ID *get_gNB_ID() const;
    void set_gNB_ID(const gNB_ID &);
private:
    union {
	OSSC::COssBitString gNB_ID_field;
    };
    void cleanup();
};

class OSS_PUBLIC Global_GNB_ID   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef GNB_ID gNB_ID;
    typedef __shared2 iE_Extensions;

    Global_GNB_ID();
    Global_GNB_ID(const Global_GNB_ID &);
    Global_GNB_ID(const pLMNidentity &, const gNB_ID &, const iE_Extensions &);
    Global_GNB_ID(const pLMNidentity &, const gNB_ID &);

    Global_GNB_ID & operator = (const Global_GNB_ID &);
    int operator == (const Global_GNB_ID &) const;
    int operator != (const Global_GNB_ID &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    gNB_ID & get_gNB_ID();
    const gNB_ID & get_gNB_ID() const;
    void set_gNB_ID(const gNB_ID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    gNB_ID gNB_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Global_NgENB_ID   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef ENB_ID ngENB_ID;
    typedef __shared2 iE_Extensions;

    Global_NgENB_ID();
    Global_NgENB_ID(const Global_NgENB_ID &);
    Global_NgENB_ID(const pLMNidentity &, const ngENB_ID &, const iE_Extensions &);
    Global_NgENB_ID(const pLMNidentity &, const ngENB_ID &);

    Global_NgENB_ID & operator = (const Global_NgENB_ID &);
    int operator == (const Global_NgENB_ID &) const;
    int operator != (const Global_NgENB_ID &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    ngENB_ID & get_ngENB_ID();
    const ngENB_ID & get_ngENB_ID() const;
    void set_ngENB_ID(const ngENB_ID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    ngENB_ID ngENB_ID_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Global_RAN_Node_ID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	global_GNB_ID_chosen = 1,
	global_NgENB_ID_chosen = 2
    };
    typedef Global_GNB_ID global_GNB_ID;
    typedef Global_NgENB_ID global_NgENB_ID;

    Global_RAN_Node_ID();
    Global_RAN_Node_ID(const Global_RAN_Node_ID &);
    ~Global_RAN_Node_ID();

    Global_RAN_Node_ID & operator = (const Global_RAN_Node_ID &);
    int operator == (const Global_RAN_Node_ID &) const;
    int operator != (const Global_RAN_Node_ID &) const;

    global_GNB_ID *get_global_GNB_ID();
    const global_GNB_ID *get_global_GNB_ID() const;
    void set_global_GNB_ID(const global_GNB_ID &);

    global_NgENB_ID *get_global_NgENB_ID();
    const global_NgENB_ID *get_global_NgENB_ID() const;
    void set_global_NgENB_ID(const global_NgENB_ID &);
private:
    union {
	global_GNB_ID *global_GNB_ID_field;
	global_NgENB_ID *global_NgENB_ID_field;
    };
    void cleanup();
};

class OSS_PUBLIC Write_Replace_Warning_Request_Extensions_Extension : public OssConstrainedOpenType
{
public:
    Write_Replace_Warning_Request_Extensions_Extension();
    Write_Replace_Warning_Request_Extensions_Extension(const Write_Replace_Warning_Request_Extensions_Extension &);
    ~Write_Replace_Warning_Request_Extensions_Extension();
    Write_Replace_Warning_Request_Extensions_Extension & operator = (const Write_Replace_Warning_Request_Extensions_Extension &);
    int operator == (const Write_Replace_Warning_Request_Extensions_Extension &) const;
    int operator != (const Write_Replace_Warning_Request_Extensions_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared7 *get_List_of_5GS_TAIs();
    const __shared7 *get_List_of_5GS_TAIs() const;
    void set_List_of_5GS_TAIs(const __shared7 &);
    __shared7 *release_List_of_5GS_TAIs();
    void set_List_of_5GS_TAIs(__shared7 *);

    Warning_Area_List_5GS *get_Warning_Area_List_5GS();
    const Warning_Area_List_5GS *get_Warning_Area_List_5GS() const;
    void set_Warning_Area_List_5GS(const Warning_Area_List_5GS &);
    Warning_Area_List_5GS *release_Warning_Area_List_5GS();
    void set_Warning_Area_List_5GS(Warning_Area_List_5GS *);

    Global_RAN_Node_ID *get_Global_RAN_Node_ID();
    const Global_RAN_Node_ID *get_Global_RAN_Node_ID() const;
    void set_Global_RAN_Node_ID(const Global_RAN_Node_ID &);
    Global_RAN_Node_ID *release_Global_RAN_Node_ID();
    void set_Global_RAN_Node_ID(Global_RAN_Node_ID *);

    RAT_Selector_5GS *get_RAT_Selector_5GS();
    const RAT_Selector_5GS *get_RAT_Selector_5GS() const;
    void set_RAT_Selector_5GS(const RAT_Selector_5GS &);
    RAT_Selector_5GS *release_RAT_Selector_5GS();
    void set_RAT_Selector_5GS(RAT_Selector_5GS *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq1   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Write_Replace_Warning_Request_IEs_Value value;

    __seq1();
    __seq1(const __seq1 &);
    __seq1(id, criticality, const value &);

    __seq1 & operator = (const __seq1 &);
    int operator == (const __seq1 &) const;
    int operator != (const __seq1 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq2   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Write_Replace_Warning_Request_Extensions_Extension extensionValue;

    __seq2();
    __seq2(const __seq2 &);
    __seq2(id, criticality, const extensionValue &);

    __seq2 & operator = (const __seq2 &);
    int operator == (const __seq2 &) const;
    int operator != (const __seq2 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC __seq37;

class OSS_PUBLIC __shared9 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq37 component;

    __shared9();
    __shared9(const __shared9 &);
    ~__shared9();

    __shared9 & operator = (const __shared9 &);
    int operator == (const __shared9 &) const;
    int operator != (const __shared9 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared9 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared9 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared9 *extract_after(OssIndex, OssIndex);
};

typedef __shared9 CriticalityDiagnostics_IE_List;

class OSS_PUBLIC Criticality_Diagnostics   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 procedureCode;
    typedef enum TriggeringMessage triggeringMessage;
    typedef enum Criticality procedureCriticality;
    typedef __shared9 iE_CriticalityDiagnostics;
    typedef __shared2 iE_Extensions;

    Criticality_Diagnostics();
    Criticality_Diagnostics(const Criticality_Diagnostics &);
    Criticality_Diagnostics(procedureCode, triggeringMessage, procedureCriticality, 
	const iE_CriticalityDiagnostics &, const iE_Extensions &);

    Criticality_Diagnostics & operator = (const Criticality_Diagnostics &);
    int operator == (const Criticality_Diagnostics &) const;
    int operator != (const Criticality_Diagnostics &) const;

    procedureCode *get_procedureCode();
    const procedureCode *get_procedureCode() const;
    void set_procedureCode(procedureCode);
    int procedureCode_is_present() const;
    void omit_procedureCode();

    triggeringMessage *get_triggeringMessage();
    const triggeringMessage *get_triggeringMessage() const;
    void set_triggeringMessage(triggeringMessage);
    int triggeringMessage_is_present() const;
    void omit_triggeringMessage();

    procedureCriticality *get_procedureCriticality();
    const procedureCriticality *get_procedureCriticality() const;
    void set_procedureCriticality(procedureCriticality);
    int procedureCriticality_is_present() const;
    void omit_procedureCriticality();

    iE_CriticalityDiagnostics *get_iE_CriticalityDiagnostics();
    const iE_CriticalityDiagnostics *get_iE_CriticalityDiagnostics() const;
    void set_iE_CriticalityDiagnostics(const iE_CriticalityDiagnostics &);
    int iE_CriticalityDiagnostics_is_present() const;
    void omit_iE_CriticalityDiagnostics();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    procedureCode procedureCode_field;
    triggeringMessage triggeringMessage_field;
    procedureCriticality procedureCriticality_field;
    iE_CriticalityDiagnostics iE_CriticalityDiagnostics_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Write_Replace_Warning_Response_IEs_Value : public OssConstrainedOpenType
{
public:
    Write_Replace_Warning_Response_IEs_Value();
    Write_Replace_Warning_Response_IEs_Value(const Write_Replace_Warning_Response_IEs_Value &);
    ~Write_Replace_Warning_Response_IEs_Value();
    Write_Replace_Warning_Response_IEs_Value & operator = (const Write_Replace_Warning_Response_IEs_Value &);
    int operator == (const Write_Replace_Warning_Response_IEs_Value &) const;
    int operator != (const Write_Replace_Warning_Response_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Message_Identifier *get_Message_Identifier();
    const Message_Identifier *get_Message_Identifier() const;
    void set_Message_Identifier(const Message_Identifier &);
    Message_Identifier *release_Message_Identifier();
    void set_Message_Identifier(Message_Identifier *);

    Serial_Number *get_Serial_Number();
    const Serial_Number *get_Serial_Number() const;
    void set_Serial_Number(const Serial_Number &);
    Serial_Number *release_Serial_Number();
    void set_Serial_Number(Serial_Number *);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    Criticality_Diagnostics *get_Criticality_Diagnostics();
    const Criticality_Diagnostics *get_Criticality_Diagnostics() const;
    void set_Criticality_Diagnostics(const Criticality_Diagnostics &);
    Criticality_Diagnostics *release_Criticality_Diagnostics();
    void set_Criticality_Diagnostics(Criticality_Diagnostics *);

    __shared3 *get_List_of_TAIs();
    const __shared3 *get_List_of_TAIs() const;
    void set_List_of_TAIs(const __shared3 &);
    __shared3 *release_List_of_TAIs();
    void set_List_of_TAIs(__shared3 *);
private:
    void cleanup_decoded();
};

typedef __shared7 Unknown_5GS_Tracking_Area_List;

class OSS_PUBLIC Write_Replace_Warning_Response_Extensions_Extension : public OssConstrainedOpenType
{
public:
    Write_Replace_Warning_Response_Extensions_Extension();
    Write_Replace_Warning_Response_Extensions_Extension(const Write_Replace_Warning_Response_Extensions_Extension &);
    ~Write_Replace_Warning_Response_Extensions_Extension();
    Write_Replace_Warning_Response_Extensions_Extension & operator = (const Write_Replace_Warning_Response_Extensions_Extension &);
    int operator == (const Write_Replace_Warning_Response_Extensions_Extension &) const;
    int operator != (const Write_Replace_Warning_Response_Extensions_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared7 *get_Unknown_5GS_Tracking_Area_List();
    const __shared7 *get_Unknown_5GS_Tracking_Area_List() const;
    void set_Unknown_5GS_Tracking_Area_List(const __shared7 &);
    __shared7 *release_Unknown_5GS_Tracking_Area_List();
    void set_Unknown_5GS_Tracking_Area_List(__shared7 *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared24   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Write_Replace_Warning_Response_IEs_Value value;

    __shared24();
    __shared24(const __shared24 &);
    __shared24(id, criticality, const value &);

    __shared24 & operator = (const __shared24 &);
    int operator == (const __shared24 &) const;
    int operator != (const __shared24 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared26   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Write_Replace_Warning_Response_Extensions_Extension extensionValue;

    __shared26();
    __shared26(const __shared26 &);
    __shared26(id, criticality, const extensionValue &);

    __shared26 & operator = (const __shared26 &);
    int operator == (const __shared26 &) const;
    int operator != (const __shared26 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC Stop_Warning_Request_IEs_Value : public OssConstrainedOpenType
{
public:
    Stop_Warning_Request_IEs_Value();
    Stop_Warning_Request_IEs_Value(const Stop_Warning_Request_IEs_Value &);
    ~Stop_Warning_Request_IEs_Value();
    Stop_Warning_Request_IEs_Value & operator = (const Stop_Warning_Request_IEs_Value &);
    int operator == (const Stop_Warning_Request_IEs_Value &) const;
    int operator != (const Stop_Warning_Request_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Message_Identifier *get_Message_Identifier();
    const Message_Identifier *get_Message_Identifier() const;
    void set_Message_Identifier(const Message_Identifier &);
    Message_Identifier *release_Message_Identifier();
    void set_Message_Identifier(Message_Identifier *);

    Serial_Number *get_Serial_Number();
    const Serial_Number *get_Serial_Number() const;
    void set_Serial_Number(const Serial_Number &);
    Serial_Number *release_Serial_Number();
    void set_Serial_Number(Serial_Number *);

    __shared3 *get_List_of_TAIs();
    const __shared3 *get_List_of_TAIs() const;
    void set_List_of_TAIs(const __shared3 &);
    __shared3 *release_List_of_TAIs();
    void set_List_of_TAIs(__shared3 *);

    Warning_Area_List *get_Warning_Area_List();
    const Warning_Area_List *get_Warning_Area_List() const;
    void set_Warning_Area_List(const Warning_Area_List &);
    Warning_Area_List *release_Warning_Area_List();
    void set_Warning_Area_List(Warning_Area_List *);

    Omc_Id *get_Omc_Id();
    const Omc_Id *get_Omc_Id() const;
    void set_Omc_Id(const Omc_Id &);
    Omc_Id *release_Omc_Id();
    void set_Omc_Id(Omc_Id *);

    Send_Stop_Warning_Indication *get_Send_Stop_Warning_Indication();
    const Send_Stop_Warning_Indication *get_Send_Stop_Warning_Indication() const;
    void set_Send_Stop_Warning_Indication(const Send_Stop_Warning_Indication &);
    Send_Stop_Warning_Indication *release_Send_Stop_Warning_Indication();
    void set_Send_Stop_Warning_Indication(Send_Stop_Warning_Indication *);

    Stop_All_Indicator *get_Stop_All_Indicator();
    const Stop_All_Indicator *get_Stop_All_Indicator() const;
    void set_Stop_All_Indicator(const Stop_All_Indicator &);
    Stop_All_Indicator *release_Stop_All_Indicator();
    void set_Stop_All_Indicator(Stop_All_Indicator *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC Stop_Warning_Request_Extensions_Extension : public OssConstrainedOpenType
{
public:
    Stop_Warning_Request_Extensions_Extension();
    Stop_Warning_Request_Extensions_Extension(const Stop_Warning_Request_Extensions_Extension &);
    ~Stop_Warning_Request_Extensions_Extension();
    Stop_Warning_Request_Extensions_Extension & operator = (const Stop_Warning_Request_Extensions_Extension &);
    int operator == (const Stop_Warning_Request_Extensions_Extension &) const;
    int operator != (const Stop_Warning_Request_Extensions_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared7 *get_List_of_5GS_TAIs();
    const __shared7 *get_List_of_5GS_TAIs() const;
    void set_List_of_5GS_TAIs(const __shared7 &);
    __shared7 *release_List_of_5GS_TAIs();
    void set_List_of_5GS_TAIs(__shared7 *);

    Warning_Area_List_5GS *get_Warning_Area_List_5GS();
    const Warning_Area_List_5GS *get_Warning_Area_List_5GS() const;
    void set_Warning_Area_List_5GS(const Warning_Area_List_5GS &);
    Warning_Area_List_5GS *release_Warning_Area_List_5GS();
    void set_Warning_Area_List_5GS(Warning_Area_List_5GS *);

    RAT_Selector_5GS *get_RAT_Selector_5GS();
    const RAT_Selector_5GS *get_RAT_Selector_5GS() const;
    void set_RAT_Selector_5GS(const RAT_Selector_5GS &);
    RAT_Selector_5GS *release_RAT_Selector_5GS();
    void set_RAT_Selector_5GS(RAT_Selector_5GS *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq5   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Stop_Warning_Request_IEs_Value value;

    __seq5();
    __seq5(const __seq5 &);
    __seq5(id, criticality, const value &);

    __seq5 & operator = (const __seq5 &);
    int operator == (const __seq5 &) const;
    int operator != (const __seq5 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq6   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Stop_Warning_Request_Extensions_Extension extensionValue;

    __seq6();
    __seq6(const __seq6 &);
    __seq6(id, criticality, const extensionValue &);

    __seq6 & operator = (const __seq6 &);
    int operator == (const __seq6 &) const;
    int operator != (const __seq6 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC __shared10;

class OSS_PUBLIC __shared11 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared10 component;

    __shared11();
    __shared11(const __shared11 &);
    ~__shared11();

    __shared11 & operator = (const __shared11 &);
    int operator == (const __shared11 &) const;
    int operator != (const __shared11 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared11 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared11 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared11 *extract_after(OssIndex, OssIndex);
};

typedef __shared11 CellId_Broadcast_List;

class OSS_PUBLIC TAI_Broadcast_List_Item;

class OSS_PUBLIC __shared12 : public OssList  /* SEQUENCE OF */
{
public:
    typedef TAI_Broadcast_List_Item component;

    __shared12();
    __shared12(const __shared12 &);
    ~__shared12();

    __shared12 & operator = (const __shared12 &);
    int operator == (const __shared12 &) const;
    int operator != (const __shared12 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared12 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared12 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared12 *extract_after(OssIndex, OssIndex);
};

typedef __shared12 TAI_Broadcast_List;

class OSS_PUBLIC EmergencyAreaID_Broadcast_List_Item;

class OSS_PUBLIC __shared13 : public OssList  /* SEQUENCE OF */
{
public:
    typedef EmergencyAreaID_Broadcast_List_Item component;

    __shared13();
    __shared13(const __shared13 &);
    ~__shared13();

    __shared13 & operator = (const __shared13 &);
    int operator == (const __shared13 &) const;
    int operator != (const __shared13 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared13 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared13 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared13 *extract_after(OssIndex, OssIndex);
};

typedef __shared13 EmergencyAreaID_Broadcast_List;

class OSS_PUBLIC Broadcast_Scheduled_Area_List   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared11 cellId_Broadcast_List;
    typedef __shared12 tAI_Broadcast_List;
    typedef __shared13 emergencyAreaID_Broadcast_List;
    typedef __shared2 iE_Extensions;

    Broadcast_Scheduled_Area_List();
    Broadcast_Scheduled_Area_List(const Broadcast_Scheduled_Area_List &);
    Broadcast_Scheduled_Area_List(const cellId_Broadcast_List &, const tAI_Broadcast_List &, 
	const emergencyAreaID_Broadcast_List &, const iE_Extensions &);

    Broadcast_Scheduled_Area_List & operator = (const Broadcast_Scheduled_Area_List &);
    int operator == (const Broadcast_Scheduled_Area_List &) const;
    int operator != (const Broadcast_Scheduled_Area_List &) const;

    cellId_Broadcast_List *get_cellId_Broadcast_List();
    const cellId_Broadcast_List *get_cellId_Broadcast_List() const;
    void set_cellId_Broadcast_List(const cellId_Broadcast_List &);
    int cellId_Broadcast_List_is_present() const;
    void omit_cellId_Broadcast_List();

    tAI_Broadcast_List *get_tAI_Broadcast_List();
    const tAI_Broadcast_List *get_tAI_Broadcast_List() const;
    void set_tAI_Broadcast_List(const tAI_Broadcast_List &);
    int tAI_Broadcast_List_is_present() const;
    void omit_tAI_Broadcast_List();

    emergencyAreaID_Broadcast_List *get_emergencyAreaID_Broadcast_List();
    const emergencyAreaID_Broadcast_List *get_emergencyAreaID_Broadcast_List() const;
    void set_emergencyAreaID_Broadcast_List(const emergencyAreaID_Broadcast_List &);
    int emergencyAreaID_Broadcast_List_is_present() const;
    void omit_emergencyAreaID_Broadcast_List();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cellId_Broadcast_List cellId_Broadcast_List_field;
    tAI_Broadcast_List tAI_Broadcast_List_field;
    emergencyAreaID_Broadcast_List emergencyAreaID_Broadcast_List_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Write_Replace_Warning_Indication_IEs_Value : public OssConstrainedOpenType
{
public:
    Write_Replace_Warning_Indication_IEs_Value();
    Write_Replace_Warning_Indication_IEs_Value(const Write_Replace_Warning_Indication_IEs_Value &);
    ~Write_Replace_Warning_Indication_IEs_Value();
    Write_Replace_Warning_Indication_IEs_Value & operator = (const Write_Replace_Warning_Indication_IEs_Value &);
    int operator == (const Write_Replace_Warning_Indication_IEs_Value &) const;
    int operator != (const Write_Replace_Warning_Indication_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Message_Identifier *get_Message_Identifier();
    const Message_Identifier *get_Message_Identifier() const;
    void set_Message_Identifier(const Message_Identifier &);
    Message_Identifier *release_Message_Identifier();
    void set_Message_Identifier(Message_Identifier *);

    Serial_Number *get_Serial_Number();
    const Serial_Number *get_Serial_Number() const;
    void set_Serial_Number(const Serial_Number &);
    Serial_Number *release_Serial_Number();
    void set_Serial_Number(Serial_Number *);

    Broadcast_Scheduled_Area_List *get_Broadcast_Scheduled_Area_List();
    const Broadcast_Scheduled_Area_List *get_Broadcast_Scheduled_Area_List() const;
    void set_Broadcast_Scheduled_Area_List(const Broadcast_Scheduled_Area_List &);
    Broadcast_Scheduled_Area_List *release_Broadcast_Scheduled_Area_List();
    void set_Broadcast_Scheduled_Area_List(Broadcast_Scheduled_Area_List *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared14;

class OSS_PUBLIC __shared15 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared14 component;

    __shared15();
    __shared15(const __shared15 &);
    ~__shared15();

    __shared15 & operator = (const __shared15 &);
    int operator == (const __shared15 &) const;
    int operator != (const __shared15 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared15 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared15 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared15 *extract_after(OssIndex, OssIndex);
};

typedef __shared15 CellId_Broadcast_List_5GS;

class OSS_PUBLIC __seq51;

class OSS_PUBLIC __shared16 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq51 component;

    __shared16();
    __shared16(const __shared16 &);
    ~__shared16();

    __shared16 & operator = (const __shared16 &);
    int operator == (const __shared16 &) const;
    int operator != (const __shared16 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared16 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared16 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared16 *extract_after(OssIndex, OssIndex);
};

typedef __shared16 TAI_Broadcast_List_5GS;

class OSS_PUBLIC Broadcast_Scheduled_Area_List_5GS   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared15 cellId_Broadcast_List_5GS;
    typedef __shared16 tAI_Broadcast_List_5GS;
    typedef __shared13 emergencyAreaID_Broadcast_List;
    typedef __shared2 iE_Extensions;

    Broadcast_Scheduled_Area_List_5GS();
    Broadcast_Scheduled_Area_List_5GS(const Broadcast_Scheduled_Area_List_5GS &);
    Broadcast_Scheduled_Area_List_5GS(const cellId_Broadcast_List_5GS &, const tAI_Broadcast_List_5GS &, 
	const emergencyAreaID_Broadcast_List &, const iE_Extensions &);

    Broadcast_Scheduled_Area_List_5GS & operator = (const Broadcast_Scheduled_Area_List_5GS &);
    int operator == (const Broadcast_Scheduled_Area_List_5GS &) const;
    int operator != (const Broadcast_Scheduled_Area_List_5GS &) const;

    cellId_Broadcast_List_5GS *get_cellId_Broadcast_List_5GS();
    const cellId_Broadcast_List_5GS *get_cellId_Broadcast_List_5GS() const;
    void set_cellId_Broadcast_List_5GS(const cellId_Broadcast_List_5GS &);
    int cellId_Broadcast_List_5GS_is_present() const;
    void omit_cellId_Broadcast_List_5GS();

    tAI_Broadcast_List_5GS *get_tAI_Broadcast_List_5GS();
    const tAI_Broadcast_List_5GS *get_tAI_Broadcast_List_5GS() const;
    void set_tAI_Broadcast_List_5GS(const tAI_Broadcast_List_5GS &);
    int tAI_Broadcast_List_5GS_is_present() const;
    void omit_tAI_Broadcast_List_5GS();

    emergencyAreaID_Broadcast_List *get_emergencyAreaID_Broadcast_List();
    const emergencyAreaID_Broadcast_List *get_emergencyAreaID_Broadcast_List() const;
    void set_emergencyAreaID_Broadcast_List(const emergencyAreaID_Broadcast_List &);
    int emergencyAreaID_Broadcast_List_is_present() const;
    void omit_emergencyAreaID_Broadcast_List();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cellId_Broadcast_List_5GS cellId_Broadcast_List_5GS_field;
    tAI_Broadcast_List_5GS tAI_Broadcast_List_5GS_field;
    emergencyAreaID_Broadcast_List emergencyAreaID_Broadcast_List_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Write_Replace_Warning_Indication_Extensions_Extension : public OssConstrainedOpenType
{
public:
    Write_Replace_Warning_Indication_Extensions_Extension();
    Write_Replace_Warning_Indication_Extensions_Extension(const Write_Replace_Warning_Indication_Extensions_Extension &);
    ~Write_Replace_Warning_Indication_Extensions_Extension();
    Write_Replace_Warning_Indication_Extensions_Extension & operator = (const Write_Replace_Warning_Indication_Extensions_Extension &);
    int operator == (const Write_Replace_Warning_Indication_Extensions_Extension &) const;
    int operator != (const Write_Replace_Warning_Indication_Extensions_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Broadcast_Scheduled_Area_List_5GS *get_Broadcast_Scheduled_Area_List_5GS();
    const Broadcast_Scheduled_Area_List_5GS *get_Broadcast_Scheduled_Area_List_5GS() const;
    void set_Broadcast_Scheduled_Area_List_5GS(const Broadcast_Scheduled_Area_List_5GS &);
    Broadcast_Scheduled_Area_List_5GS *release_Broadcast_Scheduled_Area_List_5GS();
    void set_Broadcast_Scheduled_Area_List_5GS(Broadcast_Scheduled_Area_List_5GS *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq9   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Write_Replace_Warning_Indication_IEs_Value value;

    __seq9();
    __seq9(const __seq9 &);
    __seq9(id, criticality, const value &);

    __seq9 & operator = (const __seq9 &);
    int operator == (const __seq9 &) const;
    int operator != (const __seq9 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq10   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Write_Replace_Warning_Indication_Extensions_Extension extensionValue;

    __seq10();
    __seq10(const __seq10 &);
    __seq10(id, criticality, const extensionValue &);

    __seq10 & operator = (const __seq10 &);
    int operator == (const __seq10 &) const;
    int operator != (const __seq10 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC __shared17;

class OSS_PUBLIC __shared18 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared17 component;

    __shared18();
    __shared18(const __shared18 &);
    ~__shared18();

    __shared18 & operator = (const __shared18 &);
    int operator == (const __shared18 &) const;
    int operator != (const __shared18 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared18 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared18 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared18 *extract_after(OssIndex, OssIndex);
};

typedef __shared18 CellID_Cancelled_List;

class OSS_PUBLIC TAI_Cancelled_List_Item;

class OSS_PUBLIC __shared19 : public OssList  /* SEQUENCE OF */
{
public:
    typedef TAI_Cancelled_List_Item component;

    __shared19();
    __shared19(const __shared19 &);
    ~__shared19();

    __shared19 & operator = (const __shared19 &);
    int operator == (const __shared19 &) const;
    int operator != (const __shared19 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared19 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared19 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared19 *extract_after(OssIndex, OssIndex);
};

typedef __shared19 TAI_Cancelled_List;

class OSS_PUBLIC EmergencyAreaID_Cancelled_Item;

class OSS_PUBLIC __shared20 : public OssList  /* SEQUENCE OF */
{
public:
    typedef EmergencyAreaID_Cancelled_Item component;

    __shared20();
    __shared20(const __shared20 &);
    ~__shared20();

    __shared20 & operator = (const __shared20 &);
    int operator == (const __shared20 &) const;
    int operator != (const __shared20 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared20 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared20 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared20 *extract_after(OssIndex, OssIndex);
};

typedef __shared20 EmergencyAreaID_Cancelled_List;

class OSS_PUBLIC Broadcast_Cancelled_Area_List   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared18 cellID_Cancelled_List;
    typedef __shared19 tAI_Cancelled_List;
    typedef __shared20 emergencyAreaID_Cancelled_List;
    typedef __shared2 iE_Extensions;

    Broadcast_Cancelled_Area_List();
    Broadcast_Cancelled_Area_List(const Broadcast_Cancelled_Area_List &);
    Broadcast_Cancelled_Area_List(const cellID_Cancelled_List &, const tAI_Cancelled_List &, 
	const emergencyAreaID_Cancelled_List &, const iE_Extensions &);

    Broadcast_Cancelled_Area_List & operator = (const Broadcast_Cancelled_Area_List &);
    int operator == (const Broadcast_Cancelled_Area_List &) const;
    int operator != (const Broadcast_Cancelled_Area_List &) const;

    cellID_Cancelled_List *get_cellID_Cancelled_List();
    const cellID_Cancelled_List *get_cellID_Cancelled_List() const;
    void set_cellID_Cancelled_List(const cellID_Cancelled_List &);
    int cellID_Cancelled_List_is_present() const;
    void omit_cellID_Cancelled_List();

    tAI_Cancelled_List *get_tAI_Cancelled_List();
    const tAI_Cancelled_List *get_tAI_Cancelled_List() const;
    void set_tAI_Cancelled_List(const tAI_Cancelled_List &);
    int tAI_Cancelled_List_is_present() const;
    void omit_tAI_Cancelled_List();

    emergencyAreaID_Cancelled_List *get_emergencyAreaID_Cancelled_List();
    const emergencyAreaID_Cancelled_List *get_emergencyAreaID_Cancelled_List() const;
    void set_emergencyAreaID_Cancelled_List(const emergencyAreaID_Cancelled_List &);
    int emergencyAreaID_Cancelled_List_is_present() const;
    void omit_emergencyAreaID_Cancelled_List();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cellID_Cancelled_List cellID_Cancelled_List_field;
    tAI_Cancelled_List tAI_Cancelled_List_field;
    emergencyAreaID_Cancelled_List emergencyAreaID_Cancelled_List_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Broadcast_Empty_Area_List : public OssList  /* SEQUENCE OF */
{
public:
    typedef Global_ENB_ID component;

    Broadcast_Empty_Area_List();
    Broadcast_Empty_Area_List(const Broadcast_Empty_Area_List &);
    ~Broadcast_Empty_Area_List();

    Broadcast_Empty_Area_List & operator = (const Broadcast_Empty_Area_List &);
    int operator == (const Broadcast_Empty_Area_List &) const;
    int operator != (const Broadcast_Empty_Area_List &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(Broadcast_Empty_Area_List *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, Broadcast_Empty_Area_List *);

    int remove_front();
    int remove_after(OssIndex);

    Broadcast_Empty_Area_List *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Stop_Warning_Indication_IEs_Value : public OssConstrainedOpenType
{
public:
    Stop_Warning_Indication_IEs_Value();
    Stop_Warning_Indication_IEs_Value(const Stop_Warning_Indication_IEs_Value &);
    ~Stop_Warning_Indication_IEs_Value();
    Stop_Warning_Indication_IEs_Value & operator = (const Stop_Warning_Indication_IEs_Value &);
    int operator == (const Stop_Warning_Indication_IEs_Value &) const;
    int operator != (const Stop_Warning_Indication_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Message_Identifier *get_Message_Identifier();
    const Message_Identifier *get_Message_Identifier() const;
    void set_Message_Identifier(const Message_Identifier &);
    Message_Identifier *release_Message_Identifier();
    void set_Message_Identifier(Message_Identifier *);

    Serial_Number *get_Serial_Number();
    const Serial_Number *get_Serial_Number() const;
    void set_Serial_Number(const Serial_Number &);
    Serial_Number *release_Serial_Number();
    void set_Serial_Number(Serial_Number *);

    Broadcast_Cancelled_Area_List *get_Broadcast_Cancelled_Area_List();
    const Broadcast_Cancelled_Area_List *get_Broadcast_Cancelled_Area_List() const;
    void set_Broadcast_Cancelled_Area_List(const Broadcast_Cancelled_Area_List &);
    Broadcast_Cancelled_Area_List *release_Broadcast_Cancelled_Area_List();
    void set_Broadcast_Cancelled_Area_List(Broadcast_Cancelled_Area_List *);

    Broadcast_Empty_Area_List *get_Broadcast_Empty_Area_List();
    const Broadcast_Empty_Area_List *get_Broadcast_Empty_Area_List() const;
    void set_Broadcast_Empty_Area_List(const Broadcast_Empty_Area_List &);
    Broadcast_Empty_Area_List *release_Broadcast_Empty_Area_List();
    void set_Broadcast_Empty_Area_List(Broadcast_Empty_Area_List *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __shared21;

class OSS_PUBLIC __shared22 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __shared21 component;

    __shared22();
    __shared22(const __shared22 &);
    ~__shared22();

    __shared22 & operator = (const __shared22 &);
    int operator == (const __shared22 &) const;
    int operator != (const __shared22 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared22 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared22 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared22 *extract_after(OssIndex, OssIndex);
};

typedef __shared22 CellID_Cancelled_List_5GS;

class OSS_PUBLIC __seq54;

class OSS_PUBLIC __shared23 : public OssList  /* SEQUENCE OF */
{
public:
    typedef __seq54 component;

    __shared23();
    __shared23(const __shared23 &);
    ~__shared23();

    __shared23 & operator = (const __shared23 &);
    int operator == (const __shared23 &) const;
    int operator != (const __shared23 &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(__shared23 *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, __shared23 *);

    int remove_front();
    int remove_after(OssIndex);

    __shared23 *extract_after(OssIndex, OssIndex);
};

typedef __shared23 TAI_Cancelled_List_5GS;

class OSS_PUBLIC Broadcast_Cancelled_Area_List_5GS   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared22 cellID_Cancelled_List_5GS;
    typedef __shared23 tAI_Cancelled_List_5GS;
    typedef __shared20 emergencyAreaID_Cancelled_List;
    typedef __shared2 iE_Extensions;

    Broadcast_Cancelled_Area_List_5GS();
    Broadcast_Cancelled_Area_List_5GS(const Broadcast_Cancelled_Area_List_5GS &);
    Broadcast_Cancelled_Area_List_5GS(const cellID_Cancelled_List_5GS &, const tAI_Cancelled_List_5GS &, 
	const emergencyAreaID_Cancelled_List &, const iE_Extensions &);

    Broadcast_Cancelled_Area_List_5GS & operator = (const Broadcast_Cancelled_Area_List_5GS &);
    int operator == (const Broadcast_Cancelled_Area_List_5GS &) const;
    int operator != (const Broadcast_Cancelled_Area_List_5GS &) const;

    cellID_Cancelled_List_5GS *get_cellID_Cancelled_List_5GS();
    const cellID_Cancelled_List_5GS *get_cellID_Cancelled_List_5GS() const;
    void set_cellID_Cancelled_List_5GS(const cellID_Cancelled_List_5GS &);
    int cellID_Cancelled_List_5GS_is_present() const;
    void omit_cellID_Cancelled_List_5GS();

    tAI_Cancelled_List_5GS *get_tAI_Cancelled_List_5GS();
    const tAI_Cancelled_List_5GS *get_tAI_Cancelled_List_5GS() const;
    void set_tAI_Cancelled_List_5GS(const tAI_Cancelled_List_5GS &);
    int tAI_Cancelled_List_5GS_is_present() const;
    void omit_tAI_Cancelled_List_5GS();

    emergencyAreaID_Cancelled_List *get_emergencyAreaID_Cancelled_List();
    const emergencyAreaID_Cancelled_List *get_emergencyAreaID_Cancelled_List() const;
    void set_emergencyAreaID_Cancelled_List(const emergencyAreaID_Cancelled_List &);
    int emergencyAreaID_Cancelled_List_is_present() const;
    void omit_emergencyAreaID_Cancelled_List();

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    cellID_Cancelled_List_5GS cellID_Cancelled_List_5GS_field;
    tAI_Cancelled_List_5GS tAI_Cancelled_List_5GS_field;
    emergencyAreaID_Cancelled_List emergencyAreaID_Cancelled_List_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC Broadcast_Empty_Area_List_5GS : public OssList  /* SEQUENCE OF */
{
public:
    typedef Global_RAN_Node_ID component;

    Broadcast_Empty_Area_List_5GS();
    Broadcast_Empty_Area_List_5GS(const Broadcast_Empty_Area_List_5GS &);
    ~Broadcast_Empty_Area_List_5GS();

    Broadcast_Empty_Area_List_5GS & operator = (const Broadcast_Empty_Area_List_5GS &);
    int operator == (const Broadcast_Empty_Area_List_5GS &) const;
    int operator != (const Broadcast_Empty_Area_List_5GS &) const;

    component *at(OssIndex);
    const component *at(OssIndex) const;

    OssIndex prepend(const component & );
    OssIndex prepend(Broadcast_Empty_Area_List_5GS *);
    OssIndex insert_after(OssIndex, const component & );
    OssIndex insert_after(OssIndex, Broadcast_Empty_Area_List_5GS *);

    int remove_front();
    int remove_after(OssIndex);

    Broadcast_Empty_Area_List_5GS *extract_after(OssIndex, OssIndex);
};

class OSS_PUBLIC Stop_Warning_Indication_Extensions_Extension : public OssConstrainedOpenType
{
public:
    Stop_Warning_Indication_Extensions_Extension();
    Stop_Warning_Indication_Extensions_Extension(const Stop_Warning_Indication_Extensions_Extension &);
    ~Stop_Warning_Indication_Extensions_Extension();
    Stop_Warning_Indication_Extensions_Extension & operator = (const Stop_Warning_Indication_Extensions_Extension &);
    int operator == (const Stop_Warning_Indication_Extensions_Extension &) const;
    int operator != (const Stop_Warning_Indication_Extensions_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Broadcast_Cancelled_Area_List_5GS *get_Broadcast_Cancelled_Area_List_5GS();
    const Broadcast_Cancelled_Area_List_5GS *get_Broadcast_Cancelled_Area_List_5GS() const;
    void set_Broadcast_Cancelled_Area_List_5GS(const Broadcast_Cancelled_Area_List_5GS &);
    Broadcast_Cancelled_Area_List_5GS *release_Broadcast_Cancelled_Area_List_5GS();
    void set_Broadcast_Cancelled_Area_List_5GS(Broadcast_Cancelled_Area_List_5GS *);

    Broadcast_Empty_Area_List_5GS *get_Broadcast_Empty_Area_List_5GS();
    const Broadcast_Empty_Area_List_5GS *get_Broadcast_Empty_Area_List_5GS() const;
    void set_Broadcast_Empty_Area_List_5GS(const Broadcast_Empty_Area_List_5GS &);
    Broadcast_Empty_Area_List_5GS *release_Broadcast_Empty_Area_List_5GS();
    void set_Broadcast_Empty_Area_List_5GS(Broadcast_Empty_Area_List_5GS *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq11   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Stop_Warning_Indication_IEs_Value value;

    __seq11();
    __seq11(const __seq11 &);
    __seq11(id, criticality, const value &);

    __seq11 & operator = (const __seq11 &);
    int operator == (const __seq11 &) const;
    int operator != (const __seq11 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq12   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef Stop_Warning_Indication_Extensions_Extension extensionValue;

    __seq12();
    __seq12(const __seq12 &);
    __seq12(id, criticality, const extensionValue &);

    __seq12 & operator = (const __seq12 &);
    int operator == (const __seq12 &) const;
    int operator != (const __seq12 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef __shared4 Restarted_Cell_List;

typedef __shared3 List_of_TAIs_Restart;

typedef __shared6 List_of_EAIs_Restart;

class OSS_PUBLIC PWS_Restart_Indication_IEs_Value : public OssConstrainedOpenType
{
public:
    PWS_Restart_Indication_IEs_Value();
    PWS_Restart_Indication_IEs_Value(const PWS_Restart_Indication_IEs_Value &);
    ~PWS_Restart_Indication_IEs_Value();
    PWS_Restart_Indication_IEs_Value & operator = (const PWS_Restart_Indication_IEs_Value &);
    int operator == (const PWS_Restart_Indication_IEs_Value &) const;
    int operator != (const PWS_Restart_Indication_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared4 *get_Restarted_Cell_List();
    const __shared4 *get_Restarted_Cell_List() const;
    void set_Restarted_Cell_List(const __shared4 &);
    __shared4 *release_Restarted_Cell_List();
    void set_Restarted_Cell_List(__shared4 *);

    Global_ENB_ID *get_Global_ENB_ID();
    const Global_ENB_ID *get_Global_ENB_ID() const;
    void set_Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID *release_Global_ENB_ID();
    void set_Global_ENB_ID(Global_ENB_ID *);

    __shared3 *get_List_of_TAIs_Restart();
    const __shared3 *get_List_of_TAIs_Restart() const;
    void set_List_of_TAIs_Restart(const __shared3 &);
    __shared3 *release_List_of_TAIs_Restart();
    void set_List_of_TAIs_Restart(__shared3 *);

    __shared6 *get_List_of_EAIs_Restart();
    const __shared6 *get_List_of_EAIs_Restart() const;
    void set_List_of_EAIs_Restart(const __shared6 &);
    __shared6 *release_List_of_EAIs_Restart();
    void set_List_of_EAIs_Restart(__shared6 *);
private:
    void cleanup_decoded();
};

typedef __shared8 Restarted_Cell_List_NR;

typedef __shared7 List_of_5GS_TAI_for_Restart;

class OSS_PUBLIC PWS_Restart_Indication_Extensions_Extension : public OssConstrainedOpenType
{
public:
    PWS_Restart_Indication_Extensions_Extension();
    PWS_Restart_Indication_Extensions_Extension(const PWS_Restart_Indication_Extensions_Extension &);
    ~PWS_Restart_Indication_Extensions_Extension();
    PWS_Restart_Indication_Extensions_Extension & operator = (const PWS_Restart_Indication_Extensions_Extension &);
    int operator == (const PWS_Restart_Indication_Extensions_Extension &) const;
    int operator != (const PWS_Restart_Indication_Extensions_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared8 *get_Restarted_Cell_List_NR();
    const __shared8 *get_Restarted_Cell_List_NR() const;
    void set_Restarted_Cell_List_NR(const __shared8 &);
    __shared8 *release_Restarted_Cell_List_NR();
    void set_Restarted_Cell_List_NR(__shared8 *);

    __shared7 *get_List_of_5GS_TAI_for_Restart();
    const __shared7 *get_List_of_5GS_TAI_for_Restart() const;
    void set_List_of_5GS_TAI_for_Restart(const __shared7 &);
    __shared7 *release_List_of_5GS_TAI_for_Restart();
    void set_List_of_5GS_TAI_for_Restart(__shared7 *);

    Global_GNB_ID *get_Global_GNB_ID();
    const Global_GNB_ID *get_Global_GNB_ID() const;
    void set_Global_GNB_ID(const Global_GNB_ID &);
    Global_GNB_ID *release_Global_GNB_ID();
    void set_Global_GNB_ID(Global_GNB_ID *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq13   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PWS_Restart_Indication_IEs_Value value;

    __seq13();
    __seq13(const __seq13 &);
    __seq13(id, criticality, const value &);

    __seq13 & operator = (const __seq13 &);
    int operator == (const __seq13 &) const;
    int operator != (const __seq13 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq14   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PWS_Restart_Indication_Extensions_Extension extensionValue;

    __seq14();
    __seq14(const __seq14 &);
    __seq14(id, criticality, const extensionValue &);

    __seq14 & operator = (const __seq14 &);
    int operator == (const __seq14 &) const;
    int operator != (const __seq14 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef __shared4 Failed_Cell_List;

class OSS_PUBLIC PWS_Failure_Indication_IEs_Value : public OssConstrainedOpenType
{
public:
    PWS_Failure_Indication_IEs_Value();
    PWS_Failure_Indication_IEs_Value(const PWS_Failure_Indication_IEs_Value &);
    ~PWS_Failure_Indication_IEs_Value();
    PWS_Failure_Indication_IEs_Value & operator = (const PWS_Failure_Indication_IEs_Value &);
    int operator == (const PWS_Failure_Indication_IEs_Value &) const;
    int operator != (const PWS_Failure_Indication_IEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared4 *get_Failed_Cell_List();
    const __shared4 *get_Failed_Cell_List() const;
    void set_Failed_Cell_List(const __shared4 &);
    __shared4 *release_Failed_Cell_List();
    void set_Failed_Cell_List(__shared4 *);

    Global_ENB_ID *get_Global_ENB_ID();
    const Global_ENB_ID *get_Global_ENB_ID() const;
    void set_Global_ENB_ID(const Global_ENB_ID &);
    Global_ENB_ID *release_Global_ENB_ID();
    void set_Global_ENB_ID(Global_ENB_ID *);
private:
    void cleanup_decoded();
};

typedef __shared8 Failed_Cell_List_NR;

class OSS_PUBLIC PWS_Failure_Indication_Extensions_Extension : public OssConstrainedOpenType
{
public:
    PWS_Failure_Indication_Extensions_Extension();
    PWS_Failure_Indication_Extensions_Extension(const PWS_Failure_Indication_Extensions_Extension &);
    ~PWS_Failure_Indication_Extensions_Extension();
    PWS_Failure_Indication_Extensions_Extension & operator = (const PWS_Failure_Indication_Extensions_Extension &);
    int operator == (const PWS_Failure_Indication_Extensions_Extension &) const;
    int operator != (const PWS_Failure_Indication_Extensions_Extension &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    __shared8 *get_Failed_Cell_List_NR();
    const __shared8 *get_Failed_Cell_List_NR() const;
    void set_Failed_Cell_List_NR(const __shared8 &);
    __shared8 *release_Failed_Cell_List_NR();
    void set_Failed_Cell_List_NR(__shared8 *);

    Global_GNB_ID *get_Global_GNB_ID();
    const Global_GNB_ID *get_Global_GNB_ID() const;
    void set_Global_GNB_ID(const Global_GNB_ID &);
    Global_GNB_ID *release_Global_GNB_ID();
    void set_Global_GNB_ID(Global_GNB_ID *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq15   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PWS_Failure_Indication_IEs_Value value;

    __seq15();
    __seq15(const __seq15 &);
    __seq15(id, criticality, const value &);

    __seq15 & operator = (const __seq15 &);
    int operator == (const __seq15 &) const;
    int operator != (const __seq15 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __seq16   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef PWS_Failure_Indication_Extensions_Extension extensionValue;

    __seq16();
    __seq16(const __seq16 &);
    __seq16(id, criticality, const extensionValue &);

    __seq16 & operator = (const __seq16 &);
    int operator == (const __seq16 &) const;
    int operator != (const __seq16 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

class OSS_PUBLIC ErrorIndicationIEs_Value : public OssConstrainedOpenType
{
public:
    ErrorIndicationIEs_Value();
    ErrorIndicationIEs_Value(const ErrorIndicationIEs_Value &);
    ~ErrorIndicationIEs_Value();
    ErrorIndicationIEs_Value & operator = (const ErrorIndicationIEs_Value &);
    int operator == (const ErrorIndicationIEs_Value &) const;
    int operator != (const ErrorIndicationIEs_Value &) const;
    int set_decoded(PDU &);
    int grab_decoded(PDU &);
    int set_encoded(const EncodedBuffer &);
    int grab_encoded(EncodedBuffer &);
    int encode(OssControl &);

    Cause *get_Cause();
    const Cause *get_Cause() const;
    void set_Cause(const Cause &);
    Cause *release_Cause();
    void set_Cause(Cause *);

    Criticality_Diagnostics *get_Criticality_Diagnostics();
    const Criticality_Diagnostics *get_Criticality_Diagnostics() const;
    void set_Criticality_Diagnostics(const Criticality_Diagnostics &);
    Criticality_Diagnostics *release_Criticality_Diagnostics();
    void set_Criticality_Diagnostics(Criticality_Diagnostics *);
private:
    void cleanup_decoded();
};

class OSS_PUBLIC __seq17   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef ErrorIndicationIEs_Value value;

    __seq17();
    __seq17(const __seq17 &);
    __seq17(id, criticality, const value &);

    __seq17 & operator = (const __seq17 &);
    int operator == (const __seq17 &) const;
    int operator != (const __seq17 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    value & get_value();
    const value & get_value() const;
    void set_value(const value &);
private:
    id id_field;
    criticality criticality_field;
    value value_field;
};

class OSS_PUBLIC __shared1   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_UINT32 id;
    typedef enum Criticality criticality;
    typedef SBC_AP_ELEMENTARY_PROCEDURES_UnsuccessfulOutcome extensionValue;

    __shared1();
    __shared1(const __shared1 &);
    __shared1(id, criticality, const extensionValue &);

    __shared1 & operator = (const __shared1 &);
    int operator == (const __shared1 &) const;
    int operator != (const __shared1 &) const;

    id & get_id();
    id get_id() const;
    void set_id(id);

    criticality & get_criticality();
    criticality get_criticality() const;
    void set_criticality(criticality);

    extensionValue & get_extensionValue();
    const extensionValue & get_extensionValue() const;
    void set_extensionValue(const extensionValue &);
private:
    id id_field;
    criticality criticality_field;
    extensionValue extensionValue_field;
};

typedef OssString TBCD_STRING;

typedef OssString PLMNidentity;

typedef OssBitString CellIdentity;

class OSS_PUBLIC EUTRAN_CGI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssBitString cell_ID;
    typedef __shared2 iE_Extensions;

    EUTRAN_CGI();
    EUTRAN_CGI(const EUTRAN_CGI &);
    EUTRAN_CGI(const pLMNidentity &, const cell_ID &, const iE_Extensions &);
    EUTRAN_CGI(const pLMNidentity &, const cell_ID &);

    EUTRAN_CGI & operator = (const EUTRAN_CGI &);
    int operator == (const EUTRAN_CGI &) const;
    int operator != (const EUTRAN_CGI &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    cell_ID & get_cell_ID();
    const cell_ID & get_cell_ID() const;
    void set_cell_ID(const cell_ID &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    cell_ID cell_ID_field;
    iE_Extensions iE_Extensions_field;
};

typedef OSS_UINT32 NumberOfBroadcasts;

class OSS_PUBLIC __shared17   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI eCGI;
    typedef OSS_UINT32 numberOfBroadcasts;
    typedef __shared2 iE_Extensions;

    __shared17();
    __shared17(const __shared17 &);
    __shared17(const eCGI &, numberOfBroadcasts, const iE_Extensions &);
    __shared17(const eCGI &, numberOfBroadcasts);

    __shared17 & operator = (const __shared17 &);
    int operator == (const __shared17 &) const;
    int operator != (const __shared17 &) const;

    eCGI & get_eCGI();
    const eCGI & get_eCGI() const;
    void set_eCGI(const eCGI &);

    numberOfBroadcasts & get_numberOfBroadcasts();
    numberOfBroadcasts get_numberOfBroadcasts() const;
    void set_numberOfBroadcasts(numberOfBroadcasts);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eCGI eCGI_field;
    numberOfBroadcasts numberOfBroadcasts_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared17 CellID_Cancelled_Item;

typedef __shared17 CancelledCellinEAI_Item;

typedef __shared18 CancelledCellinEAI;

typedef __shared17 CancelledCellinTAI_Item;

typedef __shared18 CancelledCellinTAI;

typedef OssBitString NRCellIdentity;

class OSS_PUBLIC NR_CGI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssBitString nRCellIdentity;
    typedef __shared2 iE_Extensions;

    NR_CGI();
    NR_CGI(const NR_CGI &);
    NR_CGI(const pLMNidentity &, const nRCellIdentity &, const iE_Extensions &);
    NR_CGI(const pLMNidentity &, const nRCellIdentity &);

    NR_CGI & operator = (const NR_CGI &);
    int operator == (const NR_CGI &) const;
    int operator != (const NR_CGI &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    nRCellIdentity & get_nRCellIdentity();
    const nRCellIdentity & get_nRCellIdentity() const;
    void set_nRCellIdentity(const nRCellIdentity &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    nRCellIdentity nRCellIdentity_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared22 CancelledCellinTAI_5GS;

class OSS_PUBLIC __shared21   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef NR_CGI nR_CGI;
    typedef OSS_UINT32 numberOfBroadcasts;
    typedef __shared2 iE_Extensions;

    __shared21();
    __shared21(const __shared21 &);
    __shared21(const nR_CGI &, numberOfBroadcasts, const iE_Extensions &);
    __shared21(const nR_CGI &, numberOfBroadcasts);

    __shared21 & operator = (const __shared21 &);
    int operator == (const __shared21 &) const;
    int operator != (const __shared21 &) const;

    nR_CGI & get_nR_CGI();
    const nR_CGI & get_nR_CGI() const;
    void set_nR_CGI(const nR_CGI &);

    numberOfBroadcasts & get_numberOfBroadcasts();
    numberOfBroadcasts get_numberOfBroadcasts() const;
    void set_numberOfBroadcasts(numberOfBroadcasts);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    nR_CGI nR_CGI_field;
    numberOfBroadcasts numberOfBroadcasts_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __shared10   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef EUTRAN_CGI eCGI;
    typedef __shared2 iE_Extensions;

    __shared10();
    __shared10(const __shared10 &);
    __shared10(const eCGI &, const iE_Extensions &);
    __shared10(const eCGI &);

    __shared10 & operator = (const __shared10 &);
    int operator == (const __shared10 &) const;
    int operator != (const __shared10 &) const;

    eCGI & get_eCGI();
    const eCGI & get_eCGI() const;
    void set_eCGI(const eCGI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    eCGI eCGI_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared10 CellId_Broadcast_List_Item;

class OSS_PUBLIC __shared14   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef NR_CGI nR_CGI;
    typedef __shared2 iE_Extensions;

    __shared14();
    __shared14(const __shared14 &);
    __shared14(const nR_CGI &, const iE_Extensions &);
    __shared14(const nR_CGI &);

    __shared14 & operator = (const __shared14 &);
    int operator == (const __shared14 &) const;
    int operator != (const __shared14 &) const;

    nR_CGI & get_nR_CGI();
    const nR_CGI & get_nR_CGI() const;
    void set_nR_CGI(const nR_CGI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    nR_CGI nR_CGI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq37   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum Criticality iECriticality;
    typedef OSS_UINT32 iE_ID;
    typedef enum TypeOfError typeOfError;
    typedef __shared2 iE_Extensions;

    __seq37();
    __seq37(const __seq37 &);
    __seq37(iECriticality, iE_ID, typeOfError, const iE_Extensions &);
    __seq37(iECriticality, iE_ID, typeOfError);

    __seq37 & operator = (const __seq37 &);
    int operator == (const __seq37 &) const;
    int operator != (const __seq37 &) const;

    iECriticality & get_iECriticality();
    iECriticality get_iECriticality() const;
    void set_iECriticality(iECriticality);

    iE_ID & get_iE_ID();
    iE_ID get_iE_ID() const;
    void set_iE_ID(iE_ID);

    typeOfError & get_typeOfError();
    typeOfError get_typeOfError() const;
    void set_typeOfError(typeOfError);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    iECriticality iECriticality_field;
    iE_ID iE_ID_field;
    typeOfError typeOfError_field;
    iE_Extensions iE_Extensions_field;
};

typedef OssString Emergency_Area_ID;

typedef __shared11 ScheduledCellinEAI;

class OSS_PUBLIC EmergencyAreaID_Broadcast_List_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString emergencyAreaID;
    typedef __shared11 scheduledCellinEAI;
    typedef __shared2 iE_Extensions;

    EmergencyAreaID_Broadcast_List_Item();
    EmergencyAreaID_Broadcast_List_Item(const EmergencyAreaID_Broadcast_List_Item &);
    EmergencyAreaID_Broadcast_List_Item(const emergencyAreaID &, const scheduledCellinEAI &, 
	const iE_Extensions &);
    EmergencyAreaID_Broadcast_List_Item(const emergencyAreaID &, const scheduledCellinEAI &);

    EmergencyAreaID_Broadcast_List_Item & operator = (const EmergencyAreaID_Broadcast_List_Item &);
    int operator == (const EmergencyAreaID_Broadcast_List_Item &) const;
    int operator != (const EmergencyAreaID_Broadcast_List_Item &) const;

    emergencyAreaID & get_emergencyAreaID();
    const emergencyAreaID & get_emergencyAreaID() const;
    void set_emergencyAreaID(const emergencyAreaID &);

    scheduledCellinEAI & get_scheduledCellinEAI();
    const scheduledCellinEAI & get_scheduledCellinEAI() const;
    void set_scheduledCellinEAI(const scheduledCellinEAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    emergencyAreaID emergencyAreaID_field;
    scheduledCellinEAI scheduledCellinEAI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC EmergencyAreaID_Cancelled_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString emergencyAreaID;
    typedef __shared18 cancelledCellinEAI;
    typedef __shared2 iE_Extensions;

    EmergencyAreaID_Cancelled_Item();
    EmergencyAreaID_Cancelled_Item(const EmergencyAreaID_Cancelled_Item &);
    EmergencyAreaID_Cancelled_Item(const emergencyAreaID &, const cancelledCellinEAI &, 
	const iE_Extensions &);
    EmergencyAreaID_Cancelled_Item(const emergencyAreaID &, const cancelledCellinEAI &);

    EmergencyAreaID_Cancelled_Item & operator = (const EmergencyAreaID_Cancelled_Item &);
    int operator == (const EmergencyAreaID_Cancelled_Item &) const;
    int operator != (const EmergencyAreaID_Cancelled_Item &) const;

    emergencyAreaID & get_emergencyAreaID();
    const emergencyAreaID & get_emergencyAreaID() const;
    void set_emergencyAreaID(const emergencyAreaID &);

    cancelledCellinEAI & get_cancelledCellinEAI();
    const cancelledCellinEAI & get_cancelledCellinEAI() const;
    void set_cancelledCellinEAI(const cancelledCellinEAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    emergencyAreaID emergencyAreaID_field;
    cancelledCellinEAI cancelledCellinEAI_field;
    iE_Extensions iE_Extensions_field;
};

typedef OssString TAC;

class OSS_PUBLIC TAI   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString pLMNidentity;
    typedef OssString tAC;
    typedef __shared2 iE_Extensions;

    TAI();
    TAI(const TAI &);
    TAI(const pLMNidentity &, const tAC &, const iE_Extensions &);
    TAI(const pLMNidentity &, const tAC &);

    TAI & operator = (const TAI &);
    int operator == (const TAI &) const;
    int operator != (const TAI &) const;

    pLMNidentity & get_pLMNidentity();
    const pLMNidentity & get_pLMNidentity() const;
    void set_pLMNidentity(const pLMNidentity &);

    tAC & get_tAC();
    const tAC & get_tAC() const;
    void set_tAC(const tAC &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    pLMNidentity pLMNidentity_field;
    tAC tAC_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq43   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI tai;

    __seq43();
    __seq43(const __seq43 &);
    __seq43(const tai &);

    __seq43 & operator = (const __seq43 &);
    int operator == (const __seq43 &) const;
    int operator != (const __seq43 &) const;

    tai & get_tai();
    const tai & get_tai() const;
    void set_tai(const tai &);
private:
    tai tai_field;
};

typedef OssString TAC_5GS;

typedef __shared8 List_of_5GS_Cells_for_Failure;

class OSS_PUBLIC NgENB_ID  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	macroNgENB_ID_chosen = 1,
	shortMacroNgENB_ID_chosen = 2,
	longMacroNgENB_ID_chosen = 3
    };
    typedef OssBitString macroNgENB_ID;
    typedef OssBitString shortMacroNgENB_ID;
    typedef OssBitString longMacroNgENB_ID;

    NgENB_ID();
    NgENB_ID(const NgENB_ID &);
    ~NgENB_ID();

    NgENB_ID & operator = (const NgENB_ID &);
    int operator == (const NgENB_ID &) const;
    int operator != (const NgENB_ID &) const;

    macroNgENB_ID *get_macroNgENB_ID();
    const macroNgENB_ID *get_macroNgENB_ID() const;
    void set_macroNgENB_ID(const macroNgENB_ID &);

    shortMacroNgENB_ID *get_shortMacroNgENB_ID();
    const shortMacroNgENB_ID *get_shortMacroNgENB_ID() const;
    void set_shortMacroNgENB_ID(const shortMacroNgENB_ID &);

    longMacroNgENB_ID *get_longMacroNgENB_ID();
    const longMacroNgENB_ID *get_longMacroNgENB_ID() const;
    void set_longMacroNgENB_ID(const longMacroNgENB_ID &);
private:
    union {
	OSSC::COssBitString macroNgENB_ID_field;
	OSSC::COssBitString shortMacroNgENB_ID_field;
	OSSC::COssBitString longMacroNgENB_ID_field;
    };
    void cleanup();
};

typedef __shared10 ScheduledCellinEAI_Item;

typedef __shared10 ScheduledCellinTAI_Item;

typedef __shared11 ScheduledCellinTAI;

typedef __shared15 ScheduledCellinTAI_5GS;

class OSS_PUBLIC TAI_Broadcast_List_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI tAI;
    typedef __shared11 scheduledCellinTAI;
    typedef __shared2 iE_Extensions;

    TAI_Broadcast_List_Item();
    TAI_Broadcast_List_Item(const TAI_Broadcast_List_Item &);
    TAI_Broadcast_List_Item(const tAI &, const scheduledCellinTAI &, const iE_Extensions &);
    TAI_Broadcast_List_Item(const tAI &, const scheduledCellinTAI &);

    TAI_Broadcast_List_Item & operator = (const TAI_Broadcast_List_Item &);
    int operator == (const TAI_Broadcast_List_Item &) const;
    int operator != (const TAI_Broadcast_List_Item &) const;

    tAI & get_tAI();
    const tAI & get_tAI() const;
    void set_tAI(const tAI &);

    scheduledCellinTAI & get_scheduledCellinTAI();
    const scheduledCellinTAI & get_scheduledCellinTAI() const;
    void set_scheduledCellinTAI(const scheduledCellinTAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAI tAI_field;
    scheduledCellinTAI scheduledCellinTAI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq51   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI_5GS tAI_5GS;
    typedef __shared15 scheduledCellinTAI_5GS;
    typedef __shared2 iE_Extensions;

    __seq51();
    __seq51(const __seq51 &);
    __seq51(const tAI_5GS &, const scheduledCellinTAI_5GS &, const iE_Extensions &);
    __seq51(const tAI_5GS &, const scheduledCellinTAI_5GS &);

    __seq51 & operator = (const __seq51 &);
    int operator == (const __seq51 &) const;
    int operator != (const __seq51 &) const;

    tAI_5GS & get_tAI_5GS();
    const tAI_5GS & get_tAI_5GS() const;
    void set_tAI_5GS(const tAI_5GS &);

    scheduledCellinTAI_5GS & get_scheduledCellinTAI_5GS();
    const scheduledCellinTAI_5GS & get_scheduledCellinTAI_5GS() const;
    void set_scheduledCellinTAI_5GS(const scheduledCellinTAI_5GS &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAI_5GS tAI_5GS_field;
    scheduledCellinTAI_5GS scheduledCellinTAI_5GS_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC TAI_Cancelled_List_Item   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI tAI;
    typedef __shared18 cancelledCellinTAI;
    typedef __shared2 iE_Extensions;

    TAI_Cancelled_List_Item();
    TAI_Cancelled_List_Item(const TAI_Cancelled_List_Item &);
    TAI_Cancelled_List_Item(const tAI &, const cancelledCellinTAI &, const iE_Extensions &);
    TAI_Cancelled_List_Item(const tAI &, const cancelledCellinTAI &);

    TAI_Cancelled_List_Item & operator = (const TAI_Cancelled_List_Item &);
    int operator == (const TAI_Cancelled_List_Item &) const;
    int operator != (const TAI_Cancelled_List_Item &) const;

    tAI & get_tAI();
    const tAI & get_tAI() const;
    void set_tAI(const tAI &);

    cancelledCellinTAI & get_cancelledCellinTAI();
    const cancelledCellinTAI & get_cancelledCellinTAI() const;
    void set_cancelledCellinTAI(const cancelledCellinTAI &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAI tAI_field;
    cancelledCellinTAI cancelledCellinTAI_field;
    iE_Extensions iE_Extensions_field;
};

class OSS_PUBLIC __seq54   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef TAI_5GS tAI_5GS;
    typedef __shared22 cancelledCellinTAI_5GS;
    typedef __shared2 iE_Extensions;

    __seq54();
    __seq54(const __seq54 &);
    __seq54(const tAI_5GS &, const cancelledCellinTAI_5GS &, const iE_Extensions &);
    __seq54(const tAI_5GS &, const cancelledCellinTAI_5GS &);

    __seq54 & operator = (const __seq54 &);
    int operator == (const __seq54 &) const;
    int operator != (const __seq54 &) const;

    tAI_5GS & get_tAI_5GS();
    const tAI_5GS & get_tAI_5GS() const;
    void set_tAI_5GS(const tAI_5GS &);

    cancelledCellinTAI_5GS & get_cancelledCellinTAI_5GS();
    const cancelledCellinTAI_5GS & get_cancelledCellinTAI_5GS() const;
    void set_cancelledCellinTAI_5GS(const cancelledCellinTAI_5GS &);

    iE_Extensions *get_iE_Extensions();
    const iE_Extensions *get_iE_Extensions() const;
    void set_iE_Extensions(const iE_Extensions &);
    int iE_Extensions_is_present() const;
    void omit_iE_Extensions();
private:
    OSS_UINT32 bit_mask;
    tAI_5GS tAI_5GS_field;
    cancelledCellinTAI_5GS cancelledCellinTAI_5GS_field;
    iE_Extensions iE_Extensions_field;
};

typedef __shared5 Unknown_Tracking_Area_List;

/* Universal PDU class */

class OSS_PUBLIC sbcap_PDU : public UniversalPDU {
public:
    sbcap_PDU();
    void set_SBC_AP_PDU(SBC_AP_PDU &);
    SBC_AP_PDU *get_SBC_AP_PDU() const;
    void set_Write_Replace_Warning_Request(Write_Replace_Warning_Request &);
    Write_Replace_Warning_Request *get_Write_Replace_Warning_Request() const;
    void set_Write_Replace_Warning_Response(Write_Replace_Warning_Response &);
    Write_Replace_Warning_Response *get_Write_Replace_Warning_Response() const;
    void set_Stop_Warning_Request(Stop_Warning_Request &);
    Stop_Warning_Request *get_Stop_Warning_Request() const;
    void set_Stop_Warning_Response(Stop_Warning_Response &);
    Stop_Warning_Response *get_Stop_Warning_Response() const;
    void set_Write_Replace_Warning_Indication(Write_Replace_Warning_Indication &);
    Write_Replace_Warning_Indication *get_Write_Replace_Warning_Indication() const;
    void set_Stop_Warning_Indication(Stop_Warning_Indication &);
    Stop_Warning_Indication *get_Stop_Warning_Indication() const;
    void set_PWS_Restart_Indication(PWS_Restart_Indication &);
    PWS_Restart_Indication *get_PWS_Restart_Indication() const;
    void set_PWS_Failure_Indication(PWS_Failure_Indication &);
    PWS_Failure_Indication *get_PWS_Failure_Indication() const;
    void set_Error_Indication(Error_Indication &);
    Error_Indication *get_Error_Indication() const;
    void set_Broadcast_Scheduled_Area_List(Broadcast_Scheduled_Area_List &);
    Broadcast_Scheduled_Area_List *get_Broadcast_Scheduled_Area_List() const;
    void set_Broadcast_Scheduled_Area_List_5GS(Broadcast_Scheduled_Area_List_5GS &);
    Broadcast_Scheduled_Area_List_5GS *get_Broadcast_Scheduled_Area_List_5GS() const;
    void set_Broadcast_Cancelled_Area_List(Broadcast_Cancelled_Area_List &);
    Broadcast_Cancelled_Area_List *get_Broadcast_Cancelled_Area_List() const;
    void set_Broadcast_Cancelled_Area_List_5GS(Broadcast_Cancelled_Area_List_5GS &);
    Broadcast_Cancelled_Area_List_5GS *get_Broadcast_Cancelled_Area_List_5GS() const;
    void set_Broadcast_Empty_Area_List(Broadcast_Empty_Area_List &);
    Broadcast_Empty_Area_List *get_Broadcast_Empty_Area_List() const;
    void set_Broadcast_Empty_Area_List_5GS(Broadcast_Empty_Area_List_5GS &);
    Broadcast_Empty_Area_List_5GS *get_Broadcast_Empty_Area_List_5GS() const;
    void set_Cause(Cause &);
    Cause *get_Cause() const;
    void set_Concurrent_Warning_Message_Indicator(Concurrent_Warning_Message_Indicator &);
    Concurrent_Warning_Message_Indicator *get_Concurrent_Warning_Message_Indicator() const;
    void set_Criticality_Diagnostics(Criticality_Diagnostics &);
    Criticality_Diagnostics *get_Criticality_Diagnostics() const;
    void set_Data_Coding_Scheme(Data_Coding_Scheme &);
    Data_Coding_Scheme *get_Data_Coding_Scheme() const;
    void set_Extended_Repetition_Period(Extended_Repetition_Period &);
    Extended_Repetition_Period *get_Extended_Repetition_Period() const;
    void set_Failed_Cell_List(Failed_Cell_List &);
    Failed_Cell_List *get_Failed_Cell_List() const;
    void set_Failed_Cell_List_NR(Failed_Cell_List_NR &);
    Failed_Cell_List_NR *get_Failed_Cell_List_NR() const;
    void set_Global_ENB_ID(Global_ENB_ID &);
    Global_ENB_ID *get_Global_ENB_ID() const;
    void set_Global_RAN_Node_ID(Global_RAN_Node_ID &);
    Global_RAN_Node_ID *get_Global_RAN_Node_ID() const;
    void set_Global_GNB_ID(Global_GNB_ID &);
    Global_GNB_ID *get_Global_GNB_ID() const;
    void set_List_of_TAIs(List_of_TAIs &);
    List_of_TAIs *get_List_of_TAIs() const;
    void set_List_of_TAIs_Restart(List_of_TAIs_Restart &);
    List_of_TAIs_Restart *get_List_of_TAIs_Restart() const;
    void set_List_of_EAIs_Restart(List_of_EAIs_Restart &);
    List_of_EAIs_Restart *get_List_of_EAIs_Restart() const;
    void set_List_of_5GS_TAIs(List_of_5GS_TAIs &);
    List_of_5GS_TAIs *get_List_of_5GS_TAIs() const;
    void set_List_of_5GS_Cells_for_Failure(List_of_5GS_Cells_for_Failure &);
    List_of_5GS_Cells_for_Failure *get_List_of_5GS_Cells_for_Failure() const;
    void set_List_of_5GS_TAI_for_Restart(List_of_5GS_TAI_for_Restart &);
    List_of_5GS_TAI_for_Restart *get_List_of_5GS_TAI_for_Restart() const;
    void set_Message_Identifier(Message_Identifier &);
    Message_Identifier *get_Message_Identifier() const;
    void set_Number_of_Broadcasts_Requested(Number_of_Broadcasts_Requested &);
    Number_of_Broadcasts_Requested *get_Number_of_Broadcasts_Requested() const;
    void set_NgENB_ID(NgENB_ID &);
    NgENB_ID *get_NgENB_ID() const;
    void set_Omc_Id(Omc_Id &);
    Omc_Id *get_Omc_Id() const;
    void set_Repetition_Period(Repetition_Period &);
    Repetition_Period *get_Repetition_Period() const;
    void set_Restarted_Cell_List(Restarted_Cell_List &);
    Restarted_Cell_List *get_Restarted_Cell_List() const;
    void set_RAT_Selector_5GS(RAT_Selector_5GS &);
    RAT_Selector_5GS *get_RAT_Selector_5GS() const;
    void set_Restarted_Cell_List_NR(Restarted_Cell_List_NR &);
    Restarted_Cell_List_NR *get_Restarted_Cell_List_NR() const;
    void set_Send_Write_Replace_Warning_Indication(Send_Write_Replace_Warning_Indication &);
    Send_Write_Replace_Warning_Indication *get_Send_Write_Replace_Warning_Indication() const;
    void set_Send_Stop_Warning_Indication(Send_Stop_Warning_Indication &);
    Send_Stop_Warning_Indication *get_Send_Stop_Warning_Indication() const;
    void set_Serial_Number(Serial_Number &);
    Serial_Number *get_Serial_Number() const;
    void set_Stop_All_Indicator(Stop_All_Indicator &);
    Stop_All_Indicator *get_Stop_All_Indicator() const;
    void set_Unknown_Tracking_Area_List(Unknown_Tracking_Area_List &);
    Unknown_Tracking_Area_List *get_Unknown_Tracking_Area_List() const;
    void set_Unknown_5GS_Tracking_Area_List(Unknown_5GS_Tracking_Area_List &);
    Unknown_5GS_Tracking_Area_List *get_Unknown_5GS_Tracking_Area_List() const;
    void set_Warning_Area_List(Warning_Area_List &);
    Warning_Area_List *get_Warning_Area_List() const;
    void set_Warning_Message_Content(Warning_Message_Content &);
    Warning_Message_Content *get_Warning_Message_Content() const;
    void set_Warning_Area_Coordinates(Warning_Area_Coordinates &);
    Warning_Area_Coordinates *get_Warning_Area_Coordinates() const;
    void set_Warning_Security_Information(Warning_Security_Information &);
    Warning_Security_Information *get_Warning_Security_Information() const;
    void set_Warning_Type(Warning_Type &);
    Warning_Type *get_Warning_Type() const;
    void set_Warning_Area_List_5GS(Warning_Area_List_5GS &);
    Warning_Area_List_5GS *get_Warning_Area_List_5GS() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_SBC_AP_PDU(const SBC_AP_PDU &);
    const SBC_AP_PDU *get_const_SBC_AP_PDU() const;
    void set_const_Write_Replace_Warning_Request(const Write_Replace_Warning_Request &);
    const Write_Replace_Warning_Request *get_const_Write_Replace_Warning_Request() const;
    void set_const_Write_Replace_Warning_Response(const Write_Replace_Warning_Response &);
    const Write_Replace_Warning_Response *get_const_Write_Replace_Warning_Response() const;
    void set_const_Stop_Warning_Request(const Stop_Warning_Request &);
    const Stop_Warning_Request *get_const_Stop_Warning_Request() const;
    void set_const_Stop_Warning_Response(const Stop_Warning_Response &);
    const Stop_Warning_Response *get_const_Stop_Warning_Response() const;
    void set_const_Write_Replace_Warning_Indication(const Write_Replace_Warning_Indication &);
    const Write_Replace_Warning_Indication *get_const_Write_Replace_Warning_Indication() const;
    void set_const_Stop_Warning_Indication(const Stop_Warning_Indication &);
    const Stop_Warning_Indication *get_const_Stop_Warning_Indication() const;
    void set_const_PWS_Restart_Indication(const PWS_Restart_Indication &);
    const PWS_Restart_Indication *get_const_PWS_Restart_Indication() const;
    void set_const_PWS_Failure_Indication(const PWS_Failure_Indication &);
    const PWS_Failure_Indication *get_const_PWS_Failure_Indication() const;
    void set_const_Error_Indication(const Error_Indication &);
    const Error_Indication *get_const_Error_Indication() const;
    void set_const_Broadcast_Scheduled_Area_List(const Broadcast_Scheduled_Area_List &);
    const Broadcast_Scheduled_Area_List *get_const_Broadcast_Scheduled_Area_List() const;
    void set_const_Broadcast_Scheduled_Area_List_5GS(const Broadcast_Scheduled_Area_List_5GS &);
    const Broadcast_Scheduled_Area_List_5GS *get_const_Broadcast_Scheduled_Area_List_5GS() const;
    void set_const_Broadcast_Cancelled_Area_List(const Broadcast_Cancelled_Area_List &);
    const Broadcast_Cancelled_Area_List *get_const_Broadcast_Cancelled_Area_List() const;
    void set_const_Broadcast_Cancelled_Area_List_5GS(const Broadcast_Cancelled_Area_List_5GS &);
    const Broadcast_Cancelled_Area_List_5GS *get_const_Broadcast_Cancelled_Area_List_5GS() const;
    void set_const_Broadcast_Empty_Area_List(const Broadcast_Empty_Area_List &);
    const Broadcast_Empty_Area_List *get_const_Broadcast_Empty_Area_List() const;
    void set_const_Broadcast_Empty_Area_List_5GS(const Broadcast_Empty_Area_List_5GS &);
    const Broadcast_Empty_Area_List_5GS *get_const_Broadcast_Empty_Area_List_5GS() const;
    void set_const_Cause(const Cause &);
    const Cause *get_const_Cause() const;
    void set_const_Concurrent_Warning_Message_Indicator(const Concurrent_Warning_Message_Indicator &);
    const Concurrent_Warning_Message_Indicator *get_const_Concurrent_Warning_Message_Indicator() const;
    void set_const_Criticality_Diagnostics(const Criticality_Diagnostics &);
    const Criticality_Diagnostics *get_const_Criticality_Diagnostics() const;
    void set_const_Data_Coding_Scheme(const Data_Coding_Scheme &);
    const Data_Coding_Scheme *get_const_Data_Coding_Scheme() const;
    void set_const_Extended_Repetition_Period(const Extended_Repetition_Period &);
    const Extended_Repetition_Period *get_const_Extended_Repetition_Period() const;
    void set_const_Failed_Cell_List(const Failed_Cell_List &);
    const Failed_Cell_List *get_const_Failed_Cell_List() const;
    void set_const_Failed_Cell_List_NR(const Failed_Cell_List_NR &);
    const Failed_Cell_List_NR *get_const_Failed_Cell_List_NR() const;
    void set_const_Global_ENB_ID(const Global_ENB_ID &);
    const Global_ENB_ID *get_const_Global_ENB_ID() const;
    void set_const_Global_RAN_Node_ID(const Global_RAN_Node_ID &);
    const Global_RAN_Node_ID *get_const_Global_RAN_Node_ID() const;
    void set_const_Global_GNB_ID(const Global_GNB_ID &);
    const Global_GNB_ID *get_const_Global_GNB_ID() const;
    void set_const_List_of_TAIs(const List_of_TAIs &);
    const List_of_TAIs *get_const_List_of_TAIs() const;
    void set_const_List_of_TAIs_Restart(const List_of_TAIs_Restart &);
    const List_of_TAIs_Restart *get_const_List_of_TAIs_Restart() const;
    void set_const_List_of_EAIs_Restart(const List_of_EAIs_Restart &);
    const List_of_EAIs_Restart *get_const_List_of_EAIs_Restart() const;
    void set_const_List_of_5GS_TAIs(const List_of_5GS_TAIs &);
    const List_of_5GS_TAIs *get_const_List_of_5GS_TAIs() const;
    void set_const_List_of_5GS_Cells_for_Failure(const List_of_5GS_Cells_for_Failure &);
    const List_of_5GS_Cells_for_Failure *get_const_List_of_5GS_Cells_for_Failure() const;
    void set_const_List_of_5GS_TAI_for_Restart(const List_of_5GS_TAI_for_Restart &);
    const List_of_5GS_TAI_for_Restart *get_const_List_of_5GS_TAI_for_Restart() const;
    void set_const_Message_Identifier(const Message_Identifier &);
    const Message_Identifier *get_const_Message_Identifier() const;
    void set_const_Number_of_Broadcasts_Requested(const Number_of_Broadcasts_Requested &);
    const Number_of_Broadcasts_Requested *get_const_Number_of_Broadcasts_Requested() const;
    void set_const_NgENB_ID(const NgENB_ID &);
    const NgENB_ID *get_const_NgENB_ID() const;
    void set_const_Omc_Id(const Omc_Id &);
    const Omc_Id *get_const_Omc_Id() const;
    void set_const_Repetition_Period(const Repetition_Period &);
    const Repetition_Period *get_const_Repetition_Period() const;
    void set_const_Restarted_Cell_List(const Restarted_Cell_List &);
    const Restarted_Cell_List *get_const_Restarted_Cell_List() const;
    void set_const_RAT_Selector_5GS(const RAT_Selector_5GS &);
    const RAT_Selector_5GS *get_const_RAT_Selector_5GS() const;
    void set_const_Restarted_Cell_List_NR(const Restarted_Cell_List_NR &);
    const Restarted_Cell_List_NR *get_const_Restarted_Cell_List_NR() const;
    void set_const_Send_Write_Replace_Warning_Indication(const Send_Write_Replace_Warning_Indication &);
    const Send_Write_Replace_Warning_Indication *get_const_Send_Write_Replace_Warning_Indication() const;
    void set_const_Send_Stop_Warning_Indication(const Send_Stop_Warning_Indication &);
    const Send_Stop_Warning_Indication *get_const_Send_Stop_Warning_Indication() const;
    void set_const_Serial_Number(const Serial_Number &);
    const Serial_Number *get_const_Serial_Number() const;
    void set_const_Stop_All_Indicator(const Stop_All_Indicator &);
    const Stop_All_Indicator *get_const_Stop_All_Indicator() const;
    void set_const_Unknown_Tracking_Area_List(const Unknown_Tracking_Area_List &);
    const Unknown_Tracking_Area_List *get_const_Unknown_Tracking_Area_List() const;
    void set_const_Unknown_5GS_Tracking_Area_List(const Unknown_5GS_Tracking_Area_List &);
    const Unknown_5GS_Tracking_Area_List *get_const_Unknown_5GS_Tracking_Area_List() const;
    void set_const_Warning_Area_List(const Warning_Area_List &);
    const Warning_Area_List *get_const_Warning_Area_List() const;
    void set_const_Warning_Message_Content(const Warning_Message_Content &);
    const Warning_Message_Content *get_const_Warning_Message_Content() const;
    void set_const_Warning_Area_Coordinates(const Warning_Area_Coordinates &);
    const Warning_Area_Coordinates *get_const_Warning_Area_Coordinates() const;
    void set_const_Warning_Security_Information(const Warning_Security_Information &);
    const Warning_Security_Information *get_const_Warning_Security_Information() const;
    void set_const_Warning_Type(const Warning_Type &);
    const Warning_Type *get_const_Warning_Type() const;
    void set_const_Warning_Area_List_5GS(const Warning_Area_List_5GS &);
    const Warning_Area_List_5GS *get_const_Warning_Area_List_5GS() const;
#endif
};

/* Specific PDU classes */

class OSS_PUBLIC SBC_AP_PDU_PDU : public ConcretePDU {
public:
    SBC_AP_PDU_PDU();
    void set_data(SBC_AP_PDU &);
    SBC_AP_PDU *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SBC_AP_PDU & d);
    const SBC_AP_PDU *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Write_Replace_Warning_Request_PDU : public ConcretePDU {
public:
    Write_Replace_Warning_Request_PDU();
    void set_data(Write_Replace_Warning_Request &);
    Write_Replace_Warning_Request *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Write_Replace_Warning_Request & d);
    const Write_Replace_Warning_Request *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Write_Replace_Warning_Response_PDU : public ConcretePDU {
public:
    Write_Replace_Warning_Response_PDU();
    void set_data(Write_Replace_Warning_Response &);
    Write_Replace_Warning_Response *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Write_Replace_Warning_Response & d);
    const Write_Replace_Warning_Response *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Stop_Warning_Request_PDU : public ConcretePDU {
public:
    Stop_Warning_Request_PDU();
    void set_data(Stop_Warning_Request &);
    Stop_Warning_Request *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Stop_Warning_Request & d);
    const Stop_Warning_Request *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Stop_Warning_Response_PDU : public ConcretePDU {
public:
    Stop_Warning_Response_PDU();
    void set_data(Stop_Warning_Response &);
    Stop_Warning_Response *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Stop_Warning_Response & d);
    const Stop_Warning_Response *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Write_Replace_Warning_Indication_PDU : public ConcretePDU {
public:
    Write_Replace_Warning_Indication_PDU();
    void set_data(Write_Replace_Warning_Indication &);
    Write_Replace_Warning_Indication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Write_Replace_Warning_Indication & d);
    const Write_Replace_Warning_Indication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Stop_Warning_Indication_PDU : public ConcretePDU {
public:
    Stop_Warning_Indication_PDU();
    void set_data(Stop_Warning_Indication &);
    Stop_Warning_Indication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Stop_Warning_Indication & d);
    const Stop_Warning_Indication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PWS_Restart_Indication_PDU : public ConcretePDU {
public:
    PWS_Restart_Indication_PDU();
    void set_data(PWS_Restart_Indication &);
    PWS_Restart_Indication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PWS_Restart_Indication & d);
    const PWS_Restart_Indication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PWS_Failure_Indication_PDU : public ConcretePDU {
public:
    PWS_Failure_Indication_PDU();
    void set_data(PWS_Failure_Indication &);
    PWS_Failure_Indication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PWS_Failure_Indication & d);
    const PWS_Failure_Indication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Error_Indication_PDU : public ConcretePDU {
public:
    Error_Indication_PDU();
    void set_data(Error_Indication &);
    Error_Indication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Error_Indication & d);
    const Error_Indication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Broadcast_Scheduled_Area_List_PDU : public ConcretePDU {
public:
    Broadcast_Scheduled_Area_List_PDU();
    void set_data(Broadcast_Scheduled_Area_List &);
    Broadcast_Scheduled_Area_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Broadcast_Scheduled_Area_List & d);
    const Broadcast_Scheduled_Area_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Broadcast_Scheduled_Area_List_5GS_PDU : public ConcretePDU {
public:
    Broadcast_Scheduled_Area_List_5GS_PDU();
    void set_data(Broadcast_Scheduled_Area_List_5GS &);
    Broadcast_Scheduled_Area_List_5GS *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Broadcast_Scheduled_Area_List_5GS & d);
    const Broadcast_Scheduled_Area_List_5GS *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Broadcast_Cancelled_Area_List_PDU : public ConcretePDU {
public:
    Broadcast_Cancelled_Area_List_PDU();
    void set_data(Broadcast_Cancelled_Area_List &);
    Broadcast_Cancelled_Area_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Broadcast_Cancelled_Area_List & d);
    const Broadcast_Cancelled_Area_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Broadcast_Cancelled_Area_List_5GS_PDU : public ConcretePDU {
public:
    Broadcast_Cancelled_Area_List_5GS_PDU();
    void set_data(Broadcast_Cancelled_Area_List_5GS &);
    Broadcast_Cancelled_Area_List_5GS *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Broadcast_Cancelled_Area_List_5GS & d);
    const Broadcast_Cancelled_Area_List_5GS *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Broadcast_Empty_Area_List_PDU : public ConcretePDU {
public:
    Broadcast_Empty_Area_List_PDU();
    void set_data(Broadcast_Empty_Area_List &);
    Broadcast_Empty_Area_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Broadcast_Empty_Area_List & d);
    const Broadcast_Empty_Area_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Broadcast_Empty_Area_List_5GS_PDU : public ConcretePDU {
public:
    Broadcast_Empty_Area_List_5GS_PDU();
    void set_data(Broadcast_Empty_Area_List_5GS &);
    Broadcast_Empty_Area_List_5GS *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Broadcast_Empty_Area_List_5GS & d);
    const Broadcast_Empty_Area_List_5GS *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Cause_PDU : public ConcretePDU {
public:
    Cause_PDU();
    void set_data(Cause &);
    Cause *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Cause & d);
    const Cause *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Concurrent_Warning_Message_Indicator_PDU : public ConcretePDU {
public:
    Concurrent_Warning_Message_Indicator_PDU();
    void set_data(Concurrent_Warning_Message_Indicator &);
    Concurrent_Warning_Message_Indicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Concurrent_Warning_Message_Indicator & d);
    const Concurrent_Warning_Message_Indicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Criticality_Diagnostics_PDU : public ConcretePDU {
public:
    Criticality_Diagnostics_PDU();
    void set_data(Criticality_Diagnostics &);
    Criticality_Diagnostics *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Criticality_Diagnostics & d);
    const Criticality_Diagnostics *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Data_Coding_Scheme_PDU : public ConcretePDU {
public:
    Data_Coding_Scheme_PDU();
    void set_data(Data_Coding_Scheme &);
    Data_Coding_Scheme *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Data_Coding_Scheme & d);
    const Data_Coding_Scheme *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Extended_Repetition_Period_PDU : public ConcretePDU {
public:
    Extended_Repetition_Period_PDU();
    void set_data(Extended_Repetition_Period &);
    Extended_Repetition_Period *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Extended_Repetition_Period & d);
    const Extended_Repetition_Period *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Failed_Cell_List_PDU : public ConcretePDU {
public:
    Failed_Cell_List_PDU();
    void set_data(Failed_Cell_List &);
    Failed_Cell_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Failed_Cell_List & d);
    const Failed_Cell_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Failed_Cell_List_NR_PDU : public ConcretePDU {
public:
    Failed_Cell_List_NR_PDU();
    void set_data(Failed_Cell_List_NR &);
    Failed_Cell_List_NR *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Failed_Cell_List_NR & d);
    const Failed_Cell_List_NR *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Global_ENB_ID_PDU : public ConcretePDU {
public:
    Global_ENB_ID_PDU();
    void set_data(Global_ENB_ID &);
    Global_ENB_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Global_ENB_ID & d);
    const Global_ENB_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Global_RAN_Node_ID_PDU : public ConcretePDU {
public:
    Global_RAN_Node_ID_PDU();
    void set_data(Global_RAN_Node_ID &);
    Global_RAN_Node_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Global_RAN_Node_ID & d);
    const Global_RAN_Node_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Global_GNB_ID_PDU : public ConcretePDU {
public:
    Global_GNB_ID_PDU();
    void set_data(Global_GNB_ID &);
    Global_GNB_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Global_GNB_ID & d);
    const Global_GNB_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC List_of_TAIs_PDU : public ConcretePDU {
public:
    List_of_TAIs_PDU();
    void set_data(List_of_TAIs &);
    List_of_TAIs *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const List_of_TAIs & d);
    const List_of_TAIs *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC List_of_TAIs_Restart_PDU : public ConcretePDU {
public:
    List_of_TAIs_Restart_PDU();
    void set_data(List_of_TAIs_Restart &);
    List_of_TAIs_Restart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const List_of_TAIs_Restart & d);
    const List_of_TAIs_Restart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC List_of_EAIs_Restart_PDU : public ConcretePDU {
public:
    List_of_EAIs_Restart_PDU();
    void set_data(List_of_EAIs_Restart &);
    List_of_EAIs_Restart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const List_of_EAIs_Restart & d);
    const List_of_EAIs_Restart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC List_of_5GS_TAIs_PDU : public ConcretePDU {
public:
    List_of_5GS_TAIs_PDU();
    void set_data(List_of_5GS_TAIs &);
    List_of_5GS_TAIs *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const List_of_5GS_TAIs & d);
    const List_of_5GS_TAIs *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC List_of_5GS_Cells_for_Failure_PDU : public ConcretePDU {
public:
    List_of_5GS_Cells_for_Failure_PDU();
    void set_data(List_of_5GS_Cells_for_Failure &);
    List_of_5GS_Cells_for_Failure *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const List_of_5GS_Cells_for_Failure & d);
    const List_of_5GS_Cells_for_Failure *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC List_of_5GS_TAI_for_Restart_PDU : public ConcretePDU {
public:
    List_of_5GS_TAI_for_Restart_PDU();
    void set_data(List_of_5GS_TAI_for_Restart &);
    List_of_5GS_TAI_for_Restart *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const List_of_5GS_TAI_for_Restart & d);
    const List_of_5GS_TAI_for_Restart *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Message_Identifier_PDU : public ConcretePDU {
public:
    Message_Identifier_PDU();
    void set_data(Message_Identifier &);
    Message_Identifier *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Message_Identifier & d);
    const Message_Identifier *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Number_of_Broadcasts_Requested_PDU : public ConcretePDU {
public:
    Number_of_Broadcasts_Requested_PDU();
    void set_data(Number_of_Broadcasts_Requested &);
    Number_of_Broadcasts_Requested *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Number_of_Broadcasts_Requested & d);
    const Number_of_Broadcasts_Requested *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NgENB_ID_PDU : public ConcretePDU {
public:
    NgENB_ID_PDU();
    void set_data(NgENB_ID &);
    NgENB_ID *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NgENB_ID & d);
    const NgENB_ID *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Omc_Id_PDU : public ConcretePDU {
public:
    Omc_Id_PDU();
    void set_data(Omc_Id &);
    Omc_Id *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Omc_Id & d);
    const Omc_Id *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Repetition_Period_PDU : public ConcretePDU {
public:
    Repetition_Period_PDU();
    void set_data(Repetition_Period &);
    Repetition_Period *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Repetition_Period & d);
    const Repetition_Period *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Restarted_Cell_List_PDU : public ConcretePDU {
public:
    Restarted_Cell_List_PDU();
    void set_data(Restarted_Cell_List &);
    Restarted_Cell_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Restarted_Cell_List & d);
    const Restarted_Cell_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC RAT_Selector_5GS_PDU : public ConcretePDU {
public:
    RAT_Selector_5GS_PDU();
    void set_data(RAT_Selector_5GS &);
    RAT_Selector_5GS *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const RAT_Selector_5GS & d);
    const RAT_Selector_5GS *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Restarted_Cell_List_NR_PDU : public ConcretePDU {
public:
    Restarted_Cell_List_NR_PDU();
    void set_data(Restarted_Cell_List_NR &);
    Restarted_Cell_List_NR *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Restarted_Cell_List_NR & d);
    const Restarted_Cell_List_NR *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Send_Write_Replace_Warning_Indication_PDU : public ConcretePDU {
public:
    Send_Write_Replace_Warning_Indication_PDU();
    void set_data(Send_Write_Replace_Warning_Indication &);
    Send_Write_Replace_Warning_Indication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Send_Write_Replace_Warning_Indication & d);
    const Send_Write_Replace_Warning_Indication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Send_Stop_Warning_Indication_PDU : public ConcretePDU {
public:
    Send_Stop_Warning_Indication_PDU();
    void set_data(Send_Stop_Warning_Indication &);
    Send_Stop_Warning_Indication *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Send_Stop_Warning_Indication & d);
    const Send_Stop_Warning_Indication *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Serial_Number_PDU : public ConcretePDU {
public:
    Serial_Number_PDU();
    void set_data(Serial_Number &);
    Serial_Number *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Serial_Number & d);
    const Serial_Number *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Stop_All_Indicator_PDU : public ConcretePDU {
public:
    Stop_All_Indicator_PDU();
    void set_data(Stop_All_Indicator &);
    Stop_All_Indicator *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Stop_All_Indicator & d);
    const Stop_All_Indicator *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Unknown_Tracking_Area_List_PDU : public ConcretePDU {
public:
    Unknown_Tracking_Area_List_PDU();
    void set_data(Unknown_Tracking_Area_List &);
    Unknown_Tracking_Area_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Unknown_Tracking_Area_List & d);
    const Unknown_Tracking_Area_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Unknown_5GS_Tracking_Area_List_PDU : public ConcretePDU {
public:
    Unknown_5GS_Tracking_Area_List_PDU();
    void set_data(Unknown_5GS_Tracking_Area_List &);
    Unknown_5GS_Tracking_Area_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Unknown_5GS_Tracking_Area_List & d);
    const Unknown_5GS_Tracking_Area_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Warning_Area_List_PDU : public ConcretePDU {
public:
    Warning_Area_List_PDU();
    void set_data(Warning_Area_List &);
    Warning_Area_List *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Warning_Area_List & d);
    const Warning_Area_List *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Warning_Message_Content_PDU : public ConcretePDU {
public:
    Warning_Message_Content_PDU();
    void set_data(Warning_Message_Content &);
    Warning_Message_Content *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Warning_Message_Content & d);
    const Warning_Message_Content *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Warning_Area_Coordinates_PDU : public ConcretePDU {
public:
    Warning_Area_Coordinates_PDU();
    void set_data(Warning_Area_Coordinates &);
    Warning_Area_Coordinates *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Warning_Area_Coordinates & d);
    const Warning_Area_Coordinates *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Warning_Security_Information_PDU : public ConcretePDU {
public:
    Warning_Security_Information_PDU();
    void set_data(Warning_Security_Information &);
    Warning_Security_Information *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Warning_Security_Information & d);
    const Warning_Security_Information *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Warning_Type_PDU : public ConcretePDU {
public:
    Warning_Type_PDU();
    void set_data(Warning_Type &);
    Warning_Type *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Warning_Type & d);
    const Warning_Type *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Warning_Area_List_5GS_PDU : public ConcretePDU {
public:
    Warning_Area_List_5GS_PDU();
    void set_data(Warning_Area_List_5GS &);
    Warning_Area_List_5GS *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Warning_Area_List_5GS & d);
    const Warning_Area_List_5GS *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

/* Control object class */

class OSS_PUBLIC sbcap_Control : public OssControl {
public:
    sbcap_Control();
    sbcap_Control(const sbcap_Control &);
};


/* External definitions for named values */

const OSS_INT32 id_Write_Replace_Warning = 0;

const OSS_INT32 id_Stop_Warning = 1;

const OSS_INT32 id_Error_Indication = 2;

const OSS_INT32 id_Write_Replace_Warning_Indication = 3;

const OSS_INT32 id_Stop_Warning_Indication = 4;

const OSS_INT32 id_PWS_Restart_Indication = 5;

const OSS_INT32 id_PWS_Failure_Indication = 6;

const OSS_INT32 id_Broadcast_Message_Content = 0;

const OSS_INT32 id_Cause = 1;

const OSS_INT32 id_Criticality_Diagnostics = 2;

const OSS_INT32 id_Data_Coding_Scheme = 3;

const OSS_INT32 id_Failure_List = 4;

const OSS_INT32 id_Message_Identifier = 5;

const OSS_INT32 id_Number_of_Broadcasts_Completed_List = 6;

const OSS_INT32 id_Number_of_Broadcasts_Requested = 7;

const OSS_INT32 id_Radio_Resource_Loading_List = 8;

const OSS_INT32 id_Recovery_Indication = 9;

const OSS_INT32 id_Repetition_Period = 10;

const OSS_INT32 id_Serial_Number = 11;

const OSS_INT32 id_Service_Areas_List = 12;

const OSS_INT32 id_TypeOfError = 13;

const OSS_INT32 id_List_of_TAIs = 14;

const OSS_INT32 id_Warning_Area_List = 15;

const OSS_INT32 id_Warning_Message_Content = 16;

const OSS_INT32 id_Warning_Security_Information = 17;

const OSS_INT32 id_Warning_Type = 18;

const OSS_INT32 id_Omc_Id = 19;

const OSS_INT32 id_Concurrent_Warning_Message_Indicator = 20;

const OSS_INT32 id_Extended_Repetition_Period = 21;

const OSS_INT32 id_Unknown_Tracking_Area_List = 22;

const OSS_INT32 id_Broadcast_Scheduled_Area_List = 23;

const OSS_INT32 id_Send_Write_Replace_Warning_Indication = 24;

const OSS_INT32 id_Broadcast_Cancelled_Area_List = 25;

const OSS_INT32 id_Send_Stop_Warning_Indication = 26;

const OSS_INT32 id_Stop_All_Indicator = 27;

const OSS_INT32 id_Global_ENB_ID = 28;

const OSS_INT32 id_Broadcast_Empty_Area_List = 29;

const OSS_INT32 id_Restarted_Cell_List = 30;

const OSS_INT32 id_List_of_TAIs_Restart = 31;

const OSS_INT32 id_List_of_EAIs_Restart = 32;

const OSS_INT32 id_Failed_Cell_List = 33;

const OSS_INT32 id_List_of_5GS_TAIs = 34;

const OSS_INT32 id_Warning_Area_List_5GS = 35;

const OSS_INT32 id_Global_RAN_Node_ID = 36;

const OSS_INT32 id_Global_GNB_ID = 37;

const OSS_INT32 id_RAT_Selector_5GS = 38;

const OSS_INT32 id_Unknown_5GS_Tracking_Area_List = 39;

const OSS_INT32 id_Broadcast_Scheduled_Area_List_5GS = 40;

const OSS_INT32 id_Broadcast_Cancelled_Area_List_5GS = 41;

const OSS_INT32 id_Broadcast_Empty_Area_List_5GS = 42;

const OSS_INT32 id_Restarted_Cell_List_NR = 43;

const OSS_INT32 id_Failed_Cell_List_NR = 44;

const OSS_INT32 id_List_of_5GS_TAI_for_Restart = 45;

const OSS_INT32 id_Warning_Area_Coordinates = 46;

const OSS_INT32 maxNrOfErrors = 256;

const OSS_INT32 maxnoofCellID = USHRT_MAX;

const OSS_INT32 maxnoofCellinEAI = USHRT_MAX;

const OSS_INT32 maxnoofCellinTAI = USHRT_MAX;

const OSS_INT32 maxNrOfTAIs = USHRT_MAX;

const OSS_INT32 maxnoofEmergencyAreaID = USHRT_MAX;

const OSS_INT32 maxnoofTAIforWarning = USHRT_MAX;

const OSS_INT32 maxProtocolExtensions = USHRT_MAX;

const OSS_INT32 maxProtocolIEs = USHRT_MAX;

const OSS_INT32 maxnoofeNBIds = 256;

const OSS_INT32 maxnoofRestartedCells = 256;

const OSS_INT32 maxnoofRestartTAIs = 2048;

const OSS_INT32 maxnoofRestartEAIs = 256;

const OSS_INT32 maxnoofFailedCells = 256;

const OSS_INT32 maxnoof5GSTAIs = 2048;

const OSS_INT32 maxnoofCellsingNB = 16384;

const OSS_INT32 maxnoofCellsin5GS = 16776960;

const OSS_INT32 maxnoofCellsin5GSTAI = USHRT_MAX;

const OSS_INT32 maxnoofRANNodes = USHRT_MAX;

const OSS_INT32 maxnoofRestart5GSTAIs = 2048;

const OSS_INT32 maxnoofCellsforRestartNR = 16384;

#endif // OSS_sbcap
