#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDatatype;
typedef struct SlitsNode
{
	struct SlistNode* next;
	SLDatatype data;

}SLNode;

void SLprint(SLNode* phead);

void SLPushBack(SLNode** pphead, SLDatatype x);

void SLPushFront(SLNode** pphead, SLDatatype x);

void SLPopFront(SLNode** pphead);
void SLPopBack(SLNode** pphead);

SLNode* SLFind(SLNode* pphead, SLDatatype x);

void SLInsert(SLNode** pphead, SLNode* pos, SLDatatype x);
void SLInsertAfter(SLNode** pphead, SLNode* pos, SLDatatype x);
