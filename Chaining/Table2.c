#include "Table2.h"
#include "DLinkedList.h"
#include <stdlib.h>
#include <stdio.h>


void TBLInit(Table * pt, HashFunc * f)
{
  int i;

  for(i=0; i<MAX_TBL; i++)
    ListInit(&(pt->tbl[i]));

  pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
  int hv = pt->hf(k);
  Slot s = {k, v};
 
  if(TBLSearch(pt, k) != NULL)
  {
    puts("Key duplication");
    return;
  }
  
  LInsert(&(pt->tbl[hv]), s);
}

Value TBLDelete(Table * pt, Key k)
{
  int hv = pt->hf(k);
  LData data;

  if(LFirst(&(pt->tbl[hv]), &data))
  {
    if(k == data.key)
    {
      LRemove(&(pt->tbl[hv]));
      return data.value;
    }

    while(LNext(&(pt->tbl[hv]), &data))
      if(k == data.key)
      {
        LRemove(&(pt->tbl[hv]));
        return data.value;
      }
  }
  return NULL; 
}

Value TBLSearch(Table * pt, Key k)
{
  int hv = pt->hf(k);
  LData data;

  if(LFirst(&(pt->tbl[hv]), &data))
  {
    if(k == data.key)
      return data.value;

    while(LNext(&(pt->tbl[hv]), &data))
      if(k == data.key)
        return data.value;
  }
  return NULL; 
}

