#include "ArrayList.h"
#include <stdio.h>

void ListInit(List * plist)
{
  plist->numOfData = 0;
  plist->curPosition= -1;
}

void LInsert(List * plist, LData data)
{
  if(plist->numOfData == LIST_LEN)
  {
    puts("can't store");
    return;
  }
  plist->arr[(plist->numOfData)++] = data;
}

int LFirst(List * plist, LData * pdata)
{
  if(!(plist->numOfData))
    return FALSE;

  plist->curPosition = 0;
  *pdata = plist->arr[0];
  return TRUE;
}

int LNext(List * plist, LData * pdata)
{
  if((plist->curPosition)+1 == plist->numOfData)
    return FALSE;

  plist->curPosition += 1;
  *pdata = plist->arr[plist->curPosition];
  return TRUE;
}

LData LRemove(List * plist)
{
  int i;
  LData data = plist->arr[plist->curPosition];
  (plist->numOfData)--;

  for(i=plist->curPosition; i<plist->numOfData; i++)
    plist->arr[i] = plist->arr[i+1];
  (plist->curPosition)--;
  return data;
}

int LCount(List * plist)
{
  return plist->numOfData;
}
