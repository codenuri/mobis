#include <stdio.h>
#include <stdlib.h>

// memory pooling
// => 미리 커다란 크기의 메모리를 한번에 할당해서
// => 필요할때 마다 조금씩 사용하는 것

// 아래 코드는 32bit 용. 
// => 32bit 는 포인터 크기가 4바이트
/*
typedef struct _bullet
{
	int x;

	union
	{
		int y;
		struct bullet* next;
	};

} bullet;
*/

// 아래 코드는 64bit 용
// => 포인터 크기가 8byte(64bit)
typedef struct _bullet1
{
	union
	{	
		struct 
		{
			int x;
			int y;
		} pos;		// pos 는 struct { int x; int y; } 타입

		struct _bullet1* next;
	};

} bullet1;

typedef struct _bullet2
{
	union
	{	
		struct 
		{
			int x;
			int y;
		}; 				// 핵심 : pos 이름이 없습니다.

		struct _bullet2* next;
	};

} bullet2;

int main()
{
	bullet1 b1;		// pos 라는 이름이 있으면 아래 처럼 사용
	b1.pos.x = 10;	// pos 라는 이름 때문에 보기 좋지 않습니다.
	b1.pos.y = 10;
	b1.next = 0;

	bullet2 b2;
	b2.x = 10;
	b2.y = 10;
	b2.next = 0;

	printf("%d\n", sizeof(b1));
	printf("%d\n", sizeof(b2));


}
