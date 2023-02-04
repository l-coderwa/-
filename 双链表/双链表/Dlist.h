#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDateType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDateType data;
}LD;

LD* ListInit();
void ListDestroy(LD* phead);
void ListPrint(LD* phead);

void ListPushFront(LD* phead, LTDateType x);
void ListPushBack(LD* phead, LTDateType x);
void ListPopFront(LD* pehad);
void ListPopBack(LD* phead);
bool ListEmpty(LD* phead);

size_t ListSize(LD* phead);
LD* ListFind(LD* phead,LTDateType x);


void ListInsert(LD* pos, LTDateType x);

void ListErase(LD* pos);