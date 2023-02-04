#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

int main()
{
	int a[] = {33,22,55,44,5,4,9,10};
	int n = sizeof(a) / sizeof(int);
	//InsertSort(a, n);
	//print(a, n);
	/*ShellSort(a, n);
	print(a, n);*/

	//SelectSort(a, n);
	//print(a, n);

	QuickSortNonR(a, 0,n-1);
	print(a, n);
	return 0;
}