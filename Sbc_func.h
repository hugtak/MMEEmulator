#ifndef SBC_FUNC_H
#define SBC_FUNC_H

#define alternative_chosen 10
#define typename_PDU 10
/*Includes*/
#include "General_func.h"


/*Functions*/
void printHexString(OssControl *ctl, const OssString &value);
void printHexBitString(OssControl *ctl, const OssBitString &value);
static void printProtocolExtensions(OssControl *ctl, Global_ENB_ID::iE_Extensions *ie_ext, int indent);
void printProtocolIEs(OssControl *ctl, Write_Replace_Warning_Request::protocolIEs & ies, int indent);
void printWriteReplaceWarningReqMsg(OssControl *ctl, SBC_AP_PDU *request);
int intToAsciiLen(int number);
unsigned char* intToAscii(int number);
unsigned char* intToAscii2Bytes(int number);
void createRequest(OssControl *ctl, SBC_AP_PDU **request, int message_identifier_val, int serial_number_val, int repetition_period_val, int nb_of_broad_val, 
const char *message_content, int number_of_tais, int data_scheme_val, int conc_message_val, int send_indication_val);
FILE * openOutputFile(char *directoryName, const char *fileName);
FILE * openInputFile(char *directoryName, const char *fileName);
FILE * openRequestFile(char *directoryName, const char *fileName);
EncodedBuffer *readEncodingFromFile(const char *filename);
void writeEncodingFile(const char *filename, OssControl *ctl, SBC_AP_PDU_PDU pdu);
void writeEncodingFileMsg(const char *filename, unsigned char *msg, long length);
void WRWRequest(OssControl *ctl);
void createSuccessResponse(OssControl *ctl, SBC_AP_PDU *request, SBC_AP_PDU **response);

#endif