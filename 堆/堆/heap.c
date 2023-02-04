#pragma once
#include"heap.h"

void HeapInit(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}


void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HeapAdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		Heap* tmp = (Heap*)realloc(hp->a, sizeof(Heap) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		else
		{
			hp->a = tmp;
			hp->capacity = newcapacity;
		}
	}
	hp->a[hp->size] = x;
	hp->size++;
	HeapAdjustUp(hp->a, hp->size - 1);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	return hp->a[0];
}

void HeapAdjustDown(HPDataType* a, int size,int n)
{
	int parrent = n;
	int minchild = parrent * 2 + 1;
	while (minchild < size)
	{
		if (minchild + 1 < size && a[minchild + 1] > a[minchild])
		{
			minchild = minchild + 1;
		}

		if (a[minchild] > a[parrent])
		{
			Swap(&a[parrent], &a[minchild]);
			parrent = minchild;
			minchild = parrent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	HeapAdjustDown(hp->a, hp->size,0);
}

bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

