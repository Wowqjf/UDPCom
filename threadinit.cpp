#include "threadinit.h"
#include "udp.h"
#include <pthread.h>
#include <sys/prctl.h>

extern int g_sockfd;

void create_recv_thread()
{
    int ret = 0;
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    ret = pthread_create(&thread,&attr,recv_Thread,NULL);
    if(0 != ret)
    {
        printf("create recv thread error\n");
        return;
    }
}

void create_send_thread()
{
    int ret = 0;
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    ret = pthread_create(&thread,&attr,send_Thread,NULL);
    if(0 != ret)
    {
        printf("create send thread error\n");
        return;
    }
}

void* recv_Thread(void*)
{
    prctl(PR_SET_NAME,"recvthread");
    int sockfd = g_sockfd;
    //if( create_UDP(&sockfd,RECV_PORT) )
    if(0 != sockfd )
    {

    }
    else
    {
        printf("create_UDP error\n");
        return NULL;
    }

    set_broadcast(sockfd);
    set_timeout(sockfd, 1);
    
    sockaddr_in staddr;
    
    printf("start recving\n");
    for(;;)
    {
        MSG_BUF_S stBuf;
        stBuf.length = MAX_BUF_LEN;
        socklen_t len = sizeof(struct sockaddr);
        char *buf = stBuf.buf;
        size_t size = recvfrom(sockfd, buf,MAX_BUF_LEN,0,(sockaddr*)&staddr,&len);
        //printf("recv size = %ld\n",size);
    }
    return NULL;
}

void* send_Thread(void*)
{
    prctl(PR_SET_NAME,"sendthread");
    int sockfd = g_sockfd;
    if( sockfd != 0 )
    {

    }
    else
    {
        printf("create_UDP send error\n");
        return NULL;
    }

    set_broadcast(sockfd);

    
    MSG_BUF_S *pstBuf = new MSG_BUF_S;
    memset(pstBuf->buf, 0,MAX_BUF_LEN);
    pstBuf->length = MAX_BUF_LEN;

    sprintf(pstBuf->buf, "Hello");
    sockaddr_in staddr;
    init_sockaddr(RECV_PORT,"255.255.255.255",&staddr);
    
    printf("start sending\n");
    for(;;)
    {
        socklen_t len = sizeof(struct sockaddr);
        char *buf = pstBuf->buf;
        size_t size = sendto(sockfd, buf,MAX_BUF_LEN,0,(sockaddr*)&staddr,len);
        //printf("send size = %ld\n",size);
        usleep(500);
    }
    return NULL;
}
