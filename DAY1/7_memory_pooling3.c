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

/*
void pool_init()
{
	// #1. 200개 총알을 한번에 메모리 할당
	pool_head = (bullet*)malloc(sizeof(bullet) * SIZE);


	// #2. 모든 총알을 list 형태로 연결
	for( int i = 0; i < SIZE -1; i++)
	{
		pool_head[i].next = &(pool_head[i+1]);
	}
}

void pool_destroy()
{
	free(pool_head);
	pool_head = 0;
}
*/

void pool_init()
{
	// malloc 과 free 를 사용하지 못하는 환경(임베디드 라면)
	// 아래 처럼 해도 됩니다.
	// => .data 섹션 활용
	static char pool[sizeof(bullet) * SIZE];

	pool_head = (bullet*)&pool;


	// #2. 모든 총알을 list 형태로 연결
	for( int i = 0; i < SIZE -1; i++)
	{
		pool_head[i].next = &(pool_head[i+1]);
	}
}

// pool 에서 총알 한개를 할당하는 함수
// => pool 의 제일 앞에 총알 반환
bullet* pool_alloc()
{
	bullet* temp = pool_head;
	pool_head = pool_head->next;
	return temp;
}

// 더이상 사용하지 않으면 
// => pool 의 제일 앞쪽으로 연결
// => 싱글리스트 앞쪽에 넣는 코드 입니다.
void pool_free(bullet* p)
{
	p->next = pool_head;
	pool_head = p;
}

// 위 코드는 
// 최근에 반납한것이 pool 앞쪽에 있고
// 새로 할당하면 pool 앞을 반환 합니다.
// => 즉, 가장 최근에 사용된 것이 다시 사용.
// => 가장 최근에 사용된것은 캐쉬에 있을확률이 높습니다. 캐쉬 적중률 증가 

int main()
{
	pool_init();

	bullet* p1 = pool_alloc();
	bullet* p2 = pool_alloc();

	p1->x = 10;
	p1->y = 10;	// 이렇게 사용하면 p1->next 정보는 손실.
				// 하지만 다시 pool 에 놓일때 
				// p1->next = pool_head 로 채워 집니다.

	printf("%p\n", p1);
	pool_free(p1);				// pool 의 list 의 제일 앞쪽에 다시 넣고
								// 이순간 다시 p1->next = pool_head 이므로
								// 문제 없음. 

	bullet* p3 = pool_alloc(); 	// p3 는 결국 방금 반납한 p1 입니다.
	printf("%p\n", p3);			// pool 의 list 의 제일 앞쪽에서 꺼내기
}

// pool 을 사용하면
// 1. 메모리 크기가 총알당 한개가 아닌 pool 전체의 크기 한개만 추가 할당
// 2. pool 안에서는 동일 크기 메모리 할당 사용하므로 파편화 현상 없습니다
// 3. 실제 할당이 아닌 list 연산이므로 할당/해지가 아주 빠르게 됩니다.
// 4. static 메모리를 힙처럼 사용도 가능. 