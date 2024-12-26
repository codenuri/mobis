// 114 page. flexible_array
#include "chronometry.h"

typedef struct _point
{
	int x;
	int y;
} MYPOINT;

// 해결책 2. flexible array
// => 핵심 : 일반적으로  크기가 0인 배열을 만들수 없지만
//           구조체 마지막 멤버로는 만들수 있다.
// => 특징 : 구조체 크기에는 포함 안되지만, 구조체 사용시 멤버 이름으로 사용가능.

typedef struct _shapes
{
	int count;		
	MYPOINT pos[0]; // flexible array
} SHAPES;

int main()
{
	SHAPES s;

	printf("%d\n", sizeof(s)); // 4

	// flexible array 를 포함하는 구조체는 대부분 "동적할당" 해서 사용하게 됩니다.

	SHAPES* sp = malloc(sizeof(SHAPES) + sizeof(MYPOINT) * 5);
				// malloc( 4 + 40 ) => 44 바이트 할당하고 SHAPES* 처럼 해석
				// => count 한개 + MYPOINT 5개로 해석
	sp->count = 5;
	sp->pos[0].x = 10;  // pos 라는 이름 사용가능
	sp->pos[0].y = 10;
	sp->pos[1].x = 10;  
	sp->pos[1].y = 10;

	// 위 코드의 메모리 그림을 생각해 보세요
	// => sp->count 와 sp->pos 는 연속된 메모리 공간에 있습니다.

	// 참고, malloc(C) vs new (C++)
	// new : 갯수
	// malloc : 크기(바이트 단위)
//	int* p1 = new int[20]; 		// int 타입 20개 할당 => 즉, 4 * 20 => 80 바이트 할당
//	int* p1 = (int*)malloc(20);	// 20 바이트 할당하는데, 그 주소를 int 타입으로 해석하겠다.
								// int 5개 할당
								// 캐스팅 없어도 가능 (int*)
}
