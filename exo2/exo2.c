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

/***** length list ******/
int list_length( T_list_chain* listIn ) ;




/**** main *********/
int main ( int argc , char ** argv ){
    T_list_chain* list   = list_chain_new( 12 ) ; 
    list -> next         = list_chain_new( 3 ) ; 
    list -> next -> next = list_chain_new( 8 ) ; 

    list_chain_display( list ) ;
    printf( "La taille vaut:%d \", list_length( list ) ) ;

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


/**** list length *****/
int list_length( T_list_chain* listIn ) {

    int i = 0 ;
    while ( listIn ){
        listIn = listIn -> next ; 
        i++;
    }
    return i ;
}
