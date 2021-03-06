// CircularQueue.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "QueueProc.h"

int main()
{
	int getFromQueue = 0, addIntoQueue = 0, idx = 0;

	Queue_Init(&g_Queue);

	(void)Queue_DeleteElement(&g_Queue, getFromQueue);

	for (idx = 0; idx < 10; idx++)
	{
		addIntoQueue = idx;
		if (Queue_AddElement(&g_Queue, addIntoQueue) != Queue_FULL)
		{
			printf("Add 0x%4x into Queue. Front = %5d, Rear = %5d\r\n", addIntoQueue, \
				g_Queue.front, g_Queue.rear);
		}
	}

	for (idx = 0; idx < 5; idx++)
	{
		if (Queue_DeleteElement(&g_Queue, getFromQueue) != Queue_EMPTY)
		{
			printf("Delete 0x%4x from Queue. Front = %5d, Rear = %5d\r\n", getFromQueue, \
				g_Queue.front, g_Queue.rear);
		}
	}

	for (idx = 0; idx < 1024; idx++)
	{
		addIntoQueue = idx;
		if (Queue_AddElement(&g_Queue, addIntoQueue) != Queue_FULL)
		{
			printf("Add 0x%4x into Queue. Front = %5d, Rear = %5d\r\n", addIntoQueue, \
				g_Queue.front, g_Queue.rear);
		}
		else
		{
			break;
		}
	}

	for (idx = 0; idx < 1025; idx++)
	{
		if (Queue_DeleteElement(&g_Queue, getFromQueue) != Queue_EMPTY)
		{
			printf("Delete 0x%4x from Queue. Front = %5d, Rear = %5d\r\n", getFromQueue, \
				g_Queue.front, g_Queue.rear);
		}
		else
		{
			break;
		}
	}

	for (idx = 0; idx < 1024; idx++)
	{
		addIntoQueue = idx;
		if (Queue_AddElement(&g_Queue, addIntoQueue) != Queue_FULL)
		{
			printf("Add 0x%4x into Queue. Front = %5d, Rear = %5d\r\n", addIntoQueue, \
				g_Queue.front, g_Queue.rear);
		}
		else
		{
			break;
		}
	}

	for (idx = 0; idx < 1025; idx++)
	{
		if (Queue_DeleteElement(&g_Queue, getFromQueue) != Queue_EMPTY)
		{
			printf("Delete 0x%4x from Queue. Front = %5d, Rear = %5d\r\n", getFromQueue, \
				g_Queue.front, g_Queue.rear);
		}
		else
		{
			break;
		}
	}

	getchar();
	return 0;
    return 0;
}

