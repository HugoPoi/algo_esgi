
typedef struct S_pile{
    int    value ;
    struct S_pile* next ;
}T_pile ;

/***** LIFO functions *****/

void push(T_pile** , int value);
int peek(T_pile* );
int pop(T_pile** );
void display(T_pile* );

/***** End LIFO functions *****/

