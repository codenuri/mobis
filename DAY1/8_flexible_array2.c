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

	// 단점 : 위 코드의 메모리 모양을 생각해 보세요
	// => 연속된 메모리가 아닌 떨어진 메모리를 사용하는 모양입니다.
	// => s.count 의 위치와, s.pos 의 점들은 다른 메모리 공간

	// s.count 와 점들을 연속되게 할수 없을까요 ?
	// => flexible array 기술!!!!
}
