#include "DCLLBaseStack.h"
#include <stdlib.h>

void StackInit(Stack * pstack)
{
  pstack->plist = (List *)malloc(sizeof(List));
  ListInit(pstack->plist);
// pstack->head == NULL;
}

int SIsEmpty(Stack * pstack)
{
  if(LCount(pstack->plist))
    return FALSE;
  return TRUE;
  /*
  if(pstack->head == NULL)
    return TRUE;
  return FALSE;
  */
}

void SPush(Stack * pstack, Data data)
{
  LInsertFront(pstack->plist, data);
  /*
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode -> data = data;

  newNode->next = pstack->head;
  pstack->head = newNode;
  */
}

Data SPop(Stack * pstack)
{
  Data rdata;
  LFirst(pstack->plist, &rdata);
  return LRemove(pstack->plist);

  /*
  Data rdata = pstack->head->data;
  Node * ptr = pstack->head->next;

  free(pstack->head);
  pstack->head = ptr;
  return rdata;
  */
}

Data SPeek(Stack * pstack)
{
  Data data;
  LFirst(pstack->plist, &data);
  return data;
//  return pstack->head->data;
}

