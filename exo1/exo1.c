#include <stdio.h>
#include <stdlib.h>
#include <math.h>


enum OCCURENCE_Strategy{
    FIRST,
    LAST,
    ALL,
    INVALID = -1
};


/**** define list ****/
typedef struct {

    int*         data     ;
    unsigned int max_size ;
    unsigned int length   ;

} t_list ;

/**** create a new liste ****/
t_list* new( unsigned int ) ;

/**** insert element ****/
void list_insert(t_list* , int , int ) ;
void list_insert_infinite(t_list* , int ,int );

/**** remove element ****/
void list_remove(t_list* , int );
void list_remove_value(t_list* , int , enum OCCURENCE_Strategy);

/**** list reverte ****/
void list_reverte_inside(t_list* );
t_list* list_reverte(t_list* );

/**** display the list ****/
void display_list(t_list* ) ;

/***** main start *************/
int main ( int argc, char ** argv ){

    t_list * testList = new( 5 ) ;

    list_insert(testList,0,15);
    list_insert(testList,0,28);
    list_insert(testList,0,87);
    list_insert(testList,0,87);
    list_insert(testList,0,40);
    list_insert(testList,0,35);
    list_insert_infinite(testList,0,35);
    list_insert_infinite(testList,0,35);
    list_insert_infinite(testList,0,35);
    list_insert_infinite(testList,0,35);
    list_insert_infinite(testList,0,35);
    list_insert_infinite(testList,0,35);
    list_insert_infinite(testList,0,35);
    //list_delete(testList, 3);
    display_list( testList );
    //list_remove_value(testList,87,ALL);
    //list_reverte_inside(testList);
    //display_list( testList );
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

/******** display list content ********/
void display_list( t_list* listIn ) {

    if ( listIn == NULL ) {
        printf( "your list is empty\n" ) ;
    } 

    else{

        /**** display the list contents ****/
        int i = 0 ;
        for ( i = 0; i < listIn -> length; i++ ){
            printf( "value %d of the list is: %d \n", i, listIn -> data[ i ] ) ;
        } 
    }

}

/******** insertion ********/
void list_insert( t_list* listIn, int idx, int value ){

    if ( ( idx > listIn -> max_size -1 ) ||  ( idx > listIn->length-1) || ( listIn->length > listIn->max_size-1) )
    {
         printf("idx out of range!\n");
        return;
    }
    

    int i = listIn -> length;

    for( ; i > idx ; i-- ){

        listIn -> data[ i ] = listIn -> data[ i - 1 ] ; 

    } 

    listIn -> data [ idx ] = value ;
    listIn -> length++ ;

}

/******** remove ********/
void list_remove(t_list* listIn, int idx){
  
    if( (idx >= listIn->length) || (idx < 0)){
      printf("Error!\n");
      return;
    }
    
   int i=idx;
   for(;i < listIn -> length;i++){
      listIn -> data[ i ] = listIn -> data[ i + 1 ] ; 
     }
     listIn -> length-- ;
  }
  
void list_remove_value(t_list* listIn, int value, enum OCCURENCE_Strategy occ){
  
  if(ALL == occ){
      int r=0,w=0;
  for(; r < listIn->length;r++){
    if(value != listIn->data[r]){
      if(r!=w) listIn->data[w] = listIn->data[r];
      w++;
    }
  }
    listIn -> length = w;
  }
  
  }
  
  void list_reverte_inside(t_list* list){
    int temp;
    int i=0;
    while(i< list->length/2){
      temp = list->data[i];
      list->data[i] = list->data[list->length-i-1];
      list->data[list->length-i-1] = temp ;
      i++;
    }
    
  }
  
  t_list* list_reverte(t_list* list){
    t_list* out = new(list->max_size);
    out->length = list-> length;
    int i = 0;
    for(; i < list-> length ; i++){
      
      out->data[i] = list->data[list-> length-i-1];
      
      }
    return out;
    }
    
  void list_insert_infinite(t_list* list, int idx,int value){
    
    if(list->length == list-> max_size){
        if(0 <= idx && idx <= list->length){
          int* tmpdata = ( int* ) malloc ( sizeof ( int ) * list-> max_size * 2 ) ;
          
          int i = list->length;
            for( ; i > idx ; i-- ){
                tmpdata[ i ] = list -> data[ i - 1 ] ; 
            }
            tmpdata[ i-- ] = value ;
            for(; i > 0 ; i--){
              tmpdata[i] = list -> data[i];
            }
            
            free(list -> data);
            
            list-> data = tmpdata;
            list->length ++;
            list-> max_size = list-> max_size * 2;
        }
        else printf("idx out of range!\n");
        
     }else return list_insert(list,idx,value);
  }
