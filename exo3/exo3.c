#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct S_pile{
    int    value ;
    struct S_pile* next ;
}T_pile ;


void push(T_pile** , int value);

int peek(T_pile* );

int pop(T_pile** );

void enqueue(T_pile**, int );
int dequeue(T_pile**);
int peek_fifo(T_pile* );


int main( int argc , char ** argv ){
  
  T_pile* fifo = NULL;

  enqueue(&fifo,1);
  enqueue(&fifo,2);
  enqueue(&fifo,3);
  enqueue(&fifo,4);

  printf("%d\n",peek_fifo(fifo));
  
  printf("%d\n",dequeue(&fifo));
  enqueue(&fifo,6);
  printf("%d\n",peek_fifo(fifo));
  printf("%d\n",dequeue(&fifo));
  printf("%d\n",dequeue(&fifo));
  printf("%d\n",dequeue(&fifo));
  
  return 0;
  }
  
  
  
void push(T_pile** lifoIn, int value){
  
  T_pile* tmp = *lifoIn;
  
  *lifoIn = ( T_pile * ) malloc ( sizeof ( T_pile ) ) ;
  
  (*lifoIn)->value = value;
  (*lifoIn)->next = tmp;
}

int peek(T_pile* listIn){
	return listIn->value;
}

int pop(T_pile** listIn){
	if(!(*listIn)) return -1;
	int out = (*listIn)->value;
	T_pile* tmp = (*listIn)->next;
	free(listIn);
	*listIn = tmp;
	return out;
}

void enqueue(T_pile** fifoIn, int value){

	 T_pile* tmp = ( T_pile * ) malloc ( sizeof ( T_pile ) ) ;
	 if(!(*fifoIn)) *fifoIn = tmp;
	 tmp->value = value;
	 tmp->next = (*fifoIn)->next;
	 (*fifoIn)->next = tmp;
	 *fifoIn = tmp;
}
int dequeue(T_pile** fifoIn){
	T_pile* first = (*fifoIn)->next;
	(*fifoIn)->next = first->next;
	int out = first->value;
	free(first);
	return out;
}
int peek_fifo(T_pile* fifoIn){
	return fifoIn->next->value;
}
