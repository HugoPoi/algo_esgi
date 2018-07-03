#include <stdlib.h>
#include <stdio.h>

#include "lifo.h"

/***** main start *************/
int main ( int argc, char ** argv ){

  T_pile* pile = NULL;

  push(&pile, 42);
  push(&pile, 3);
  push(&pile, 2);
  push(&pile, 1);

  printf("pop %d\n", pop(&pile));

  display(pile);
  return 0;

}
