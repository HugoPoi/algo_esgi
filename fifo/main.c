#include <stdlib.h>
#include <stdio.h>

#include "fifo.h"

/***** main start *************/
int main ( int argc, char ** argv ){

  T_node* pile = NULL;

  for(int i = 0 ; i <= 10000; i++){
    enqueue(&pile, i);
  }

  printf("pop %d\n", dequeue(&pile));

  display_fifo(pile);
  return 0;

}
