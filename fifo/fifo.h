
typedef struct S_pile{
    int    value ;
    struct S_pile* next ;
}T_pile ;

/***** FIFO functions *****/
void enqueue(T_pile**, int );
int dequeue(T_pile**);
int peek_fifo(T_pile* );
void display_fifo(T_pile* );
int fifo_length(T_pile* fifoIn);
/***** End FIFO functions *****/

