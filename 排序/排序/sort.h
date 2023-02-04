#pragma once
#include<stdio.h>
#include<stdlib.h>

void InsertSort(int* a, int n);
void print(int* a, int n);

void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int* a, int begin,int end);
void Swap(int* p, int* q);
void QuickSortNonR(int* a, int left, int right);