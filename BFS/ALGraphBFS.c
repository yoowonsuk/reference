#include "ALGraphBFS.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int WhoIsPrecede(int data1, int data2)
{
  if(data1 < data2)
    return 0;
  return 1;
}

void GraphInit(ALGraph * pq, int nv)
{
  int i;

  pq->numV = nv;
  pq->numE = 0;
  pq->adjList = (List *)malloc(sizeof(List)*nv);
  pq->visitV = (int *)malloc(sizeof(int)*nv);

  memset(pq->visitV, FALSE, sizeof(int)*nv);
  for(i=0; i<nv; i++)
  {
    ListInit(&(pq->adjList[i]));
    SetSortRule(&(pq->adjList[i]), WhoIsPrecede);
  }
}

void GraphDestroy(ALGraph * pq)
{
  if(pq->adjList != NULL)
    free(pq->adjList);
  if(pq->visitV != NULL)
    free(pq->visitV);
}

void AddEdge(ALGraph * pq, int fromV, int toV)
{
  LInsert(&(pq->adjList[fromV]), toV);
  LInsert(&(pq->adjList[toV]), fromV);

  (pq->numE)++;
}

void ShowGraphEdgeInfo(ALGraph * pq)
{
  int i;
  LData data;

  for(i=0; i<pq->numV; i++)
  {
    printf("connection with %c: ", i+65);
    if(LFirst(&(pq->adjList[i]), &data))
    {
      printf("%c ", data+65);
    while(LNext(&(pq->adjList[i]), &data))
      printf("%c ", data+65);
    }
    printf("\n");
  }
}

int VisitVertex(ALGraph * pq, int visitV)
{
  if(pq->visitV[visitV] == 0)
  {
    pq->visitV[visitV] = 1;
    printf("%c ", visitV + 65);
    return TRUE;
  }
  return FALSE;
}

/*
void DFShowGraphVertex(ALGraph * pq, int startV)
{
  Stack stack;
  int visitV = startV;
  int nextV;

  StackInit(&stack);
  VisitVertex(pq, visitV);
  //SPush(&stack, visitV);

  while(LFirst(&(pq->adjList[visitV]), &nextV))
  {
    int visitFlag = FALSE;

    if(VisitVertex(pq, nextV))
    {
      SPush(&stack, visitV);
      visitV = nextV;
      visitFlag = TRUE;
    }

    while(LNext(&(pq->adjList[visitV]), &nextV))
      if(VisitVertex(pq, nextV))
      {
        SPush(&stack, visitV);
        visitV = nextV;
        visitFlag = TRUE;
        break;
      }
    

    if(visitFlag == FALSE)
      if(SIsEmpty(&stack))
        break;
      else
        visitV = SPop(&stack);
  }

  memset(pq->visitV, 0, sizeof(int)*pq->numV);
}
*/

void BFShowGraphVertex(ALGraph * pq, int startV)
{
  Queue q;
  int visitV = startV;
  int nextV;

  QueueInit(&q);
  VisitVertex(pq, startV);

  while(LFirst(&(pq->adjList[visitV]), &nextV))
  {
    if(VisitVertex(pq, nextV) == TRUE)
      Enqueue(&q, nextV);
    while(LNext(&(pq->adjList[visitV]), &nextV))
      if(VisitVertex(pq, nextV) == TRUE)
        Enqueue(&q, nextV);
    
    if(QIsEmpty(&q))
      break;
    visitV = Dequeue(&q);
  }
  memset(pq->visitV, 0, sizeof(int)*pq->numV);
}
