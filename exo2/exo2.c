#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct S_list_chain{
    int    value ;
    struct S_list_chain* next ;
}T_list_chain ;

enum OCCURENCE_STRATEGY{
    FIRST,
    LAST,
    ALL,
    INVALID = -1
};


/*remove by index ***/
void list_chain_remove_index( T_list_chain ** listIn, int idx ) ; 

/***** create a new chained list *******/
T_list_chain* list_chain_new( int value ) ;

/******** display **********************/
void list_chain_display( T_list_chain* listIn ) ;

/***** length list ******/
int list_length( T_list_chain* listIn ) ;

/**** get index value *****/
int list_chain_get_value_by_index( T_list_chain* listIn, int idx ) ;

/**** get value by for  *****/
int list_chain_get_value_by_indexFor( T_list_chain* , int , enum OCCURENCE_STRATEGY  ) ;

/*** insertion of element ****/
void list_chain_insert( T_list_chain** listIn, int idx, int value ) ;

/*** remove by value ***/
void list_chain_remove_value( T_list_chain ** listIn, int value, enum OCCURENCE_STRATEGY ) ;


/**** main *********/
int main ( int argc , char ** argv ){
    T_list_chain* list   = list_chain_new( 12 ) ; 
    list -> next         = list_chain_new( 3 ) ; 
    list -> next -> next = list_chain_new( 8 ) ; 
    list -> next -> next -> next = list_chain_new( 10 ) ; 
    list -> next -> next -> next -> next = list_chain_new( 80 ) ; 

    list_chain_display( list ) ;
    printf( "La taille vaut:%d \n", list_length( list ) ) ;
    list_chain_insert( &list , 2, 46) ;
    list_chain_insert( &list , 3, 45) ;
    //list_chain_insert( &list , 0, 100) ;
    list_chain_display( list ) ;
    printf( "after remove \n" ) ;
    list_chain_remove_index( &list , 2 );
    list_chain_display( list ) ;

    printf( "after remove first  \n" ) ;
    list_chain_remove_value( &list, 3, FIRST ) ;
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


/**** list length *****/
int list_length( T_list_chain* listIn ) {

    int i = 0 ;
    while ( listIn ){
        listIn = listIn -> next ; 
        i++;
    }
    return i ;
}



/**** get index value *****/
int list_chain_get_value_by_index( T_list_chain* listIn, int idx ) {


        while ( listIn && idx-- ){
            listIn = listIn -> next ;
        } 

        if (  idx == -1 )
            return listIn -> value ;
        else 
            return -1 ;
}



/**** get value by for  *****/
int list_chain_get_value_by_index_for( T_list_chain* listIn, int value, enum OCCURENCE_STRATEGY occ ) {

    int idx = -1 ;
    int i   = 0  ;
    while ( listIn ){
        i++ ;

        if ( value == listIn -> value ){

            if ( occ == FIRST )
                return i ;

            idx = i ;
        }

        listIn = listIn -> next ;

    } 
    return idx ;

}

/*** insert chain *****/
void list_chain_insert( T_list_chain** listIn, int idx, int value ) {

    T_list_chain* inter ;
    //T_list_chain* temp     = (*listIn );
    T_list_chain* templist = (*listIn );
    inter  = list_chain_new( value ) ;



    if ( idx == 0 ){
        inter -> next = ( *listIn ) ;
        ( *listIn)    = inter ;
        return ;
    }

    int i =0 ;
    while ( templist  ) {

        if( idx-1 == i ){
            inter    -> next = templist -> next ;
            templist  -> next = inter ;
            break ;
        }
        templist   = templist -> next  ;
        i++;
    }

    ( *listIn ) = (* listIn );
}

/***** correction insertion ****/
/******* 
 * while( index-- && *list && ( list = & ( * list ) -> next ) );
 * if ( !(index +1 ) )
 * *list = list_chain_new( value, *list ) ;
 * *******************************/

/*** remove by value ***/
void list_chain_remove_value( T_list_chain ** listIn, int value, enum OCCURENCE_STRATEGY occ ){

    T_list_chain * temp ;

    while( (*listIn ) && (listIn = &(*listIn) -> next )  ){
        if ( ( (*listIn )-> value == value) && ( occ == FIRST ) ){
            temp = ( *listIn ) ;
            (*listIn) = ( *listIn )-> next ;
            free( temp ) ;
        }

    } 
}




/*** remove by index ****/
void list_chain_remove_index( T_list_chain** listIn, int idx ) {


    T_list_chain* temp ;

    while ( (*listIn) && idx-- ){
        listIn = &(*listIn) -> next ;
    } 
    if (  idx == -1 && (*listIn)  )
    {
        temp = (*listIn)  ;
        (*listIn) = (*listIn) -> next ;
        free( temp ) ;
    }

}



