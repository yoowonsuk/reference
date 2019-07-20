#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
  pstack -> topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
  if(pstack->topIndex == -1)
    return TRUE;
  return FALSE;
}

void SPush(Stack * pstack, Data data)
{
  (pstack->topIndex)++;
  pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
  return pstack->stackArr[(pstack->topIndex)--];
}

Data SPeek(Stack * pstack)
{
  return pstack->stackArr[pstack->topIndex];
}
