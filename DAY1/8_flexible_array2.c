// 114 page. flexible_array
#include "chronometry.h"

typedef struct _point
{
	int x;
	int y;
} POINT;

// 해결책 1. 배열 대신 포인터 사용하면 어떨까 ?

typedef struct _shapes
{
	int count;		
	POINT* pos
} SHAPES;

int main()
{
	SHAPES s;
	s.count = 5;
	s.pos = malloc(sizeof(POINT) * s.count);

	// s.pos 는 포인터 이지만 배열 처럼 가능하므로 아래 처럼 사용해도 됩니다.
	s.pos[0].x = 10;
	s.pos[0].y = 10;

	s.pos[1].x = 10;
	s.pos[2].y = 10;
}
