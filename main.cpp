#include <iostream>
#include "threadinit.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "udp.h"
#include <signal.h>
#include "singleLinkList.h"
int g_sockfd = 0;

void handler(int a)
{
	printf("Bye\n");
	exit(0);
}

typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);

int main()
{
	int pid = getpid();
	printf("pid=%d\n",pid);
	signal(15,handler);
	signal(SIGINT,handler);
	create_UDP(&g_sockfd,RECV_PORT);
	create_recv_thread();
	create_send_thread();

	SLL_HEAD_S *head = NULL;
	head = SLL_Create_Head();

	USER_INFO_S *user_a;
	user_a = new USER_INFO_S;
	memset(user_a,0,sizeof(USER_INFO_S));
	sprintf(user_a->name,"coco");
	SLL_NODE_S *node = new SLL_NODE_S;
	node->SLLNODE = (void*)user_a;
	node->next = NULL;
	
	SLL_Insert_ToTail(head,node);

	printf("head = %p\n",head);
	SLL_NODE_S *tail = SLL_Get_Tail(head);
	USER_INFO_S *info = (USER_INFO_S*)(tail->SLLNODE);
	printf("%s\n",info->name);
	for(;;)
	{
		sleep(1);
	}
	return 0;
}
