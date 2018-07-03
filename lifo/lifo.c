#include <stdlib.h>
#include <stdio.h>

#include "lifo.h"

void push(T_pile** pile, int value){
  T_pile* newEl = malloc(sizeof(T_pile));
  newEl->value = value;
  newEl->next = *pile;
  *pile = newEl;
}

int peek(T_pile* pile){
  return pile->value;
}

int pop(T_pile** pile){
  int out = (*pile)->value;
  T_pile* toFree = *pile;
  *pile = toFree->next;
  free(toFree);
  return out;
}

void display(T_pile* pile){
  int size = 0;
  while(pile){
    size++;
    printf("%d ", pile->value);
    pile = pile->next;
  }

	printf("len=%d\n", size);
}
