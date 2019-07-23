#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#define TRUE 1
#define FALSE 0

#include "DLinkedList.h"
#include "CircularQueue.h"

enum {A, B, C, D, E, F, G};

typedef struct
{
  int numV;
  int numE;
  List * adjList;
  int * visitV;
} ALGraph;

void GraphInit(ALGraph *, int);
void GraphDestroy(ALGraph *);
void AddEdge(ALGraph *, int, int);
void ShowGraphEdgeInfo(ALGraph *);
void BFShowGraphVertex(ALGraph *, int);

#endif
