// empty_struct.c

#include <stdio.h>

// 아무멤버도 없는 구조체
// C++ : 허용. 표준 문서에서 정확히 정의되어 있음.
// C   : 컴파일러마다 다른데, 안되는 경우가 많습니다. 표준문서에 없음. undefined 
struct AAA
{
};

int main()
{	
	printf("%d\n", sizeof(struct AAA));		// 구조체 자체의 크기는 C++ 은 1, C 언어는 다를수 있음. 
	printf("%d\n", sizeof(struct AAA*));	// 포인터 변수의 크기는 32bit 라면 4, 64bit 라면 8

	struct AAA aaa;

	struct AAA* p = &aaa;

	printf("%p, %p\n", p, p+1); // gcc : 같은 주소
								// g++ : 1 차이
}