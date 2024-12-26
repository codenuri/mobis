#include <stdio.h>
#include <stdlib.h>
#include "chronometry.h"

typedef struct _bullet
{
	union
	{	
		struct 
		{
			int x;
			int y;
		}; 				
		struct _bullet* next;
	};

} bullet;


#define SIZE 200

bullet* pool_head = 0;


void pool_init()
{

	static char pool[sizeof(bullet) * SIZE];

	pool_head = (bullet*)&pool;

	for( int i = 0; i < SIZE -1; i++)
	{
		pool_head[i].next = &(pool_head[i+1]);
	}
}

bullet* pool_alloc()
{
	bullet* temp = pool_head;
	pool_head = pool_head->next;
	return temp;
}


void pool_free(bullet* p)
{
	p->next = pool_head;
	pool_head = p;
}
// --------------------------------------------------------
int count = 10000;

void ex1()
{
	pool_init();

	// pool 사용
	for(int i = 0; i < count; i++ )
	{
		bullet* p1 = pool_alloc();
		bullet* p2 = pool_alloc();

		pool_free(p1);				

		bullet* p3 = pool_alloc(); 	

		pool_free(p3);
		pool_free(p2);
	}	
}
void ex2()
{
	// malloc/free
	for(int i = 0; i < count; i++ )
	{
		bullet* p1 = malloc(sizeof(bullet));
		bullet* p2 = malloc(sizeof(bullet));

		free(p1);				

		bullet* p3 = malloc(sizeof(bullet)); 	
		
		free(p3);
		free(p2);
	}	
}
int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}
