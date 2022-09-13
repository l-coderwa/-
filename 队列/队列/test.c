#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void TestQueue()
{
	QE q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	QueuePop(&q);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueTop(&q));
		QueuePop(&q);
	}

}


int main()
{
	TestQueue();
	return 0;
}