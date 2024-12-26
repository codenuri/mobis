// 114 page. flexible_array
#include "chronometry.h"

typedef struct _point
{
	int x;
	int y;
} POINT;

// Point를 여러개 관리하는 구조체 
// => 아래 구조체는 10개의 Point 를 저장하게 됩니다.
// => 가변 갯수로 만들수 없을까요 ?
typedef struct _shapes
{
	int count;		// 점의 갯수 
	POINT pos[10];  
} SHAPES;


int main()
{
	SHAPES s;
	s.count = 5;
	s.pos[0].x = 10;
	s.pos[1].x = 10;
}
