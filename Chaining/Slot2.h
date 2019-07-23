#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

typedef struct
{
  Key key;
  Value value;
} Slot;

#endif
