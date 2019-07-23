#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct
{
  List tbl[MAX_TBL];
  HashFunc * hf;
} Table;

void TBLInit(Table *, HashFunc *);
void TBLInsert(Table *,Key k, Value v);
Value TBLDelete(Table *, Key);
Value TBLSearch(Table *, Key);

#endif
