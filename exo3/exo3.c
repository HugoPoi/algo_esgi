#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct S_pile{
    int    value ;
    struct S_pile* next ;
}T_pile ;

/***** LIFO functions *****/

void push(T_pile** , int value);
int peek(T_pile* );
int pop(T_pile** );

/***** End LIFO functions *****/

/***** FIFO functions *****/
void enqueue(T_pile**, int );
int dequeue(T_pile**);
int peek_fifo(T_pile* );
void display_fifo(T_pile* );
int fifo_length(T_pile* fifoIn);
/***** End FIFO functions *****/

int main( int argc , char ** argv ){
  
  T_pile* fifo = NULL;

  enqueue(&fifo,1);
  enqueue(&fifo,2);
  enqueue(&fifo,3);
  enqueue(&fifo,4);
  display_fifo(fifo);
  printf("%d\n",dequeue(&fifo));
  printf("%d\n",dequeue(&fifo));
  printf("%d\n",dequeue(&fifo));
  printf("%d\n",dequeue(&fifo));
  enqueue(&fifo,13);
  enqueue(&fifo,14);
  enqueue(&fifo,15);
  enqueue(&fifo,16);
  display_fifo(fifo);
  printf("%d\n",dequeue(&fifo));
  printf("%d\n",dequeue(&fifo));
  display_fifo(fifo);
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
	int out;
	if(*fifoIn != (*fifoIn)->next){
	T_pile* first = (*fifoIn)->next;
	(*fifoIn)->next = first->next;
	out = first->value;
	free(first);
	}else{
		out = (*fifoIn)->value;
		free(*fifoIn);
		*fifoIn = NULL;
	}
	return out;
}
int peek_fifo(T_pile* fifoIn){
	return fifoIn->next->value;
}
void display_fifo(T_pile* fifoIn){
	T_pile* last = fifoIn;
	fifoIn = fifoIn->next;
	while(fifoIn != last){
		printf("%d,",fifoIn->value);
		fifoIn = fifoIn->next;
	}
	printf("%d:len=%d\n",fifoIn->value,fifo_length(last));
}
int fifo_length(T_pile* fifoIn){
	T_pile* last = fifoIn;
	int length=0;
	while(((fifoIn = fifoIn->next) != last)) length++;
	return length;
}
