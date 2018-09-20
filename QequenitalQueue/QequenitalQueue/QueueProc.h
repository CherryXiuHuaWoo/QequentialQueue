#pragma once
#include "stdio.h"

#define QueueLength		1024
#define __Queue_DEBUG

#ifdef __Queue_DEBUG
#define QueuePrintf(format, ...)	printf(format, ##__VA_ARGS__)
#else
#define QueuePrintf(format, ...)
#endif

typedef enum 
{
	Queue_OK = 0U,
	Queue_EMPTY = 1U,
	Queue_FULL = 2U,
}Queue_Status;

typedef int QElemType;

typedef struct MyQueueType
{
	QElemType Queue[QueueLength];
	int front;
	int rear;
}QueueType;

extern QueueType g_Queue;

/*
Function: Init Quueue
Intput:
Queue, ptr to Queue
Return: None
*/
void Queue_Init(QueueType *Queue);

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
int Queue_GetElement(QueueType *Queue, QElemType &item);

/*
Function: add element into queue
Intput:
Queue, ptr to Queue
item
Return:
Queue_FULL
Queue_OK
*/
int Queue_AddElement(QueueType *Queue, QElemType &item);

/*
Function: delete element into queue
Intput:
Queue, ptr to Queue
item
Return:
Queue_EMPTY
Queue_OK
*/
int Queue_DeleteElement(QueueType *Queue, QElemType &item);