/*****************************************************************************/
/*  Copyright (C) 2022 OSS Nokalva, Inc.  All rights reserved.               */
/*****************************************************************************/
/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.                    */
/* AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.             */
/* THIS FILE MAY NOT BE DISTRIBUTED.                                         */
/* THIS COPYRIGHT STATEMENT MAY NOT BE REMOVED.                              */
/* THIS SAMPLE PROGRAM IS PROVIDED AS IS. THE SAMPLE PROGRAM AND ANY RESULTS */
/* OBTAINED FROM IT ARE PROVIDED WITHOUT ANY WARRANTIES OR REPRESENTATIONS,  */
/* EXPRESS, IMPLIED OR STATUTORY.                                            */
/*****************************************************************************/
/*
 * $Id: ca14e8bdd8a83e882b4c8159c1eb85bd7a8baf10 $
 */

/*
 * A demonstrative example for handling 3GPP LTE SBCAP protocol data in ASN.1/C++
 */
#include <errno.h>
#include "sbcap.h"

/* Names of Criticality values */
static const char *Criticalities[] = { "reject", "ignore", "notify" };

char *filesDir; /* The directory where input files reside. It is set to the
		 * command line parameter if any and to the directory where
		 * the sample is started, otherwise.
		 */

/*
 * Auxiliary function to make output prettier.
 */
void printBorder()
{
    printf("-------------------------------------------------------\n");
}


/*
 * A simple class used to report non-ASN.1/C++ errors (such as a failure to
 * create a socket) to the application. You may use any alternative error
 * handling if you wish.
 */

class NonASN1Exception {
private:
    const char *message;	/* can contain C format specifications */
    const char *extra_data;	/* data handled by fmt. specifications (if any) */
    int errcode;
public:
    NonASN1Exception(const char *msg, int code = 0,
	    const char *extd = NULL);
    NonASN1Exception(const NonASN1Exception & that);
    const char *get_message() const;
    const char *get_extra_data() const;
    int get_errcode() const;
};

NonASN1Exception::NonASN1Exception(const char *msg, int code, const char *extd)
{
    message = msg;
    extra_data = extd;
    errcode = code;
}

NonASN1Exception::NonASN1Exception(const NonASN1Exception & that)
{
    message = that.message;
    errcode = that.errcode;
    extra_data = that.extra_data;
}

const char *NonASN1Exception::get_message() const
{
    return message;
}

const char *NonASN1Exception::get_extra_data() const
{
    return extra_data;
}

int NonASN1Exception::get_errcode() const
{
    return errcode;
}

/*
 * FUNCTION     printHexString() prints data (octet string) as a sequence of
 *              hexadecimal digits 'XXXX...'H
 *
 * PARAMETERS
 *    ctl       ASN.1/C++ control object
 *    value     reference to input data (OssString object)
 */
void printHexString(OssControl *ctl, const OssString &value)
{
    ctl->printHex(value.get_buffer(), value.length());
}

/*
 * FUNCTION     printHexBitString() prints data (bit string) as a sequence of
 *              hexadecimal digits 'XXXX...'H
 *
 * PARAMETERS
 *    ctl       ASN.1/C++ control object
 *    value     reference to input data (OssBitString object)
 */
void printHexBitString(OssControl *ctl, const OssBitString &value)
{
    ctl->printHex((const char *)value.get_buffer(), (value.length() + 7) / 8);
}

/*
 * FUNCTION     Helper function to open file in the specified directory.
 *
 * PARAMETERS
 *     directoryName    directory where fileName resides
 *     fileName         file to open
 *
 * RETURNS      pointer to file on success, NULL on failure
 */
FILE * openInputFile(char *directoryName, const char *fileName)
{
    char *path;
    FILE *fv;
    const char kPathSeparator =
#ifdef _WIN32
				'\\';
#else
				'/';
#endif

    if (directoryName) {
	size_t dLength = strlen(directoryName);

	if (NULL == (path = (char *)asn1Malloc(dLength + strlen(fileName) + 2))) {
	    return NULL;
	}

	memcpy(path, directoryName, dLength);
	if (path[dLength - 1] != kPathSeparator)
	    path[dLength++] = kPathSeparator;
	strcpy(path+dLength, fileName);
    } else {
	path = (char *) fileName;
    }

    if (!(fv = fopen(path, "rb"))) {
	printf("Failed to open the '%s' file. Restart the sample program using the file "
		"location as the input parameter.\n", path);
    }

    if (path != fileName)
	asn1Free(path);

    return fv;
}

/*
 * FUNCTION     readEncodingFromFile() reads serialized message from specified
 *              file
 *
 * PARAMETERS
 *    filename  name of file containing serialized message
 *
 * RETURNS      a pointer to a newly allocated EncodedBuffer object containing
 *              the encoding read from the file
 */
static EncodedBuffer *readEncodingFromFile(const char *filename)
{
    long length;
    FILE *in = NULL;
    unsigned char *data = NULL;
    EncodedBuffer *result = new EncodedBuffer();

    try {
	/* Open the file and determine its length */
	in = openInputFile(filesDir, filename);
	if (!in)
	    throw NonASN1Exception(strerror(errno), errno);
	if (fseek(in, 0, SEEK_END))
	    throw NonASN1Exception(strerror(errno), errno);
	length = ftell(in);
	if (length < 0)
	    throw NonASN1Exception(strerror(errno), errno);

	/*
	 * Allocate memory. We need to use asn1Malloc so we can later pass
	 * the ownership of the allocated memory to the EncodedBuffer object.
	 */
	data = (unsigned char *)asn1Malloc(length);
	if (!data)
	    throw NonASN1Exception("No memory", OUT_MEMORY);

	/* Read the file */
	rewind(in);
	if (length != (long)fread(data, 1, (size_t)length, in))
	    throw NonASN1Exception("Error reading the file", 0);
	fclose(in);

	/* Pass the read buffer to the EncodedBuffer */
	result->grab_buffer(length, (char *)data);
	return result;
    } catch (...) {
	if (in)
	    fclose(in);
	if (data)
	    asn1Free(data);
	delete result;
	throw;
    }
}

/*
 * FUNCTION     printProtocolExtensions() prints ProtocolExtensionContainer
 *              data.
 *
 * PARAMETERS
 *    ctl       OSS control variable
 *    ie_ext    reference to ProtocolExtensionContainer data to print
 *              (NULL is acceptable, in this case the function does nothing)
 *    indent    indentation
 */
static void printProtocolExtensions(OssControl *ctl, Global_ENB_ID::iE_Extensions *ie_ext,
	int indent)
{
    int index;
    /*
     * Different messages use iE_Extensions fields, which all are binary compatible.
     * We intend to use this function for any protocol extension IE list.
     */
    Global_ENB_ID::iE_Extensions::component *ie;
    sbcap_PDU pdu;

    /* Return if there are no extensions */
    if (!ie_ext)
	return;

    printf("%*s%s includes the following IEs:\n", indent++, "", "IE-Extensions");
    /* Print each IE in the list */
    index = 1;
    for (OssIndex i = ie_ext->first(); i != OSS_NOINDEX; i = ie_ext->next(i)) {
	ie = ie_ext->at(i);

	printf("%*s#%d: id = %2u, criticality = %s\n", indent, "",
		index, ie->get_id(), Criticalities[ie->get_criticality()]);
	if (ie->get_extensionValue().has_decoded()) {
	    /* Extract the open type data */
	    ie->get_extensionValue().get_decoded(pdu);
	    /* Print it in a generic way, using ASN.1 value notation */
	    pdu.print(*ctl);
	} else
	    printf("%*s%s", indent, "", "PDU is not decoded\n");
	index++;
    }
}

/*
 * FUNCTION     printProtocolIEs() prints ProtocolIE-Container data.
 *
 * PARAMETERS
 *    ctl       OSS control variable
 *    ies       reference to ProtocolIE-Container data to print
 *    indent    indentation
 */
void printProtocolIEs(OssControl *ctl, Write_Replace_Warning_Request::protocolIEs & ies,
	int indent)
{
    int index = 1;		/* IE's ordinal number */
    Write_Replace_Warning_Request::protocolIEs::component *ie;

    printf("%*s%s includes the following IEs:\n", indent++, "", "WriteReplaceWarningRequest");

    /* For each IE in the SEQUENCE OF */
    for (OssIndex i = ies.first(); i != OSS_NOINDEX; i = ies.next(i)) {
	ie = ies.at(i);
	printf("\n%*s#%d: id = %2u, criticality = %s\n", indent, "",
		index, ie->get_id(), Criticalities[ie->get_criticality()]);

	indent++;
	index++;
	Write_Replace_Warning_Request_IEs_Value & iedata = ie->get_value();

	if (iedata.has_decoded()) {
	    /* If the IE's data are decoded */

	    /* Depending on the IE identifier */
	    switch (ie->get_id()) {
	    case id_Message_Identifier:
		{
		    /* id_Message_Identifier */
		    Message_Identifier *msg_id;

		    msg_id = iedata.get_Message_Identifier();

		    printf("%*svalue %s: ", indent, "", "Message-Identifier");
		    printHexBitString(ctl, *msg_id);
		    printf("\n");
		}
		break;
	    case id_Serial_Number:
		{
		    /* id_Serial_Number */
		    Serial_Number *serial_no;

		    serial_no = iedata.get_Serial_Number();

		    printf("%*svalue %s: ", indent, "", "Serial-Number");
		    printHexBitString(ctl, *serial_no);
		    printf("\n");
		}
		break;
	    case id_List_of_TAIs:
		{
		    /* id_List_of_TAIs */
		    List_of_TAIs *tai_list = iedata.get_List_of_TAIs();
		    List_of_TAIs::component *tai;
		    int idx;

		    printf("%*svalue %s:\n", indent, "", "List-of-TAIs");

		    indent++;
		    idx = 1;

		    for (OssIndex j = tai_list->first(); j != OSS_NOINDEX; j = tai_list->next(j)) {
			tai = tai_list->at(j);
			TAI & tai_field = tai->get_tai();

			printf("\n%*s#%d TAI:\n", indent, "", idx++);

			/* PLMN-Identity */
			printf("%*s%s: ", indent, "", "PLMN-Identity");
			printHexString(ctl, tai_field.get_pLMNidentity());
			/* TAC */
			printf("%*s%s: ", indent, "", "TAC");
			printHexString(ctl, tai_field.get_tAC());
			/* IE Extensions*/
			printProtocolExtensions(ctl, tai_field.get_iE_Extensions(), indent);
		    }
		    indent--;
		}
		break;
	    case id_Warning_Area_List:
		{
		    /* id_Warning_Area_List */
		    Warning_Area_List *warn_area_list = iedata.get_Warning_Area_List();
		    int idx = 1;

		    printf("%*svalue %s", indent, "", "Warning-Area-List choice is:");

		    if (warn_area_list->get_selection() == Warning_Area_List::cell_ID_List_chosen) {
			Warning_Area_List::cell_ID_List *cell_list = warn_area_list->get_cell_ID_List();

			printf(" Cell-ID-List\n");

			if (!cell_list) {
			    printf("\nUnexpected message\n");
			    throw NonASN1Exception("Unsupported message type", -1, NULL);
			}

			indent++;
			for (OssIndex j = cell_list->first(); j != OSS_NOINDEX; j = cell_list->next(j)) {
			    ECGIList::component *ecgi_component = cell_list->at(j);

			    printf("\n%*s#%d Cell_ID:\n", indent++, "", idx++);

			    /* PLMN-Identity */
			    printf("%*s%s: ", indent, "", "PLMN-Identity");
			    printHexString(ctl, ecgi_component->get_pLMNidentity());
			    /* Cell-ID */
			    printf("%*s%s: ", indent, "", "Cell-ID");
			    printHexBitString(ctl, ecgi_component->get_cell_ID());
			    /* IE Extensions*/
			    printProtocolExtensions(ctl, ecgi_component->get_iE_Extensions(), indent);
			    indent--;
			}
			indent--;
		    } else
			printf("%*svalue %s", indent, "", "Unimplemented");
		}
		break;
	    case id_Repetition_Period:
		{
		    /* id_Repetition_Period */
		    Repetition_Period *r_period;

		    r_period = iedata.get_Repetition_Period();
		    printf("%*svalue %s: %u\n", indent, "", "Repetition-Period", *r_period);
		}
		break;
	    case id_Extended_Repetition_Period:
		{
		    /* id_Extended_Repetition_Period */
		    Extended_Repetition_Period *er_period;

		    er_period = iedata.get_Extended_Repetition_Period();
		    printf("%*svalue %s: %u\n", indent, "", "Extended-Repetition-Period",
				*er_period);
		}
		break;

	    case id_Number_of_Broadcasts_Requested:
		{
		    /* id_Number_of_Broadcasts_Requested */
		    Number_of_Broadcasts_Requested *nr_of_broadcasts;

		    nr_of_broadcasts = iedata.get_Number_of_Broadcasts_Requested();
		    printf("%*svalue %s: %u\n", indent, "", "Number-of-Broadcasts-Requested",
				*nr_of_broadcasts);
		}
		break;
	    case id_Warning_Type:
		{
		    /* id_Warning_Type */
		    Warning_Type *warn_type;

		    warn_type = iedata.get_Warning_Type();
		    printf("%*svalue %s: ", indent, "", "Warning-Type");
		    printHexString(ctl, *warn_type);
		    printf("\n");
		}
		break;
	    case id_Warning_Security_Information:
		{
		    /* id_Warning_Security_Information */
		    Warning_Security_Information *warn_secu_info;

		    warn_secu_info = iedata.get_Warning_Security_Information();
		    printf("%*svalue %s: ", indent, "", "Warning-Security-Information");
		    printHexString(ctl, *warn_secu_info);
		    printf("\n");
		}
		break;
	    case id_Data_Coding_Scheme:
		{
		    /* id_Data_Coding_Scheme */
		    Data_Coding_Scheme *data_coding_scheme;

		    data_coding_scheme = iedata.get_Data_Coding_Scheme();
		    printf("%*svalue %s: ", indent, "", "Data-Coding-Scheme");
		    printHexBitString(ctl, *data_coding_scheme);
		    printf("\n");
		}
		break;
	    case id_Warning_Message_Content:
		{
		    /* id_Warning_Message_Content */
		    Warning_Message_Content *warn_msg_content;

		    warn_msg_content = iedata.get_Warning_Message_Content();
		    printf("%*svalue %s: ", indent, "", "Warning-Message-Content");
		    printHexString(ctl, *warn_msg_content);
		    printf("\n");
		}
		break;
	    case id_Omc_Id:
		{
		    /* id_Omc_Id */
		    Omc_Id *omc_id;

		    omc_id = iedata.get_Omc_Id();
		    printf("%*svalue %s: ", indent, "", "Omc-Id");
		    printHexString(ctl, *omc_id);
		    printf("\n");
		}
		break;
	    case id_Concurrent_Warning_Message_Indicator:
		{
		    /* id_Concurrent_Warning_Message_Indicator */
		    Concurrent_Warning_Message_Indicator *cwmi;

		    cwmi = iedata.get_Concurrent_Warning_Message_Indicator();
		    printf("%*svalue %s: %d\n", indent, "",
				"Concurrent-Warning-Message-Indicator", *cwmi);
		}
		break;
	    default:
		/* Any other IE is printed generically, using ASN.1 value notation */
		sbcap_PDU ie_pdu;

		printf("%*s", indent, "");
		iedata.get_decoded(ie_pdu);
		ie_pdu.print(*ctl);
		break;
	    }
	} else {
	    printf("PDU is not decoded\n");
	}
	indent--;
    }
}

/*
 * FUNCTION     printWriteReplaceWarningReqMsg() prints an SBCAP PDU which contains
 *              a WriteReplaceWarningReq message.
 *
 * PARAMETERS
 *    ctl       OSS control variable
 *    request   a pointer to the SBCAP PDU to print (assuming it contains a
 *              WriteReplaceWarningReq message)
 */
void printWriteReplaceWarningReqMsg(OssControl *ctl, SBC_AP_PDU *request)
{
    InitiatingMessage             *initmsg;
    Write_Replace_Warning_Request *wrwr;

    printf("\nDeserialized request printed by the custom function:\n");
    printBorder();

    initmsg = request->get_initiatingMessage();
    if (!initmsg) {
	/* If the message is not an InitiatingMessage */
	printf("Unexpected message id = %d\n", request->get_selection());
	throw NonASN1Exception("Unsupported message type", -1, NULL);
    }

    wrwr = initmsg->get_value().get_Write_Replace_Warning_Request();
    if (!wrwr) {
	/* If the message is not a WriteReplaceWarningReq */
	printf("Unexpected message id = %d\n", initmsg->get_procedureCode());
	throw NonASN1Exception("Unsupported message type", -1, NULL);
    }

    printProtocolIEs(ctl, wrwr->get_protocolIEs(), 0);
}

/*
 * FUNCTION     createSuccessResponse() creates an SBCAP successful outcome
 *              message for a given WriteReplace Warning Request.
 *
 * PARAMETERS
 *    ctl       OSS control object
 *    request   input message (request)
 *    response  pointer to the variable that is to hold the resulting
 *              successful outcome message created by the function
 */
void createSuccessResponse(OssControl *ctl, SBC_AP_PDU *request, SBC_AP_PDU **response)
{
    InitiatingMessage *initmsg;
    Write_Replace_Warning_Request *wrw_req;
    SBC_AP_PDU *resp;

    printf("\nCreating response...");

    initmsg = request->get_initiatingMessage();
    if (!initmsg) {
	/* If the message is not an InitiatingMessage */
	printf("Unexpected message id = %d\n", request->get_selection());
	throw NonASN1Exception("Unsupported message type", -1, NULL);
    }

    wrw_req = initmsg->get_value().get_Write_Replace_Warning_Request();
    if (!wrw_req) {
	/* If the message is not a WriteReplace Waring Request */
	printf("Unexpected message id = %d\n", initmsg->get_procedureCode());
	throw NonASN1Exception("Unsupported message type", -1, NULL);
    }

    /* Create a response message object */
    resp = new SBC_AP_PDU();

    /* Fill it */
    try {
	SuccessfulOutcome outcome_msg;
	Write_Replace_Warning_Response wrw_resp;
	Write_Replace_Warning_Request::protocolIEs &req_ies = wrw_req->get_protocolIEs();
	Write_Replace_Warning_Request::protocolIEs::component *req_ie;
	Write_Replace_Warning_Response::protocolIEs &resp_ies = wrw_resp.get_protocolIEs();
	/*
	 * We are filling the response IE list starting from beginning.
	 * However, the OssList class has no function to append a new
	 * component to its tail (it cannot be done efficiently because
	 * of its single-linked list representation). So, we save an OssList
	 * iterator pointing to the last component of the response IE list.
	 */
	OssIndex resp_tail = OSS_NOINDEX;

	/*
	 * Create successful outcome message from initiating message. Copy
	 * some IEs from input to output.
	 */
	for (OssIndex i = req_ies.first(); i != OSS_NOINDEX;
		i = req_ies.next(i)) {
	    req_ie = req_ies.at(i);
	    if (req_ie->get_id() == (OSS_UINT32)id_Message_Identifier ||
		    req_ie->get_id() == (OSS_UINT32)id_Serial_Number) {
		/* Copy the IE from the request to the response */
		resp_tail = resp_ies.insert_after(resp_tail,
			*(Write_Replace_Warning_Response::protocolIEs::component *)req_ie);
	    }
	}

	/* Add Cause IE to outcome message */
	Write_Replace_Warning_Response::protocolIEs::component resp_ie;
	Cause cause = message_accepted;

	resp_ie.set_id(id_Cause);
	resp_ie.set_criticality(reject);
	resp_ie.get_value().set_Cause(cause);
	resp_tail = resp_ies.insert_after(resp_tail, resp_ie);

	/* Construct a response message from the IE list */
	outcome_msg.set_procedureCode(initmsg->get_procedureCode());
	outcome_msg.set_criticality(reject);
	outcome_msg.get_value().set_Write_Replace_Warning_Response(wrw_resp);
	resp->set_successfulOutcome(outcome_msg);
	*response = resp;

	printf("Response created successfully\n");
	printBorder();
    } catch (...) {
	/* Cleanup */
	delete resp;
	throw;
    }
}

/*
 * FUNCTION     testSBCAP() is used to test SBCAP message, the input serialized
 *              pdu is deserialized and printed, then an outcome message
 *              is created, printed and encoded.
 *
 * PARAMETERS
 *    ctl       OSS control object
 *    filename  name of file containing serialized message
 */
static void testSBCAP(OssControl *ctl, const char *filename)
{
    EncodedBuffer *encoded_request;
    EncodedBuffer encoded_response;
    SBC_AP_PDU_PDU pdu;
    SBC_AP_PDU *request, *response;

    printf("======================================================"
	    "======================\n");
    printf("Reading encoding from file: %s...\n\n", filename);
    /* Read serialized message from file */
    encoded_request = readEncodingFromFile(filename);
    try {
	printf("Deserializing request...\n");
	printBorder();

	/* Decode the input message */
	pdu.decode(*ctl, *encoded_request);

	/* Free memory allocated for encoded message */
	delete encoded_request;
	encoded_request = NULL;

	/* Print the input message in the decoded form */
	printf("\nDeserialized request printed by pdu.print() method\n");
	printBorder();
	pdu.print(*ctl);

	/* Access components of the message */
	request = pdu.get_data();
	printWriteReplaceWarningReqMsg(ctl, request);

	/* Create successful outcome message */
	createSuccessResponse(ctl, request, &response);

	/* Free the decoded input message */
	pdu.free_data(*ctl);

	/* Print the response message */
	printf("\nThe response message printed by pdu.print() method:\n");
	printBorder();
	pdu.set_data(*response);
	pdu.print(*ctl);

	/* Serialize response */
	printf("\nSerializing response...\n");
	printBorder();
	pdu.encode(*ctl, encoded_response);
	printf("\nSerialized response (%lu bytes):\n",
		encoded_response.get_length());
	printBorder();
	encoded_response.print_hex(*ctl);
	printf("\n");

	/* Free memory allocated for outcome message */
	delete response;
    } catch (...) {
	/* Cleanup in case of a possible error */
	delete encoded_request;
	throw;
    }
}

/*
 * Main application routine
 */
int main(int argc, char *argv[])
{
    int retcode;
    filesDir = argc > 1 ? argv[1] : (char *) ".";

    try {
	sbcap_Control ctl;

	/* Set the encoding rules and encoding/decoding flags */
	ctl.setEncodingRules(OSS_PER_ALIGNED);
	ctl.setEncodingFlags(AUTOMATIC_ENCDEC);
	ctl.setDecodingFlags(AUTOMATIC_ENCDEC);
	ctl.setDebugFlags(PRINT_ERROR_MESSAGES | PRINT_DECODING_DETAILS |
		PRINT_ENCODING_DETAILS);

	testSBCAP(&ctl, "SBC-AP-PDU_WriteReplaceWarningRequest_bin.per");
	retcode = 0;
    } catch (ASN1RuntimeException &exc) {
        retcode = exc.get_code();
	printf("An error occurred: code = %d.\n", retcode);
    } catch (NonASN1Exception &exc) {
	printf("NonASN1Exception: ");
	retcode = exc.get_errcode();
	printf(exc.get_message(), exc.get_extra_data(), retcode);
        printf("\n");
        if (!retcode)
	    retcode = -1;
    } catch (...) {
	printf("An unexpected exception occurred.\n");
	retcode =  -1;
    }
    if (!retcode)
	printf("Testing successful.\n");

    return retcode;
}