#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

//void TestHeap()
//{
//	Heap hp;
//	HeapInit(&hp);
//
//	int a[] = { 15,18,19,25,28,34,65,49,27,37,10 };
//	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//}
//int main()
//{
//	//TestHeap();
//	int a[] = { 65, 100, 70, 32, 50, 60 };
//	Heap hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	//HeapPush(&hp, 10);
//	//HeapPrint(&hp);
//
//	//HeapPop(&hp);
//	//HeapPrint(&hp);
//
//	//HeapPop(&hp);
//	//HeapPrint(&hp);
//
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	return 0;
//}


void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		HeapAdjustDown(a, n, i);
	}
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		HeapAdjustDown(a, n - i, 0);
		++i;
	}
}

void CreateDataFile(const char* filename, int N)
{
	FILE* fin = fopen(filename, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	srand(time(0));

	for (int i = 0; i < N; ++i)
	{
		fprintf(fin, "%d\n", rand() % 1000000);
	}

	fclose(fin);
}

void PrintTopK(const char* filename, int k)
{
	assert(filename);

	FILE* fout = fopen(filename, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc fail");
		return;
	}
	// 如何读取前K个数据
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}

	// 建k个数小堆
	for (int j = (k - 2) / 2; j >= 0; --j)
	{
		HeapAdjustDown(minHeap, k, j);
	}

	// 继续读取后N-K
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			HeapAdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", minHeap[i]);
	}

	free(minHeap);
	fclose(fout);
}

int main()
{
	const char* filename = "Data.txt";
	int N = 10000;
	int K = 10;
	//CreateDataFile(filename, N);
	PrintTopK(filename, K);

	return 0;
}