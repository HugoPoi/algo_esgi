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

/*** list insert infini *******/
void list_insert_infinite( t_list * listIn, int idx, int value );

/*** list sort ***/
void list_sort_selection(t_list *);
void list_sort_bulle(t_list * inList);
void list_tri_insertion(t_list * inList);
//void list_tri_insertion_dich(t_list * inList);
void list_permut(t_list * inList, int of_idx, int to_idx);
//int list_search_dich(t_list inList,int lower_bound, int higher_bound, int val);
int next_position(t_list * inList,int lower_bound, int higher_bound, int val);
void tri_insertion_dicho_iter(t_list * inList);

/***** main start *************/
int main ( int argc, char ** argv ){

    t_list * testList = new( 8 ) ;

    testList -> data[ 0 ] = 4 ;
    testList -> data[ 1 ] = 3 ;
    testList -> data[ 2 ] = 1 ;
    testList -> data[ 3 ] = 4 ;
    testList -> data[ 4 ] = 5 ;
    testList -> data[ 5 ] = 6 ;
    testList -> data[ 6 ] = 7 ;
    testList -> data[ 7 ] = 8 ;
    testList -> length    = 8  ;
    display_list( testList )  ; 
    tri_insertion_dicho_iter(testList);
    display_list(testList);


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
            printf( "%d ",listIn -> data[ i ] ) ;
        } 
    }

    printf("\n");

}




/*** insertion ******************/
void list_insert( t_list* listIn, int idx, int value ){

    if ( ( idx > listIn -> max_size - 1 ) || ( idx > listIn -> length - 1 ) || ( listIn -> length >= listIn -> max_size ) )
    {
        printf( "insertion : indice invalide or list is full\n" ) ;
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
        return;
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
}

/******* insert infinite ********/
void list_insert_infinite( t_list * listIn, int idx, int value ){

    int * tempData ;
    if ( ( idx <= listIn -> length - 1 ))
    	{
    	if( listIn -> length == listIn -> max_size ){

        tempData = ( int * ) malloc ( sizeof( int ) * ( (listIn -> max_size) << 1  ) ) ;

        int i = 0 ;
        int j = 0 ;
        for( ; i < listIn -> max_size+1  ; i ++ ){

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
    }else{
    	list_insert(listIn,idx,value);
    }
}
}

void list_sort_selection(t_list* list) {
    if (!list)
        return;
    int i;
    int j;
    for(j = 0; j < list->length; j++) {
        int temp_data = list->data[j];
        int temp_idx=j;
        for(i=j; i<list->length; i++) {
            if (list->data[i] < temp_data) {
                temp_data = list->data[i];
                temp_idx = i;
            }
        }
        temp_data = list->data[j];
        list->data[j] = list->data[temp_idx];
        list->data[temp_idx] = temp_data;
    }
}

void list_sort_bulle(t_list * inList){
	int i,lower_bound,has_permuted=0;
	while(-1 != has_permuted){
		lower_bound = has_permuted;
		has_permuted = -1;
		for(i = inList->length-1;i> lower_bound;i--){
			if(inList->data[i] < inList->data[i-1]){
				list_permut(inList,has_permuted=i,i-1);
			}
		}
	}
}

void list_permut(t_list * inList, int of_idx, int to_idx){
	int tmp = inList->data[to_idx];
	inList->data[to_idx] = inList->data[of_idx];
	inList->data[of_idx] = tmp;
}

void list_tri_insertion(t_list * inList){

	int j,i;
	for(i = 1; i < inList->length ; i++){
		for(j=i;j && inList->data[j-1] > inList->data[j]; j--){
			list_permut(inList,j-1,j);
		}
	}
}
/*
 * A CORRIGER ne marche pas
 *
void list_tri_insertion_dich(t_list * inList){

	int lower_bound, higher_bound,i,j,middle;
	for(i = 1; i < inList->length ; i++){
		lower_bound = 0, higher_bound = i-1;

		for(j=i ; j > lower_bound ; j--){
			list_permut(inList,j-1,j);
		}
	}
}

int list_search_dich(t_list inList,int lower_bound, int higher_bound, int val){
	int middle,i;
	while(lower_bound != higher_bound && (middle = (lower_bound+higher_bound)/2)){
		(inList->data[middle] > inList->data[i] )?
			(higher_bound = middle-1) : (lower_bound = middle+1);
		if(inList->data[middle] == inList->data[i]) higher_bound=lower_bound=middle+1;
	}
	return lower_bound;
}*/
int next_position(t_list * inList,int lower_bound, int higher_bound, int val){
	int middle = (lower_bound + higher_bound) /2;
	return (lower_bound == higher_bound) ? lower_bound :
				(val <= inList->data[middle]) ? next_position(inList, lower_bound, middle, val)
						: next_position(inList, middle+1, higher_bound, val);
}
void tri_insertion_dicho_iter(t_list * inList){
	int i = 1, position, k=0;
	for (; i < inList->length; i++) {
		position = next_position(inList, 0, i, inList->data[i]);
		for(k=i;k>position;k--)
			list_permut(inList,k,k-1);
	}
}
