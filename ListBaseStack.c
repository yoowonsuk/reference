#include "ListBaseStack.h"
#include <stdlib.h>

void StackInit(Stack * pstack)
{
  pstack -> head = NULL;
}

int SIsEmpty(Stack * pstack)
{
  if(pstack->head == NULL)
    return TRUE;
  return FALSE;
}

void SPush(Stack * pstack, Data data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode -> data = data;

  newNode->next = pstack->head;
  pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
  Data rdata = pstack->head->data;
  Node * ptr = pstack->head->next;

  free(pstack->head);
  pstack->head = ptr;
  return rdata;
}

Data SPeek(Stack * pstack)
{
  return pstack->head->data;
}

