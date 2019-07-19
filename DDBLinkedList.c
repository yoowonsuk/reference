#include <stdlib.h>
#include "DDBLinkedList.h"

void ListInit(List * plist)
{
  plist->head = (Node *)malloc(sizeof(Node));
  plist->tail = (Node *)malloc(sizeof(Node));

  plist->head->prev = plist->tail->next = NULL;
  plist->head->next = plist->tail;
  plist->tail->prev = plist->head;

  plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = plist->tail->prev;
  newNode->prev->next = newNode;
  plist->tail->prev = newNode;
  newNode->next = plist->tail;

  (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
  if(!(plist->numOfData))
    return FALSE;

  plist->cur = plist->head->next;
  *pdata = plist->cur->data;
  return TRUE;
}

int LNext(List * plist, Data * pdata)
{
  if(plist->cur->next == plist->tail)
    return FALSE;

  plist->cur = plist->cur->next;
  *pdata = plist->cur->data;
  return TRUE;
}

Data LRemove(List * plist)
{
  Data rdata = plist->cur->data;
  Node * before = plist->cur->prev;

  plist->cur->next->prev = plist->cur->prev;
  plist->cur->prev->next = plist->cur->next;

  free(plist->cur);
  plist->cur = before;
  (plist->numOfData)--;
  return rdata;
}

int LCount(List * plist)
{
  return plist->numOfData;
}


