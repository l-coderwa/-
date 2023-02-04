#define _CRT_SECURE_NO_WARNINGS 1

#include"Dlist.h"

LD* ListInit()
{
	LD* guard = (LD*)malloc(sizeof(LD));
	if (guard == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	guard->next = guard;
	guard->prev = guard;

	return guard;
}


void ListPrint(LD* phead)
{
	assert(phead);
	printf("phead<=>");
	LD* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

LD* BuyListNode(LTDateType x)
{
	LD* newnode = (LD*)malloc(sizeof(LD));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}


void ListPushFront(LD* phead,LTDateType x)
{
	assert(phead);
	LD* newnode = BuyListNode(x);
	LD* next = phead->next;
	phead->next = newnode;
	newnode->next = next;
	next->prev = newnode;
	newnode->prev = phead;
	
}

void ListPushBack(LD* phead, LTDateType x)
{
	assert(phead);
	LD* newnode = BuyListNode(x);
	LD* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPopFront(LD* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	LD* cur = phead->next;
	LD* next = cur->next;
	phead->next = next;
	next->prev = phead;
	free(cur);
	cur = NULL;
}

void ListPopBack(LD* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	LD* tail = phead->prev;
	LD* prev = tail->prev;
	free(tail);
	tail->next = NULL;
	prev->next = phead;
	phead->prev = prev;
}

void ListDestroy(LD* phead)
{
	assert(phead);
	if (phead->next == phead)
	{
		free(phead);
		phead = NULL;
	}
	else
	{
		LD* cur = phead->next;
		while (cur != phead)
		{
			LD* del = cur;
			free(del);
			del = NULL;
			cur = cur->next;
		}
		free(phead);
		phead = NULL;
	}
}



size_t ListSize(LD* phead)
{
	assert(phead);
	size_t n = 0;
	LD* cur = phead->next;
	while (cur != phead)
	{
		++n;
		cur = cur->next;
	}
	return n;
}

LD* ListFind(LD* phead, LTDateType x)
{
	assert(phead);
	assert(!ListEmpty(phead));
	LD* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;

}

bool ListEmpty(LD* phead)
{
	assert(phead);
	return phead->next == phead;
}


void ListInsert(LD* pos, LTDateType x)
{
	assert(pos);

	LD* newnode = BuyListNode(x);

	pos->prev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = pos->prev;

}


void ListErase(LD* pos) {
	assert(pos);

	LD* prev = pos->prev;
	LD* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}