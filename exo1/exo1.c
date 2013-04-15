#include <stdio.h>
#include <stdlib.h>
#include <math.h>





/****** list display ********/
typedef struct {

    int*         data     ;
    unsigned int max_size ;
    unsigned int length   ;

} t_list ;

/*** insertion ******************/
void list_insert( t_list* list, int idx, int value ) ;

/*** delete and element ****/


/**** create a new liste ********/
t_list* new( unsigned int max ) ;

/**** display the list ********/
void display_list( t_list ) ;

/***** main start *************/
int main ( int argc, char ** argv ){

    t_list * testList = new( 5 ) ;

    list_insert(testList,0,15);
    list_insert(testList,0,28);
    list_insert(testList,0,87);
    list_insert(testList,0,40);
    list_insert(testList,0,35);
    display_list( *testList )  ;

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
void display_list( t_list listIn ) {

    if ( listIn.data == NULL ) {
        printf( " your list is empty " ) ;
    } 

    else{

        /**** display the list contents ****/
        int i = 0 ;
        for ( i = 0; i < listIn.length; i++ ){
            printf( "value %d of the list is: %d \n", i+1, listIn.data[ i ] ) ;
        } 
    }


}




/*** insertion ******************/
void list_insert( t_list* listIn, int idx, int value ){

    if ( ( idx > listIn -> max_size ) &&  ( idx > listIn->length ) && ( listIn->length > listIn->max_size ) )
    {
         printf("indice invalide\n");
        return;
    }
    

    int i = listIn->length;

    for( ; i > idx ; i-- ){

        listIn -> data[ i ] = listIn -> data[ i - 1 ] ; 

    } 

    listIn -> data [ idx ] = value ;
    listIn -> length++ ;

}
