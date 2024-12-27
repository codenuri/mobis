#include <stdio.h>

// 멀티 라인 매크로 기술
// => 2개이상의 문장을 한개의 매크로 함수로 하고 싶다.
// => 최선의 코드는 do ~ while(0) 입니다.
// => 리눅스 커널등에서도 널리 사용되는 아주 유명한 기술

#define PRESS()	 do { printf("press enter"); getchar(); } while(0)

int main()
{
	int n = 0;


	if ( n == 1 )
		PRESS();   
	else {}

	if ( n == 1 )
		do { printf("press enter"); getchar(); } while(0);   
	else {}


	printf("finish main\n");
}