#include<stdio.h>
#include<stddef.h>
#include"mymalloc.h"


void initialize(){
freeblock->size=25000-sizeof(struct block); 
freeblock->free=1;
freeblock->next=NULL;
}


void split(struct block *match,size_t size){
struct block *new=(void*)((void*)match+size+sizeof(struct block));


new->size=(match->size)-size-sizeof(struct block);
new->free=1;
new->next=match->next;

match->size=size; 
match->next=new;
 

  }