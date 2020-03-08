#pragma once

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

const int MAX_BUF_LEN = 1024;
const int MAX_NAME_LEN = 50;

const int BIND_PORT  = 8088;
const int RECV_PORT  = 9099;

typedef struct MSG_BUF{
    char buf[MAX_BUF_LEN];
    unsigned long length;
}MSG_BUF_S;

typedef struct USER_INFO{
	char name[MAX_NAME_LEN];
	unsigned long userid;
}USER_INFO_S;

bool create_UDP(int *psocketfd, int port);

int set_broadcast(int sockfd);

int udp_write_to(int sockfd,MSG_BUF_S *pstBuf, const sockaddr_in *pstaddr);

void init_sockaddr(int port, const char *cp, sockaddr_in *pstaddr);

int set_timeout(int sockfd, long int time_sec);
