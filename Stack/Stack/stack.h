#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDateType;

typedef struct Stack
{
	STDateType* a;
	int top;
	int capacity;
}ST;


void StackInit(ST* ps);
void StackDestroy(ST* ps);

void StackPush(ST* ps, STDateType x);

void StackPop(ST* ps);

STDateType StackTop(ST* ps);

int StackSize(ST* ps);


bool StackEmpty(ST* ps);
