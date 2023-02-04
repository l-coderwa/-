#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void TestStack()
{
	ST plist;
	StackInit(&plist);

	StackPush(&plist, 1);
	StackPush(&plist, 2);

	StackPush(&plist, 3);
	StackPush(&plist, 4);
	StackPop(&plist);
	StackPop(&plist);
	StackPush(&plist, 5);
	StackPush(&plist, 6);
	StackPop(&plist);
	while (!StackEmpty(&plist))
	{
		printf("%d ", StackTop(&plist));
		StackPop(&plist);
	}

	StackDestroy(&plist);
}

int main()
{
	TestStack();
	return 0;
}