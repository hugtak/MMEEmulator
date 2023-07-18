#include "Principal.h"
extern const char *Criticalities[];
extern char *filesDir;
/*
 * Main application routine
 */


int main(int argc, char *argv[])
{
	int retcode, socket_listen=-1;
    try {

	sbcap_Control ctl;

	/* Set the encoding rules and encoding/decoding flags */
	ctl.setEncodingRules(OSS_PER_ALIGNED);
	ctl.setEncodingFlags(AUTOMATIC_ENCDEC);
	ctl.setDecodingFlags(AUTOMATIC_ENCDEC);
	ctl.setDebugFlags(PRINT_ERROR_MESSAGES | PRINT_DECODING_DETAILS |
		PRINT_ENCODING_DETAILS);
    
    
    /*Criando socket*/
    SOCKET socket_listen = socket_sctp();

    /*Vinculando o socket com IP e porta definidos*/
    bind_sctp(socket_listen);


    /*Esperando por conexão no protocolo SCTP*/
    if(listen(socket_listen, 1)<0){ 
        printf("\nlisten() falhou");
        return 1;
    }


    /*Conjunto dos sockets*/
    fd_set master;
    FD_ZERO(&master);//Limpando conjunto de sockets
    FD_SET(socket_listen, &master);
    SOCKET max_socket = socket_listen;//Como teremos vários sockets temos sempre que saber o valor do maior para a função select()


    printf("\nEsperando por conexões...\n");

    while(1){
        fd_set reads;
        reads = master;
        if(select(max_socket+1, &reads, 0, 0, 0)<0){ /*Select() serve como uma multiplexação de sockets*/
            printf("\nselect() falhou");
            return 1;
        }
        SOCKET i;
        for(i=1; i<=max_socket; ++i){
            if(FD_ISSET(i, &reads)){
                if(i == socket_listen){
                    SOCKET socket_client = accept_sctp(socket_listen); /*Aceitando novas conexões*/
                    FD_SET(socket_client, &master);
                    if(socket_client>max_socket) /*Atualizando o valor do max_socket*/
                        max_socket= socket_client;
                }else{
                    /*Getting information from the client*/
                    unsigned char msg[MAXBUFFER];
                    int bytes_received = recv_sctp(i, msg);
                    printf("Receiving data...\n");
                    writeEncodingFileMsg("MME_WriteReplaceWarningRequest_bin.per", msg, bytes_received);
                    printf("Data received\n");
                    /*Sending the response*/
                    EncodedBuffer *encoded_request;
                    SBC_AP_PDU_PDU pdu;
                    SBC_AP_PDU *request, *response;
                    EncodedBuffer encoded_response;
                    encoded_request = readEncodingFromFile("MME_WriteReplaceWarningRequest_bin.per");
                    try {
                        pdu.decode(ctl, *encoded_request);
                        /* Free memory allocated for encoded message */
	                    delete encoded_request;
	                    encoded_request = NULL;
                        request = pdu.get_data();
                        createSuccessResponse(&ctl, request, &response);
                        pdu.free_data(ctl);
                        pdu.set_data(*response);
                        pdu.print(ctl);
                        /* Free memory allocated for outcome message */
                        writeEncodingFile("MME_WriteReplaceWarningResponse_bin.per" ,(OssControl*) &ctl, pdu);
                        delete response;
                        fflush(stdout);
                    }catch(...){
                        	delete encoded_request;
	                        throw;
                    }
                    unsigned char *mensagem = NULL;
                    int tamanho = readFile(&mensagem, "MME_WriteReplaceWarningResponse_bin.per");
                    if(mensagem){
                        int bytes_sent = send(i, mensagem, tamanho, 0);
                        free(mensagem);
                    }
                }

            }

        }
    }

    retcode = sctp_close_connection(socket_listen);


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
