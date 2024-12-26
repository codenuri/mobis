// 114 page. flexible_array
#include "chronometry.h"

typedef struct _point
{
	int x;
	int y;
} POINT;

// 해결책 2. flexible array
// => 핵심 : 일반적으로  크기가 0인 배열을 만들수 없지만
//           구조체 마지막 멤버로는 만들수 있다.
// => 특징 : 구조체 크기에는 포함 안되지만, 구조체 사용시 멤버 이름으로 사용가능.

typedef struct _shapes
{
	int count;		
	POINT pos[0]; // flexible array
} SHAPES;

int main()
{
	SHAPES s;

	printf("%d\n", sizeof(s)); // 4
}
