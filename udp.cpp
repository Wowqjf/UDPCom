#include "udp.h"


bool create_UDP(int *psocketfd, int port)
{
    int ret = -1;
    *psocketfd = socket(AF_INET, SOCK_DGRAM,IPPROTO_UDP);

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if( -1 != *psocketfd)
    {
        ret = bind(*psocketfd, (struct sockaddr*)(&addr), sizeof(sockaddr));
    }
    if(ret != -1)
    {
        return true;
    }
    return false;
    
}

int set_broadcast(int sockfd)
{
    int opt = 1;
    int ret = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (char*)&opt, sizeof(opt));
    return ret;
}

int set_timeout(int sockfd, long int time_sec)
{
    struct timeval timeout;
    timeout.tv_sec = time_sec;
    timeout.tv_usec = 0;
    int ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,&timeout, sizeof(timeout));
    return ret;
}

int udp_write_to(int sockfd,MSG_BUF_S *pstBuf, const sockaddr_in *pstaddr)
{
    char * buf = pstBuf->buf;
    size_t len = pstBuf->length;
    int ret = 0;
    ret = sendto(sockfd,buf,len,0, (sockaddr*)pstaddr,sizeof(sockaddr_in));
    return ret;
}

void init_sockaddr(int port, const char *cp, sockaddr_in *pstaddr)
{
    in_addr_t addr = inet_addr(cp);
    pstaddr->sin_family = AF_INET;
    pstaddr->sin_port = htons(port);
    pstaddr->sin_addr.s_addr = htonl(addr);
}

