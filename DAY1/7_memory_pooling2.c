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
typedef struct _bullet
{
	union
	{	
		struct 
		{
			int x;
			int y;
		} pos;

		struct bullet1* next;
	};

} bullet1;

int main()
{
	bullet1 b1;
	

}
