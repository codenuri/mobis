// empty_struct.c

#include <stdio.h>

// 아무멤버도 없는 구조체
// C++ : 허용
// C   : 컴파일러마다 다른데, 안되는 경우가 많습니다.
struct AAA
{
};
int main()
{	
	printf("%d\n", sizeof(struct AAA));
	printf("%d\n", sizeof(struct AAA*));
}