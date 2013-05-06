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

/*** get index value ***/
int list_chain_get_value_by_index( T_list_chain* listIn, int idx ) ;

/**** get value by for  ***/
int list_chain_get_index_for_value( T_list_chain* , int , enum OCCURENCE_STRATEGY ) ;

/*** insertion of element ***/
void list_chain_insert( T_list_chain** , int , int ) ;

/*** remove by value ***/
void list_chain_remove_value( T_list_chain ** , int , enum OCCURENCE_STRATEGY ) ;

/*** remove by index ***/
void list_chain_remove_index(T_list_chain** , int );


/**** main *********/
int main ( int argc , char ** argv ){
    T_list_chain* list   = list_chain_new( 12 ) ; 
    list -> next         = list_chain_new( 3 ) ; 
    list -> next -> next = list_chain_new( 8 ) ; 
    list -> next -> next -> next = list_chain_new( 10 ) ; 
    list -> next -> next -> next -> next = list_chain_new( 80 ) ; 

    list_chain_display( list ) ;
    printf( "La taille vaut:%d \n", list_length( list ) ) ;
    printf( "value:%d\n",list_chain_get_value_by_index(list,2));
    printf( "value:%d\n",list_chain_get_value_by_index(list,26));
    printf( "index:%d\n",list_chain_get_index_for_value(list, 8,LAST));
    list_chain_insert(&list,23,0);
    list_chain_insert(&list,23,2);
    list_chain_display( list ) ;
    //printf( "La taille vaut:%d \n", list_length( list ) ) ;
    list_chain_remove_value(&list,23,ALL);
    list_chain_remove_index(&list,2);
    list_chain_display( list ) ;
    printf( "La taille vaut:%d \n", list_length( list ) ) ;
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


int list_chain_get_value_by_index(T_list_chain* listIn, int index){
    
    while(listIn && index--){
      listIn = listIn -> next ; 
      }
      if(-1==index) return listIn->value;
      else return -1;
  }

int list_chain_get_index_for_value(T_list_chain* listIn, int value,enum OCCURENCE_STRATEGY occ){
    
    int index=0,save=-1;
    while(listIn){
      if(listIn->value == value){
        if(FIRST == occ) 
          return index;
         save = index;
      }
      listIn = listIn -> next ;
      index++;
      }
      return save;
  }
  
  void list_chain_insert(T_list_chain** listIn, int value,int index){
    while(listIn && index-- && (listIn=&(*listIn)->next));
    if(-1==index){
        T_list_chain* tmp = *listIn;
        (*listIn) = list_chain_new(value);
        (*listIn)->next = tmp;
    }
  }

  void list_chain_remove_value(T_list_chain** listIn, int value, enum OCCURENCE_STRATEGY strategy){
    switch (strategy){
        case FIRST:
          while(listIn && ((*listIn)->value != value) && (listIn=&(*listIn)->next));
          if((*listIn)->value == value) {
            T_list_chain* tmp = (*listIn)->next;
            free(*listIn);
            *listIn = tmp;
          }
          break;
        case LAST:{
          T_list_chain** tmplast = NULL;
          while(*listIn){
            if((*listIn)->value == value) tmplast = listIn;
          listIn = &(*listIn)->next;
          }
          if(*tmplast != NULL){
            T_list_chain* tmp2 = (*tmplast)->next;
            free(*tmplast);
            *tmplast = tmp2;
          }
          break;}
        case ALL:
          while(*listIn){
            if((*listIn)->value == value) {
              T_list_chain* tmp = (*listIn)->next;
              free(*listIn);
              *listIn = tmp;
            }
          listIn=&(*listIn)->next;
          } break;
        default:
          break;
    }

  }

  void list_chain_remove_index(T_list_chain** listIn, int index){
    while(listIn && index-- && (listIn=&(*listIn)->next));
    if(-1==index){
    T_list_chain* tmp = (*listIn)->next;
    free(*listIn);
    *listIn = tmp;
    }
  }

