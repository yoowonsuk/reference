#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
  ph->numOfData = 0;
  ph->comp = pc;
}

int HIsEmpty(Heap * ph)
{
  if(ph->numOfData)
    return FALSE;
  return TRUE;
}

int GetParentIDX(int idx)
{
	return idx/2;
}

int GetLChildIDX(int idx)
{
	return idx*2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx)+1;
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
  if(GetLChildIDX(idx) > ph->numOfData)
    return 0;
  else if(GetLChildIDX(idx) == ph->numOfData)
    return ph->numOfData;
  else
    if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
      return GetRChildIDX(idx);
    else
      return GetLChildIDX(idx);
}

void HInsert(Heap * ph, HData data)
{
  int idx = (ph->numOfData)+1;

  while(idx!=1)
    if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
    {
      ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
      idx = GetParentIDX(idx);
    }
    else
      break;
  (ph->numOfData)++;
  ph->heapArr[idx] = data;
}

HData HDelete(Heap * ph)
{
  HData rdata = ph->heapArr[1];
  HData ldata = ph->heapArr[(ph->numOfData)];

  int parentIdx = 1;
  int childIdx;

  while(childIdx = GetHiPriChildIDX(ph, parentIdx))
  {
    if(ph->comp(ldata, ph->heapArr[childIdx]) >= 0)
      break;
    else
    {
      ph->heapArr[parentIdx] = ph->heapArr[childIdx];
      parentIdx = childIdx;
    }
  }
  (ph->numOfData)--;
  ph->heapArr[parentIdx] = ldata;
  return rdata;
}
