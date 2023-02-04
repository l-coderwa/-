#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp);

void HeapPrint(Heap* hp);

void HeapDestroy(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);

bool HeapEmpty(Heap* ph);

void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp);

void HeapAdjustDown(HPDataType* a, int size, int n);

void HeapAdjustUp(HPDataType* a, int child);

void Swap(HPDataType* p1, HPDataType* p2);