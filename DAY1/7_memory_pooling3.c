#include <stdio.h>
#include <stdlib.h>

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

void init_pool()
{
	// #1. 200개 총알을 한번에 메모리 할당
	pool_head = (bullet*)malloc(sizeof(bullet) * SIZE);

	// #2. 모든 총알을 list 형태로 연결
	for( int i = 0; i < SIZE -1; i++)
	{
		pool_head[i].next = &(pool_head[i+1]);
	}
}







int main()
{

}
