#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/****** list display ********/
typedef struct {

    int*         data     ;
    unsigned int max_size ;
    unsigned int length   ;

} t_list ;

/**** create a new liste ********/
t_list* new( unsigned int max ) ;

/**** display the list ********/
void display_list( t_list* ) ;

/***** main start *************/
int main ( int argc, char ** argv ){

    t_list * testList = new( 5 ) ;

    testList -> data[ 0 ] = 15 ;
    testList -> data[ 1 ] = 28 ;
    testList -> data[ 2 ] = 87 ;
    testList -> data[ 3 ] = 40 ;
    testList -> data[ 4 ] = 35 ;
    /* TRicks !! */
    testList -> length = 5;
    /* TRicks !! */
    display_list( testList )  ;

    


    return 0 ;

} 




/****** create a new list ********/
t_list* new( unsigned int max ) {

    /******* alloc a new list ************/
    t_list* listOne    = ( t_list * ) malloc( sizeof ( t_list ) ) ;

    listOne -> data     = ( int* ) malloc ( sizeof ( int ) * max ) ; 
    listOne -> max_size = max ;
    listOne -> length   = 0 ; 
    return listOne ;

}

/*** display list content *********/
void display_list( t_list* listIn ) {

    if ( listIn == NULL ) {
        printf( " your list is empty " ) ;
    } 

    else{

        /**** display the list contents ****/
        int i = 0 ;
        for ( i = 0; i < listIn -> length-1; i++ ){
            printf( "[%d]:%d,", i, listIn -> data[ i ] ) ;
        }
        printf( "[%d]:%d\n", i, listIn -> data[ i ] ) ;
    }
}
