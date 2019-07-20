#ifndef __DB_QUEUE_H__
#define __DB_QUEUE_H__

#define TRUE	1
#define FALSE	0

#include "Deque.h"
typedef int Data;

typedef struct
{
  Deque * deque;
} DBQueue;

typedef DBQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif
