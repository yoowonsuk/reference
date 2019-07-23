#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#define TRUE 1
#define FALSE 0

#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "PriorityQueue.h"

enum {A, B, C, D, E, F, G};

typedef struct
{
  int numV;
  int numE;
  List * adjList;
  int * visitV;
  PQueue pqueue; // PQ
} ALGraph;

void GraphInit(ALGraph *, int);
void GraphDestroy(ALGraph *);
void AddEdge(ALGraph *, int, int, int); // weight
void ShowGraphEdgeInfo(ALGraph *);
void DFShowGraphVertex(ALGraph *, int);
void ConKruskalMST(ALGraph *); // make kruskal
void ShowGraphEdgeWeightInfo(ALGraph *); // show kruskal

#endif
