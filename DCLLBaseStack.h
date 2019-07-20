#ifndef __DCLLB_STACK_H__
#define __DCLLB_STACK_H__

#include "DCLinkedList.h"

#define TRUE	1
#define FALSE	0

typedef struct 
{
	List * plist;
} DCLListStack;

typedef DCLListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif
