#define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"


SLNode* BuySLNode(SLDatatype x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;

}
void SLprint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}

void SLPushBack(SLNode** pphead, SLDatatype x)
{
	SLNode* newnode = BuySLNode(x);
	if ((*pphead)== NULL)
	{
		(*pphead)= newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next= newnode;
		newnode->next = NULL;
	}
}

void SLPushFront(SLNode** pphead, SLDatatype x)
{
	assert(pphead);

	SLNode* newnode = BuySLNode(x);
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->next = *pphead;
	*pphead = newnode;
}

// ͷɾ
void SLPopFront(SLNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}

	SLNode* dele = *pphead;
	*pphead = (*pphead)->next;
	free(dele);
	dele = NULL;
}

// βɾ

void SLPopBack(SLNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		return;
	}

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		(*pphead)= NULL;
	}
	else
	{
		SLNode* tail = (*pphead)->next;
		SLNode* prev = *pphead;
		while (tail->next)
		{
			tail = tail->next;
			prev = prev->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
SLNode* SLFind(SLNode* pphead, SLDatatype x)
{
	SLNode* cur = pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void SLInsert(SLNode** pphead, SLNode* pos, SLDatatype x)
{
	SLNode* newnode = BuySLNode(x);
	SLNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = newnode;
	newnode->next = pos;
}


void SLInsertAfter(SLNode** pphead, SLNode* pos, SLDatatype x)
{
	assert(pos);
	SLNode* newnode = BuySLNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLdestroy(SLNode** pphead)
{
	assert(pphead);

	SLNode* cur = pphead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}