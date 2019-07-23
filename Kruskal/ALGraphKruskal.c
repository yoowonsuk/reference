#include "ALGraphKruskal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int WhoIsPrecede(int data1, int data2)
{
  if(data1 < data2)
    return 0;
  return 1;
}

int PQWeightComp(Edge d1, Edge d2)
{
  return d1.weight - d2.weight;
}

void GraphInit(ALGraph * pq, int nv)
{
  int i;

  pq->numV = nv;
  pq->numE = 0;
  pq->adjList = (List *)malloc(sizeof(List)*nv);
  pq->visitV = (int *)malloc(sizeof(int)*nv);

  PQueueInit(&(pq->pqueue), PQWeightComp);
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

void AddEdge(ALGraph * pq, int fromV, int toV, int weight)
{
  Edge edge = {fromV, toV, weight};

  LInsert(&(pq->adjList[fromV]), toV);
  LInsert(&(pq->adjList[toV]), fromV);
  PEnqueue(&(pq->pqueue), edge);
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
    //printf("%c ", visitV + 65);
    return TRUE;
  }
  return FALSE;
}

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

void RemoveEdge(ALGraph * pq, int fromV, int toV)
{
  int rdata, done = TRUE;

  if(LFirst(&(pq->adjList[fromV]), &rdata))
  {
    if(rdata == toV)
      LRemove(&(pq->adjList[fromV])), done = FALSE;
    while(LNext(&(pq->adjList[fromV]), &rdata) && done)
      if(rdata == toV)
      {
        LRemove(&(pq->adjList[fromV]));
        break;
      }
  }
  done = TRUE;

  if(LFirst(&(pq->adjList[toV]), &rdata))
  {
    if(rdata == fromV)
      LRemove(&(pq->adjList[toV])), done = FALSE;
    while(LNext(&(pq->adjList[toV]), &rdata) && done)
      if(rdata == fromV)
      {
        LRemove(&(pq->adjList[toV]));
        break;
      }
  }
  (pq->numE)--;
}

/*
void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
	int edge;

	if(LFirst(&(pg->adjList[fromV]), &edge))
	{
		if(edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while(LNext(&(pg->adjList[fromV]), &edge))
		{
			if(edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

// 간선의 소멸: ConKruskalMST Helper function
void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}
*/

void RecoverEdge(ALGraph * pq, int fromV, int toV, int weight)
{
  LInsert(&(pq->adjList[fromV]), toV);
  LInsert(&(pq->adjList[toV]), fromV);
  (pq->numE)++;
}

int IsConnVertex(ALGraph * pq, int v1, int v2)
{
  Stack stack;
  int visitV = v1;
  int nextV;

  StackInit(&stack);
  VisitVertex(pq, visitV);
  //SPush(&stack, visitV);

  while(LFirst(&(pq->adjList[visitV]), &nextV))
  {
    int visitFlag = FALSE;
    
    if(nextV == v2)
    {
      memset(pq->visitV, 0, sizeof(int)*pq->numV);
      return TRUE;
    }

    if(VisitVertex(pq, nextV))
    {
      SPush(&stack, visitV);
      visitV = nextV;
      visitFlag = TRUE;
    }
    else
    {
      while(LNext(&(pq->adjList[visitV]), &nextV))
      {
        if(nextV == v2)
        {
          memset(pq->visitV, 0, sizeof(int)*pq->numV);
          return TRUE;
        }
        if(VisitVertex(pq, nextV))
        {
          SPush(&stack, visitV);
          visitV = nextV;
          visitFlag = TRUE;
          break;
        }
      }
    }
    

    if(visitFlag == FALSE)
      if(SIsEmpty(&stack))
        break;
      else
        visitV = SPop(&stack);
  }

  memset(pq->visitV, 0, sizeof(int)*pq->numV);
  return FALSE;
}

void ConKruskalMST(ALGraph * pq)
{
  Edge recvEdge[20];
  Edge edge;
  int idx = 0;
  int i;

  while(pq->numE + 1 > pq->numV)
  {
    edge = PDequeue(&(pq->pqueue));
    RemoveEdge(pq, edge.v1, edge.v2);

    if(!IsConnVertex(pq, edge.v1, edge.v2))
    {
      RecoverEdge(pq, edge.v1, edge.v2, edge.weight);
      recvEdge[idx++] = edge;
    }
  }

  for(i=0; i<idx; i++)
    PEnqueue(&(pq->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pq)
{
  PQueue cpypq = pq->pqueue;
  Edge edge;

  while(!PQIsEmpty(&cpypq))
  {
    edge = PDequeue(&cpypq);
    printf("(%c-%c), w:%d\n", edge.v1+65, edge.v2+65, edge.weight);
  }
}
