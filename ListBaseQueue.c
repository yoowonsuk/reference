#include "ListBaseQueue.h"
#include <stdlib.h>
#include <stdio.h>

void QueueInit(Queue * pq)
{
  pq->front = pq ->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
  if(pq->front == NULL)
    return TRUE;
  return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = data;

  if(QIsEmpty(pq))
    pq->front = pq->rear = newNode;
  else
    pq->rear = pq->rear->next = newNode;
}

Data Dequeue(Queue * pq)
{
  Node * delNode;
  Data rdata;

  if(QIsEmpty(pq))
  {
    puts("Queue empty!");
    exit(-1);
  }

  delNode = pq->front;
  rdata = pq->front->data;
  pq->front = pq->front->next;

  free(delNode);
  return rdata;
}

Data QPeek(Queue * pq)
{
  return pq->front->data;
}
