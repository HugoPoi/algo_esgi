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
void list_insert( t_list* listIn, int idx, int value ) ;

/*** delete and element ****/
void  list_remove_index( t_list * listIn, int idx ) ;


/**** create a new liste ********/
t_list* new( unsigned int max ) ;

/**** display the list ********/
void display_list( t_list ) ;

/***** main start *************/
int main ( int argc, char ** argv ){

    t_list * testList = new( 5 ) ;

    testList -> data[ 0 ] = 15 ;
    testList -> data[ 1 ] = 28 ;
    testList -> data[ 2 ] = 87 ;
    testList -> data[ 3 ] = 40 ;
    testList -> data[ 4 ] = 35 ;
    testList -> length    = 5  ;
    display_list( *testList )  ; 
    list_insert( testList, 1,22);
    list_remove_index( testList, 1 );
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

    if ( ( idx > listIn -> max_size - 1 ) || ( idx > listIn -> length - 1 ) || ( listIn -> length >= listIn -> max_size ) )
    {
        printf( " indice invalide insertion \n " ) ;
        return;
    }
    

    int i = listIn -> length;

    for( ; i > idx ; i-- ){

        listIn -> data[ i ] = listIn -> data[ i - 1 ] ; 

    } 

    listIn -> data [ idx ] = value ;
    listIn -> length++ ;

}

/**** delete an value ****/
void  list_remove_index( t_list * listIn, int idx ) {

    if ( idx > ( listIn -> length ) && idx > 0 ){
        printf ( " invalid index remove \n " ) ;
        return;
    }

    int i = 0 ;

    for( i = idx ; i < listIn -> length; i++ ){
        listIn -> data [ i ] = listIn -> data[ i + 1 ] ;
    }

    listIn -> length -- ;


}
