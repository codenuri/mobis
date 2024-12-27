#include <stdio.h>

// 매크로 함수의 장점. 
// 1. 호출이 아닌 치환 이므로 빠르다.
// 2. 모든 타입에 대해서 동작하는 Generic 함수
//    => C는 템플릿이 없지만 매크로를 사용하면 해결

// 단점
// => 버그가 너무 많다.

#define SQUARE(x) ((x) * (x))

int main()
{
	int    ret1 = SQUARE(3);	// int 도 되고
	double ret2 = SQUARE(3.3);	// double 도 가능. 

	int n = 3;
//	int ret3 = SQUARE(n + 1); // ((n + 1) * (n + 1)) 이경우는 ok
	int ret3 = SQUARE(++n);   // ((++n) * (++n))  이 경우는 해결될수 없다. 버그. 
							  // => undefined. 컴파일러에 따라 결과다를수 있다.
							  // => 매크로 함수 사용시 인자로 ++이 사용되면 버그. 

	printf("%d\n", ret3);

}