#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QueueInit(QE* q)
{
	assert(q);
	q->head = q->rear = NULL;
	q->size = 0;
}

void QueuePush(QE* q, QEDataType x)
{
	assert(q);
	QNode* newnode = (QE*)malloc(sizeof(QE));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	if (q->rear == NULL)
	{
		q->rear = q->head = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}

void QueuePop(QE* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->rear = NULL;

	}
	else
	{
		QNode* cur = q->head;
		q->head = q->head->next;
		free(cur);
		cur = NULL;
	}
	q->size--;

}


QEDataType QueueTop(QE* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->data;
}


QEDataType QueueBack(QE* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}



bool QueueEmpty(QE* q)
{
	assert(q);
	return q->head == NULL && q->rear== NULL;
}


int QueueSize(QE* q)
{
	assert(q);

	return q->size;
}

void QueueDestroy(QE* q)
{
	assert(q);

	QNode* cur = q->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	q->head = q->rear = NULL;

}