
typedef struct S_node{
    int    value ;
    struct S_node* next ;
}T_node ;

/***** FIFO functions *****/
void enqueue( T_node**, int );
int dequeue( T_node** );
int peek_fifo( T_node* );
void display_fifo( T_node* );
int fifo_length( T_node* );
/***** End FIFO functions *****/

