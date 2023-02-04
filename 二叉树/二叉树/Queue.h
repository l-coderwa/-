#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


typedef BTNode* QEDataType;
typedef struct QListNode
{
	struct Queue* next;
	QEDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* rear;
	int size;
}QE;

void QueueInit(QE* q);
void QueuePush(QE* q, QEDataType x);
void QueuePop(QE* q);

bool QueueEmpty(QE* q);

QEDataType QueueTop(QE* q);

QEDataType QueueBack(QE* q);

int QueueSize(QE* q);

void QueueDestroy(QE* q);