#include <stdlib.h>
#include <stdio.h>

#include "fifo.h"

void enqueue(T_node** fifo, int value){
  T_node* newNode = malloc(sizeof(T_node));
  T_node* lastNode = *fifo;
  if(!lastNode){
    lastNode = newNode;
  }
  newNode->value = value;
  newNode->next = lastNode->next;
  lastNode->next = newNode;
  *fifo = newNode;
}

int dequeue(T_node** fifo){
  T_node* first = (*fifo)->next;
  int out = first->value;
  if(first != *fifo){
    (*fifo)->next = first->next;
  }else{
    *fifo = NULL;
  }
  free(first);
  return out;
}

int peek_fifo(T_node* pile){
  return pile->next->value;
}

void display_fifo(T_node* pile){
  T_node* last = pile;
  int size = 0;
  do{
    size++;
    pile = pile->next;
    printf("%d ", pile->value);
  }
  while(pile != last);
  printf("len=%d\n", size);
}

int fifo_length(T_node* pile){
  T_node* last = pile;
  int size = 0;
  do{
    size++;
    pile = pile->next;
  }
  while(pile != last);
  return size;
}

