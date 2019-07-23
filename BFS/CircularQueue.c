#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

int NextPosIdx(int pos)
{
  if(pos == QUE_LEN-1)
    return 0;
  return pos+1;
}

void QueueInit(Queue * pq)
{
  pq->front = pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
  if(pq->rear == pq->front)
    return TRUE;
  return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
  if( NextPosIdx(pq->rear) == pq->front )
  {
    puts("Queue Full!");
    exit(-1);
  }
  
  pq->rear = NextPosIdx(pq->rear);
  pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
  if( pq->rear == pq->front )
  {
    puts("Queue empty!");
    exit(-1);
  }

  pq->front = NextPosIdx(pq->front);
  return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
  if(QIsEmpty)
  {
    puts("Queue empty!");
    exit(-1);
  }
  
  return pq->queArr[NextPosIdx(pq->front)];
}
