#pragma once

#include <stdlib.h>



typedef struct SLL_NODE{
	SLL_NODE *next;
	void *SLLNODE;
}SLL_NODE_S;

typedef struct SINGLE_LIST{
	SLL_NODE_S *next;
}SLL_HEAD_S;

SLL_HEAD_S *SLL_Create_Head();

SLL_HEAD_S* SLL_Insert_ToTail(SLL_HEAD_S *head, SLL_NODE_S *node);

SLL_NODE_S* SLL_Get_Tail(SLL_HEAD_S *head);
