#include "DCLinkedList.h"
#include <stdlib.h>

void ListInit(List * plist)
{
  plist -> head = (Node *)malloc(sizeof(Node));
  plist -> head -> next = plist->head;
  plist -> tail = plist->head;
  plist -> cur = NULL;
  plist -> before = NULL;
  plist -> numOfData = 0;
}

void LInsert(List * plist, Data data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  /*
  if(plist->tail == NULL)
    newNode->next = newNode;
  else
  {
    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
  }
  plist->tail = newNode;
  */
  newNode->next = plist->tail->next;
  plist->tail->next = newNode;
  plist->tail = newNode;
  (plist->numOfData)++;
}

void LInsertFront(List * plist, Data data)
{
  Node * newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  /*
  if(plist->tail == NULL)
  {
    plist->tail = newNode;
    newNode->next = newNode;
  }
  else
  {
    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
  }
  */
  newNode->next = plist->head->next;
  plist->head->next = newNode;
  if(!(plist->numOfData))
    plist->tail = newNode;
  (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
  /*
  if(plist->tail == NULL)
    return FALSE;

  plist->before = plist->tail;
  plist->cur = plist->tail->next;
  */

  if(!(plist->numOfData)) // if(plist->head->next == tail)
    return FALSE;

  plist->before = plist->head;
  plist->cur = plist->head->next;
  
  *pdata = plist->cur->data;
  return TRUE;
}

int LNext(List * plist, Data * pdata)
{
  /*
  if(plist->tail == NULL)
    return FALSE;

  plist->before = plist->cur;
  plist->cur = plist->cur->next;
  */

  if(!(plist->numOfData))
    return FALSE;
  else if(plist->cur->next == plist->head)
  {
      plist->before = plist->head;
      plist->cur = plist->head->next;
  }
  else
  {
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
  }

  *pdata = plist->cur->data;
  return TRUE;
}

Data LRemove(List * plist)
{
  Data rdata = plist->cur->data;

  /*
  if(plist->cur == plist->tail)
    if(plist->tail == plist->tail->next)
      plist->tail = NULL;
    else
      plist->tail = plist->before;
  */

  plist->before->next = plist->cur->next;
  free(plist->cur);
  plist->cur = plist->before;
  (plist->numOfData)--;
  return rdata;
}

int LCount(List * plist)
{
  return plist->numOfData;
}
