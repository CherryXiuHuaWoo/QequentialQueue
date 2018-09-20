/*
 * File Name: QueueProc.cpp
 * Function: Queue Process 
 * Author: Wuxiuhua
 * Date: 2018-9-20
 * Function List:
 * 
 * Modification:
 * 2018-9-20 : Create file, Wuxiuhua
 */
#include "stdafx.h"
#include "QueueProc.h"
#include "string.h"

QueueType g_Queue;

 /*
 Function: Init Quueue
 Intput:
		Queue, ptr to Queue
 Return: None
  */
void Queue_Init(QueueType *Queue)
{
	memset(Queue->Queue, 0, sizeof(Queue->Queue)/sizeof(QElemType));

	Queue->front = -1;
	Queue->rear = -1;
 }


/*
 Function: Empty Queue?
 Intput:
		Queue, ptr to Queue
 Return:
 		Queue_EMPTY
 		Queue_OK
 */
static Queue_Status Queue_IsEmpty(QueueType *Queue)
{
	if (Queue->front == Queue->rear)
	{
		QueuePrintf("Err: Queue is empty!\r\n");
		return Queue_EMPTY;
	}
	else
	{
		return Queue_OK;
	}
}

/*
Function: Full Queue?
Intput:
Queue, ptr to Queue
Return:
		Queue_FULL
		Queue_OK
*/
static Queue_Status Queue_IsFull(QueueType *Queue)
{
	if (((Queue->rear + 1)%QueueLength) == Queue->front)
	{
		QueuePrintf("Err: Queue is full!\r\n");
		return Queue_FULL;
	}
	else
	{
		return Queue_OK;
	}
}

/*
 Function: get element from queue
 Intput:
			Queue, ptr to Queue
			item
 Return:
 		Queue_EMPTY
 		Queue_OK
 Other: 
		Don't change the front of Queue
*/
int Queue_GetElement(QueueType *Queue, QElemType &item)
{
	// If Queue is empty, return Queue_EMPTY
	if (Queue_EMPTY == Queue_IsEmpty(Queue))
	{
		return Queue_EMPTY;
	}
	else
	{	// else get the item from Queue
		item = Queue->Queue[Queue->front];
		return Queue_OK;
	}
}


/*
Function: add element into queue
Intput:
		Queue, ptr to Queue
		item
Return:
		Queue_FULL
		Queue_OK
*/
int Queue_AddElement(QueueType *Queue, QElemType &item)
{
	// If Queue is full, return Queue_FULL
	if (Queue_FULL == Queue_IsFull(Queue))
	{
		return Queue_FULL;
	}
	else
	{	// else add the item into Queue
		Queue->rear = (Queue->rear + 1) % QueueLength;
		Queue->Queue[Queue->rear] = item;
		return Queue_OK;
	}
}

/*
Function: delete element into queue
Intput:
		Queue, ptr to Queue
		item
Return:
		Queue_EMPTY
		Queue_OK
*/
int Queue_DeleteElement(QueueType *Queue, QElemType &item)
{
	// If Queue is empty, return Queue_EMPTY
	if (Queue_EMPTY == Queue_IsEmpty(Queue))
	{
		return Queue_EMPTY;
	}
	else
	{	// else delete the item into Queue
		Queue->front = (Queue->front + 1) % QueueLength;
		item = Queue->Queue[Queue->front];
		return Queue_OK;
	}
}

