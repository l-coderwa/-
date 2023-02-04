#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"stack.h"

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void Swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
void InsertSort(int* a, int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int j = 0; j < n; j++)
		{
			for (int i = j; i < n - gap; i += gap)
			{
				int end=i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (a[end + gap] < a[end])
					{
						a[end + gap] = a[end];
						end = end - gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n-1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin+1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j-1] > a[j])
			{
				Swap(&a[j-1], &a[j]);
			}
		}
	}
}


int GetMidIndex(int* a, int left, int right)
{
	int mid = (right + left) / 2;
}



int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		while (left < right &&  a[left] <= a[keyi])
		{
			++left;
		}
		if(left<right)
			Swap(&a[left], &a[right]);
	}
	int meeti = left;
	Swap(&a[meeti], &a[keyi]);
	return meeti;
}



int PartSort2(int* a, int left, int right)
{
	int hole = left;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	int keyi = left;

	while (cur <= right)
	{
		if (a[cur] < a[keyi]  && ++prev != cur )
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}


void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	
	if (end - begin <= 8)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int keyi = PartSort3(a, begin, end);
		// [0,keyi-1]  keyi  [keyi+1,end]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}


void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);


		int keyi = PartSort3(a, left, right);

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}