#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"


void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDateType x)
{
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ST* tmp = (ST*)realloc(ps->a,sizeof(ST) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	ps->top--;
}

STDateType StackTop(ST* ps)
{
	assert(ps);

	return ps->a[ps->top-1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;

}

bool StackEmpty(ST* ps)
{
	assert(ps);
	
	return ps->top == 0;
}

