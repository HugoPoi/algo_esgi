#include <stdlib.h>
#include <stdio.h>

#include "fifo.h"

void enqueue(T_pile** last, int value){
  T_pile* newLink = malloc(sizeof(T_pile));
  if(!*last){
    *last = newLink;
  }
  newLink->value = value;
  newLink->next = (*last)->next;
  (*last)->next = newLink;
  *last = newLink;
}

int dequeue(T_pile** pile){
  T_pile* first = (*pile)->next;
  int out = first->value;
  if(first != *pile){
    (*pile)->next = first->next;
  }else{
    *pile = NULL;
  }
  free(first);
  return out;
}

int peek_fifo(T_pile* pile){
  return pile->next->value;
}

void display_fifo(T_pile* pile){
  T_pile* last = pile;
  int size = 0;
  do{
    size++;
    pile = pile->next;
    printf("%d ", pile->value);
  }
  while(pile != last);
  printf("len=%d\n", size);
}

int fifo_length(T_pile* pile){
  T_pile* last = pile;
  int size = 0;
  do{
    size++;
    pile = pile->next;
  }
  while(pile != last);
  return size;
}

