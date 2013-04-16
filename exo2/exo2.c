#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct S_list_chain{
    int    value ;
    struct S_list_chain* next ;
}T_list_chain ;

/***** create a new chained list *******/
T_list_chain* list_chain_new( int value ) ;

/******** display **********************/
void list_chain_display( T_list_chain* listIn ) ;

int main ( int argc , char ** argv ){
    T_list_chain* list   = list_chain_new( 12 ) ; 
    list -> next         = list_chain_new( 3 ) ; 
    list -> next -> next = list_chain_new( 8 ) ; 

    list_chain_display( list ) ;

    return 0 ;
}




/****** new list ********/

T_list_chain* list_chain_new( int value ) {

    T_list_chain* node = ( T_list_chain * ) malloc ( sizeof ( T_list_chain ) ) ;

    node -> value = value ;
    node -> next  = NULL  ;
    return node ;

}
    


/***** display *********/
void list_chain_display( T_list_chain* listIn ) {

    while ( listIn -> next  ){
        printf( "%d,", listIn -> value );
        listIn = listIn -> next ; 
    }
    printf( "%d\n", listIn -> value ) ;

}

