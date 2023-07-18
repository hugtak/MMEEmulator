#ifndef SCTP_FUNC_H
#define SCTP_FUNC_H

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "Sbc_func.h"


/*Defines*/
#define MAXBUFFER 1024
#define TIMEOUTSEC 0
#define TIMEOUTUSEC 100000
#define CLOSESOCKET(s) close(s)
#define SOCKET int


/*Functions*/
SOCKET socket_sctp();
int connect_sctp(char *IP, char *PORT, SOCKET socket_peer);
int recv_sctp(SOCKET socket_peer, unsigned char* msg);
FILE * openFile(const char *path);
FILE * openHexFile(const char *path);
long  readFile(unsigned char **mensagem, const char *path);
int send_sctp(SOCKET socket_peer);
int sctp_close_connection(SOCKET socket_peer);
int accept_sctp(SOCKET socket_listen);
void bind_sctp(SOCKET socket_listen);

#endif