#include "Sctp_func.h"
extern const char *Criticalities[];
extern char *filesDir;



/*Creates a socket for SCTP, IPV4 in stream mode and handles errors*/
SOCKET socket_sctp(){
	SOCKET socket_ret;
    socket_ret = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
    if(socket_ret == -1) exit(SOCKETERROR);
    return socket_ret;
}



/*Receives IP, port and an active socket and connects it to the server in question*/
int connect_sctp(char *IP, char *PORT, SOCKET socket_peer){
    struct sockaddr_in remote_peer;
    memset(&remote_peer, 0, sizeof(remote_peer));
    remote_peer.sin_family = AF_INET;
    remote_peer.sin_addr.s_addr = inet_addr(IP);
    remote_peer.sin_port = htons(atoi(PORT));
    if(connect(socket_peer, (struct sockaddr *) &remote_peer, sizeof(remote_peer)) < 0) exit(CONNECTERROR);
    printBorder();
    printf("Connected\n");
    printBorder();
    fflush(stdout);
    return 0;
}
/*Makes the link between the socket and the IP address and server port*/
void bind_sctp(SOCKET socket_listen){
    struct sockaddr_in local_address;
    memset(&local_address, 0, sizeof(local_address));
    local_address.sin_family = AF_INET;
    local_address.sin_addr.s_addr = htonl(INADDR_ANY);
    local_address.sin_port = htons(29168);
    if(bind(socket_listen, (struct sockaddr *) &local_address, sizeof(local_address)) <0){
        printf("\nbind() falhou");
        exit(-1);
    }
}


/*Accepts new connections and prints the address on the screen*/
int accept_sctp(SOCKET socket_listen){
    struct sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);
    memset(&client_address, 0, sizeof(client_address));
    SOCKET socket_client = accept(socket_listen, (struct sockaddr *) &client_address, &client_len);
    if(socket_client<0){
        printf("\naccept() falhou");
        return 1;                   
    }
    char address_buffer[100];
    getnameinfo((struct sockaddr *) &client_address, (unsigned int) sizeof(client_address), address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST);
    printf("\nNova conexão de %s\n", address_buffer);
    return socket_client;  
}


/*Receives data from the server and returns the number of bytes received*/
int recv_sctp(SOCKET socket_peer, unsigned char* msg){
    int bytes_received = recv(socket_peer, msg, MAXBUFFER, 0);
    if (bytes_received<1) exit(RECVERROR);
    return bytes_received;
}



/*Open file for reading*/
FILE * openFile(const char *path)
{
    FILE *fv = NULL;
    if (!(fv = fopen(path, "rb"))) {
	printf("Failed to open the '%s' file. Restart the sample program using the file "
		"location as the input parameter.\n", path);
        fflush(stdout);
        exit(FILEERROR);
    }
    return fv;
}



/*Open hexa file for reading*/
FILE * openHexFile(const char *path)
{
    FILE *fv;
    if (!(fv = fopen(path, "r"))) {
	printf("Failed to open the '%s' file. Restart the sample program using the file "
		"location as the input parameter.\n", path);
        fflush(stdout);
        exit(FILEERROR);
    }
    return fv;
}



/*Get bits from a .per file from asn1*/
long  readFile(unsigned char **mensagem, const char *path){
    FILE *file = openFile(path);
    fseek(file, 0, SEEK_END);
    long tamanho = ftell(file);
    fseek(file, 0, SEEK_SET);
    *mensagem = (unsigned char*) calloc(tamanho,sizeof(unsigned char));
    if(!mensagem){
        exit(ALLOCERROR);
    }
    int resultado = fread(*mensagem, sizeof(unsigned char), tamanho, file);
    if(file) fclose(file);
    if(resultado==tamanho) return tamanho;
    exit(FILEERROR);
    //Remember to deallocate the message...
}



/*Sends data to the server and returns the number of bytes sent*/
int send_sctp(SOCKET socket_peer){
    int bytes_sent=-1;
    char msg[MAXBUFFER];
    fflush(stdin);
    getchar();
    if(!fgets(msg, MAXBUFFER, stdin)) exit(FGETSERROR);
    fflush(stdin);
    unsigned char *mensagem = NULL;
    int tamanho = readFile(&mensagem, "HugTak_WriteReplaceWarningRequest_bin.per");
    if(mensagem){
        bytes_sent = send(socket_peer, mensagem, tamanho, 0);
        free(mensagem);
    }
    return bytes_sent;
}


/*Closes a sctp connection*/
int sctp_close_connection(SOCKET socket_peer){
    int retcode = 0;
    if(socket_peer>=0){
        CLOSESOCKET(socket_peer);
        printf("Closed\n");
    }
    return retcode;
}