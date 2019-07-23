#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int GetSSN(Person * p)
{
  return p->ssn;
}

void ShowPerInfo(Person * p)
{
  printf("SSN: %d\n", p->ssn);
  printf("name: %s\n", p->name);
  printf("address: %s\n", p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
  Person * newp = (Person*)malloc(sizeof(Person));
  newp->ssn = ssn;
  strcpy(newp->name, name);
  strcpy(newp->addr, addr);
  return newp;
}
