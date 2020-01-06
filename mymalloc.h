#include<stddef.h>

char memory[25000]; 

struct block
{
	size_t size;
	int free;
	struct block *next;
};

struct block *freeblock = (struct block*)memory;

void initialize();
void split(struct block *match,size_t size);
void combine();
void *MyMalloc(size_t noOfBytes);
void MyFree(void* point); 
