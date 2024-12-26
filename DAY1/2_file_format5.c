#include <stdio.h>
#include <stdlib.h>

int g = 10;

int main()
{
	static int s = 10;
	int n = 10;

	// 아래 코드의 결과로 나오는 주소들의 생각해 보세요.
	// => 유사한 주소인지 ? 
	// => 전혀 다른 위치 인지에 대해서 생각해 보세요.
	printf("main 주소      : %p\n", &main); // .text
	printf("전역변수 주소   : %p\n", &g);	 // .data
	printf("static지역 주소:%p\n", &s);		// .data
	printf("지역 주소      :%p\n", &n);	    // stack

	int* p = (int*)malloc(4);
	printf("힙 할당 주소 : %p\n", p);		// heap

	free(p);
}
// 한글 깨지만 "chcp 65001" 하시면 됩니다.
