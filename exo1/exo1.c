#include <stdio.h>
#include <stdlib.h>
#include <math.h>


enum OCCURENCE_Strategy{
    FIRST,
    LAST,
    ALL,
    INVALID = -1
};




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

/******* list remove some value ******/
void list_remove_value( t_list* listIn, int value,enum OCCURENCE_Strategy occ ) ;

/**** create a new liste ********/
t_list* new( unsigned int max ) ;

/**** display the list ********/
void display_list( t_list* listIn ) ;

/*** revert inside ************/
/*** revert copy  *************/
/*** list insert infini *******/
void list_insert_infinite( t_list * listIn, int idx, int value );


/***** main start *************/
int main ( int argc, char ** argv ){

    t_list * testList = new( 8 ) ;

    testList -> data[ 0 ] = 12 ;
    testList -> data[ 1 ] = 18 ;
    testList -> data[ 2 ] = 18 ;
    testList -> data[ 3 ] = 30 ;
    testList -> data[ 4 ] = 18 ;
    testList -> data[ 5 ] = 35 ;
    testList -> data[ 6 ] = 25 ;
    testList -> data[ 7 ] = 35 ;
    testList -> length    = 8  ;
    display_list( testList )  ; 
    //list_insert( testList, 1,22);
    printf ( "after all \n") ;
//    list_remove_value( testList, 18, ALL );
    display_list( testList )  ; 
    printf ( "after all \n") ;
    list_insert_infinite( testList, 2, 33 );
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
        for ( i = 0; i < listIn -> length; i++ ){
            printf( "value %d of the list is: %d \n", i+1, listIn -> data[ i ] ) ;
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

    if ( idx > ( listIn -> length ) || idx < 0 ){
        printf ( " invalid index remove \n " ) ;
        return;
    }

    int i = 0 ;

    for( i = idx ; i < listIn -> length; i++ ){
        listIn -> data [ i ] = listIn -> data[ i + 1 ] ;
    }

    listIn -> length -- ;


}

/******* list remove some value ******/
void list_remove_value( t_list* listIn, int value, enum OCCURENCE_Strategy occ ) {

    if( !listIn || listIn -> length == 0 ){
        printf ( " list is empty " ) ;
    }

    int w = 0 ;
    int r = 0 ;

    for( r = 0 ; r < listIn -> length ; r++ ){

        if ( value != listIn -> data[ r ] ){
            if ( r != w )
                listIn -> data[ w ] = listIn -> data[ r ] ;
            w++;
        }
    }
    listIn -> length = w ;

/*
    int i = 0 ;
    int all= 0;
    int tempOcc = 0 ;
    int templeng =  listIn -> length ;

    for( i = 0 ; i < listIn -> length; i++ ){

        int j = i+ 1 ;
        
        if( listIn -> data[ i ] == value && ( occ == FIRST ) ){
            list_remove_index( listIn,i ) ;
            break ;
        }

        if( listIn -> data[ i ] == value && ( occ == LAST ) ){
            tempOcc = i ;

        }

        if( listIn -> data [ j ] != value && occ == ALL ){

        }
        
        if ( all ){
            listIn -> data[i] = listIn -> data [ i + 1 ];
        }

        if( listIn -> data[ i ] == value && ( occ == ALL ) ){
            //list_remove_index( listIn, i ) ;
            listIn -> data[i] = listIn -> data [ i + 1 ];
            all = 1;
            templeng -- ;

        }

        if( listIn -> data[ i-1 ] == value && ( occ == ALL ) ){
            //list_remove_index( listIn, i ) ;
            listIn -> data[ i -1 ] = listIn -> data [ i  ];
            all = 1;
            //templeng -- ;

        }
        


    }

    
    if( occ == LAST)
    list_remove_index( listIn, tempOcc ) ; 
    listIn -> length = templeng ;
    */
}

/******* insert infinite ********/
void list_insert_infinite( t_list * listIn, int idx, int value ){

    int * tempData ;
    if ( ( idx <= listIn -> length - 1 ) && ( listIn -> length == listIn -> max_size ) ){

        tempData = ( int * ) malloc ( sizeof( int ) * ( (listIn -> max_size) << 1  ) ) ;


        int i = 0 ;
        int j = 0 ;
        for( ; i < listIn -> max_size+1  ; i ++ ){

//            tempData [ i ] = listIn -> data[ i ] ;

            if( idx != j )
            {
                tempData [ j ] = listIn -> data[ i ] ;
            }
            else{
                tempData [ j ] = value ;
                i--;
            }

            j++ ;



        } 

        free ( listIn -> data ) ;
        listIn -> length++ ;
        listIn -> max_size = listIn -> max_size * 2 ;
        listIn -> data  = tempData ;
        //list_insert( listIn, idx, value) ;
    }
    else{
        printf( " use insert i\n" ) ;
    }
}


/** decouper en deux boucle ***/



/*
    if( idx != j )
    {
    tempData [ j ] = listIn -> data[ i ] ;
    }
    else{
    tempData [ j ] = value ;
    i--;
    }

    j++ ;

    */


