#include "Sbc_func.h"
extern const char *Criticalities[];
extern char *filesDir;
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
 * FUNCTION     intToAsciiLen() returns the length of the Ascii array that will be created
 *
 * PARAMETERS
 * 		number 	the number that will be converted
 */
int intToAsciiLen(int number){
	int len=0;
	while(number){
		number=number/256;
		len++;
	}
	return len;
}
/*
 * FUNCTION     intToAscii() converts an integer value into a string containing that value in Ascii
 *
 * PARAMETERS
 * 		number 	the number that will be converted
 */
unsigned char* intToAscii(int number){
	int lastDig, i=0;
	unsigned char* result;
	i = intToAsciiLen(number);
	result = (unsigned char*) calloc(i, sizeof(unsigned char));
	if(!result)	exit(ALLOCERROR);
	i--;
	while(number){
		if(number>256){
			lastDig=number%256;
			number/=256;
		} 
		else{
		lastDig=number;
		number=0;
		}
		if(i>=0)
		result[i] = lastDig;
		i--;
	}
	return result;
    //Remember to deallocate the result...
}

/*
 * FUNCTION     intToAscii2Bytes() converts an integer value into a string containing that value in Ascii
 *				but the length of the string is 2 bytes
 *
 * PARAMETERS
 * 		number 	the number that will be converted
 */
unsigned char* intToAscii2Bytes(int number){
	int lastDig, i=1;
	unsigned char* result;
	result = (unsigned char*) calloc(2, sizeof(unsigned char));
	if(!result)	exit(ALLOCERROR);
	while(number){
		if(number>256){
			lastDig=number%256;
			number/=256;
		} 
		else{
		lastDig=number;
		number=0;
		}
		if(i>=0)
		result[i] = lastDig;
		i--;
	}
	return result;
    //Remember to deallocate the result...
}

/*
 * FUNCTION     				createRequest() creates a SBC_AP_PDU (Write-Replace Warning Request) using the value passed as parameters
 *
 * PARAMETERS
 * 		ctl 					OSS control variable
 * 		request 				A pointer to a pointer of SBC_AP_PDU
 * 		message_identifier_val,
 * 		serial_number_val,
 * 		repetition_period_val,
 * 		nb_of_broad_val,
 * 		message_content,
 * 		number_of_tais,
 * 		data_scheme_val 		values passed to create the request
 */
void createRequest(OssControl *ctl, SBC_AP_PDU **request, int message_identifier_val, int serial_number_val, int repetition_period_val, 
int nb_of_broad_val, const char *message_content, int number_of_tais = 0, int data_scheme_val = 0, int conc_message_val = 0, int send_indication_val = 0)
{

    SBC_AP_PDU *req; 

	printBorder();
    printf("Creating Request...\n");
	printBorder();


    /* Create a request message object */
    req = new SBC_AP_PDU(); 
    /* Fill it */
    try {
	
	Write_Replace_Warning_Request wrw_req;
	InitiatingMessage initiating_msg;
	Write_Replace_Warning_Request::protocolIEs &req_ies = wrw_req.get_protocolIEs();
	/*
	 * We are filling the response IE list starting from beginning.
	 * However, the OssList class has no function to append a new
	 * component to its tail (it cannot be done efficiently because
	 * of its single-linked list representation). So, we save an OssList
	 * iterator pointing to the last component of the response IE list.
	 */
	OssIndex req_tail = OSS_NOINDEX;
	int len;
	unsigned char * stri=NULL;
	/* Add IEs to initiating message */
	Write_Replace_Warning_Request::protocolIEs::component req_ie;
	
	
	/*Message Identifier*/

	Message_Identifier msg_identifier;
	msg_identifier.set(16, stri = intToAscii2Bytes(message_identifier_val));
	req_ie.set_id(id_Message_Identifier);
	req_ie.set_criticality(reject);
	req_ie.get_value().set_Message_Identifier(msg_identifier);
	req_tail = req_ies.insert_after(req_tail, req_ie);
	if(stri)
	free(stri);

	/*Serial Number*/
	Serial_Number serial_number;
	serial_number.set(16,  stri = intToAscii2Bytes(serial_number_val));
	req_ie.set_id(id_Serial_Number);
	req_ie.set_criticality(reject);
	req_ie.get_value().set_Serial_Number(serial_number);
	req_tail = req_ies.insert_after(req_tail, req_ie);
	if(stri)
	free(stri);
	
	/*Repetition_Period*/
	Repetition_Period rep_period = repetition_period_val;
	req_ie.set_id(id_Repetition_Period);
	req_ie.set_criticality(reject);
	req_ie.get_value().set_Repetition_Period(rep_period);
	req_tail = req_ies.insert_after(req_tail, req_ie);
	
	/*Number Of Broadcasts Requested*/
	Number_of_Broadcasts_Requested numb_broad = nb_of_broad_val;
	req_ie.set_id(id_Number_of_Broadcasts_Requested);
	req_ie.set_criticality(reject);
	req_ie.get_value().set_Number_of_Broadcasts_Requested(numb_broad);
	req_tail = req_ies.insert_after(req_tail, req_ie);
	
	/*Warning Message Contents*/
	Warning_Message_Content wrn_message;
	wrn_message.set(strlen(message_content+1)+1,message_content);
	req_ie.set_id(id_Warning_Message_Content);
	req_ie.set_criticality(ignore);
	req_ie.get_value().set_Warning_Message_Content(wrn_message);
	req_tail = req_ies.insert_after(req_tail, req_ie);

		
	/*List of TAIs*/
	if(number_of_tais){
        OssIndex tai_tail = OSS_NOINDEX; 
        List_of_TAIs tai_list;//List of TAIs

        
        for(int index_tai = 1; index_tai<=number_of_tais; index_tai++){
            List_of_TAIs::component tai;//TAIs
            TAI tai_field;//Valores dos TAIs (tAC, plMNidentity)
            OssString plMNidentity;
            OssString tAC;
            tAC.set(2, "10");
            plMNidentity.set(3, "abc");
            tai_field.set_pLMNidentity(plMNidentity);
            tai_field.set_tAC(tAC);
            tai.set_tai(tai_field);
            tai_tail= tai_list.insert_after(tai_tail, tai);
        }
        req_ie.set_id(id_List_of_TAIs);
        req_ie.set_criticality(reject);
        req_ie.get_value().set_List_of_TAIs(tai_list);
        req_tail = req_ies.insert_after(req_tail, req_ie);
	}

	/*Data Coding Scheme*/
	if(data_scheme_val){
        Data_Coding_Scheme data_scheme;
        data_scheme.set(8, intToAscii(data_scheme_val));
        req_ie.set_id(id_Data_Coding_Scheme);
        req_ie.set_criticality(ignore);
        req_ie.get_value().set_Data_Coding_Scheme(data_scheme);
        req_tail = req_ies.insert_after(req_tail, req_ie);
	}

    /*Concurrent Warning Message Indicator*/
    if(conc_message_val){
        Concurrent_Warning_Message_Indicator conc_msg;
        req_ie.set_id(id_Concurrent_Warning_Message_Indicator);
        req_ie.set_criticality(reject);
        req_ie.get_value().set_Concurrent_Warning_Message_Indicator(conc_msg);
        req_tail = req_ies.insert_after(req_tail, req_ie);
    }

    /*Send Write Replace Warning Indication*/
    if(send_indication_val){
        Send_Write_Replace_Warning_Indication send_indication;
        req_ie.set_id(id_Send_Write_Replace_Warning_Indication);
        req_ie.set_criticality(ignore);
        req_ie.get_value().set_Send_Write_Replace_Warning_Indication(send_indication);
        req_tail = req_ies.insert_after(req_tail, req_ie);
    }
	/* Construct a request message from the IE list */
	initiating_msg.set_procedureCode(0); //Não achei a definição dos procedureCodes então coloquei direto 0 que é a do WRWR...
	initiating_msg.set_criticality(reject);
	initiating_msg.get_value().set_Write_Replace_Warning_Request(wrw_req);
	req->set_initiatingMessage(initiating_msg);
	*request = req;


	printf("Request created successfully\n");
	printBorder();

    } catch (...) {
	/*Cleanup*/
	delete req;
	throw;
    }
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
FILE * openOutputFile(char *directoryName, const char *fileName)
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

    if (!(fv = fopen(path, "wb"))) {
	printf("Failed to open the '%s' file. Restart the sample program using the file "
		"location as the input parameter.\n", path);
        exit(FILEERROR);
    }

    if (path != fileName)
	asn1Free(path);

    return fv;
}


/*
 * FUNCTION     writedEncodingFile() writes serialized message on specified
 *              file
 *
 * PARAMETERS
 *    	filename  name of file 
 *		ctl		  OSS control variable
 *		pdu		  SBC_AP_PDU that contains the request created before
 */
void writeEncodingFile(const char *filename, OssControl *ctl, SBC_AP_PDU_PDU pdu)
{
    unsigned long length;
    FILE *out = NULL;
	EncodedBuffer encoded_request;
    try {
	/* Open the file */
	out = openOutputFile(filesDir, filename);
	if (!out)
	    throw NonASN1Exception(strerror(errno), errno);
	pdu.print(*ctl);
	length = pdu.determineEncodingLength(*ctl);
	printf("Length: %d\n", (int) length);
	printBorder();
	pdu.encode(*ctl, encoded_request);
	length = encoded_request.get_length();
	printf("Encoded request:\n");
	fflush(stdout);
	encoded_request.print_hex(*ctl);
	printBorder();


	/* Write the file */
	if (length != (long)fwrite(encoded_request.get_data(), sizeof(char), length, out))
	    throw NonASN1Exception("Error writing the file", 0);
	fclose(out);
	/* Pass the read buffer to the EncodedBuffer */
    } catch (...) {
	if (out)
	    fclose(out);
	throw;
    }
}
/*
 * FUNCTION     writedEncodingFileMsg() writes serialized message on specified
 *              file
 *
 * PARAMETERS
 *    	filename  name of file
 * 		msg 	  the message to be saved
 */
void writeEncodingFileMsg(const char *filename, unsigned char *msg, long length)
{
    FILE *out = NULL;

    try {
	/* Open the file */
	out = openOutputFile(filesDir, filename);
	if (!out)
	    throw NonASN1Exception(strerror(errno), errno);

	/* Write the file */
	if (length != (long)fwrite(msg, sizeof(char), length, out))
	    throw NonASN1Exception("Error writing the file", 0);
	fclose(out);
	/* Pass the read buffer to the EncodedBuffer */
    } catch (...) {
	if (out)
	    fclose(out);
	throw;
    }
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
        exit(FILEERROR);
    }

    if (path != fileName)
	asn1Free(path);

    return fv;
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
FILE * openRequestFile(char *directoryName, const char *fileName)
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

    if (!(fv = fopen(path, "r"))) {
	printf("Failed to open the '%s' file. Restart the sample program using the file "
		"location as the input parameter.\n", path);
        exit(FILEERROR);
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
EncodedBuffer *readEncodingFromFile(const char *filename)
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
 * FUNCTION     testWRWRequest() creates and save a request message with the passed values.
 *
 * PARAMETERS
 *    ctl       OSS control object
 */
void WRWRequest(OssControl *ctl)
{
    SBC_AP_PDU_PDU pdu;
    SBC_AP_PDU *request;

  
    try {

	/* Access components of the message */
	int msg_id, serial, rep_per, nb_broad, tais, data_scheme, conc_msg, send_indication;
	char msg_content[180];
    msg_content[0]= 0;
	int retcode=0;
    FILE *in = openRequestFile(filesDir, "requestData.txt");
    retcode = fscanf(in, "%d;%d;%d;%d;%d;%d;%d;%d;%[^\n]", &msg_id, &serial, &rep_per, &nb_broad, &tais, &data_scheme, &conc_msg, &send_indication, msg_content+1);
    printf("\nCreating a request with the following information:");
    printf("\nMessage Identifier:\t\t%d", msg_id);
    printf("\nSerial Number:\t\t\t%d", serial);
    printf("\nRepetition Period:\t\t%d", rep_per);
    printf("\nNumber of Broadcasts Requested:\t%d", nb_broad);
    printf("\nNumber of Tais:\t\t\t%d", tais);
    printf("\nData Scheme:\t\t\t%d", data_scheme);
    printf("\nMessage Content:\t\t%s", msg_content+1);
    printf("\nConcurrent Message Indicator:\t%s", conc_msg==1?"TRUE":"FALSE");
    printf("\nSend Indication:\t\t%s\n", send_indication==1?"TRUE":"FALSE");

    if(retcode == 9){

	createRequest(ctl, &request, msg_id, serial, rep_per, nb_broad, (const char*)  msg_content, tais, data_scheme, conc_msg, send_indication);
	pdu.set_data(*request);
	writeEncodingFile("HugTak_WriteReplaceWarningRequest_bin.per", ctl, pdu);

	/* Free memory allocated for initiating message */
	delete request;
    }else{
        exit(SCANFERROR);
    }

    fclose(in);
    } catch (...) {

	throw;
    }
}
