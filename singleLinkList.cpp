#include "singleLinkList.h"


SLL_HEAD_S* SLL_Create_Head()
{
	SLL_HEAD_S *head = (SLL_HEAD_S*)malloc(sizeof(SLL_HEAD_S));
	head->next = NULL;
	return head;
}

SLL_HEAD_S *SLL_Insert_ToTail(SLL_HEAD_S*head, SLL_NODE_S *node)
{
	SLL_NODE_S *tail = SLL_Get_Tail(head);
	if(NULL != tail)
	{
		tail->next = node;
		node->next = NULL;
	}
	if(NULL == tail)
	{
		head->next = node;
		node->next = NULL;
	}
	return head;

}

SLL_NODE_S* SLL_Get_Tail(SLL_HEAD_S *head)
{
	if(NULL == head)
	{
		return NULL;
	}
	SLL_NODE_S *tempNode = head->next;
	if(tempNode == NULL)
	{
		return NULL;
	}
	while(NULL != tempNode->next)
	{
		tempNode = tempNode->next;
	}
	return tempNode;
}
