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

void *MyMalloc(size_t noOfBytes)
{
struct block *ptr,*prev;
void *res;
  
  if(!(freeblock->size))
  { 
    initialize();
  
  }

ptr= freeblock;

  while(ptr->next!=NULL)
  {
 

    if(((ptr->size)==noOfBytes) || ((ptr->size)>(noOfBytes+sizeof(struct block))))
    {
      if ((ptr->size)>(noOfBytes+sizeof(struct block)))
      {
        split(ptr,noOfBytes);
      }
      ptr->free=0;
      res=(void*)(++ptr);
      printf("Memory allocated\n");
      return res;
    }

    else
    { 
      printf(" No sufficient memory\n");
      return 0;
    }
  }
}

