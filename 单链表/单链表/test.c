#define _CRT_SECURE_NO_WARNINGS 1
#include"slist.h"

void TestList()
{
	SLNode* plist = NULL;

	SLPushBack(&plist,1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushFront(&plist, 8);
	SLPushFront(&plist, 7);

	SLprint(plist);

	SLPopFront(&plist);
	SLprint(plist);

	SLPopBack(&plist);
	SLprint(plist);

	SLPopBack(&plist);
	SLprint(plist);
}


void TestList2() {
	SLNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushFront(&plist, 8);
	SLPushFront(&plist, 7);

	SLprint(plist);

	SLNode* pos = SLFind(plist, 8);
	if (pos)
	{
		SLInsert(&plist, pos, 10);
	}
	SLprint(plist);


}

void Testlist3()
{

	SLNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushFront(&plist, 8);
	SLPushFront(&plist, 7);

	SLprint(plist);
	SLNode* pos = SLFind(plist, 7);
	if (pos)
	{
		SLInsertAfter(&plist, pos, 100);
	}
	SLprint(plist);
}
int main()
{
	//TestList();
	//TestList2();
	Testlist3();
	return 0;
}