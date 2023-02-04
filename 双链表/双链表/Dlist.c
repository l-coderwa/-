#define _CRT_SECURE_NO_WARNINGS 1
#include"Dlist.h"

void TestList()
{
	LD* plist = ListInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushBack(plist, 30);
	ListPushBack(plist, 40);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListDestroy(plist);

}

void TestList1()
{
	LD* plist = ListInit();

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushBack(plist, 30);
	ListPushBack(plist, 40);

	LD* pos = ListFind(plist, 30);

	if (pos)
	{
		ListInsert(pos, 100);
	}
	ListPrint(plist);

	ListDestroy(plist);
}


void TestList2()
{
	LD* plist = ListInit();

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushBack(plist, 30);
	ListPushBack(plist, 40);

	LD* pos = ListFind(plist, 30);

	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);

	ListDestroy(plist);
}
int main()
{
	//TestList();

	//TestList1();

	TestList2();

	return 0;
}