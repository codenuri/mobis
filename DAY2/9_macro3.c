#include <stdio.h>

// 멀티 라인 매크로 기술
// => 2개이상의 문장을 한개의 매크로 함수로 하고 싶다.

#define PRESS()	 { printf("press enter"); getchar(); }

int main()
{
	int n = 0;

	// #1
	PRESS(); 	// ok

	// #2.
	if ( n == 1 )
		PRESS();	// {} 가 있으면 ok

	// #3. 핵심. 아래 코드는 에러 입니다. 해결책은 뭘까요 ?
	if ( n == 1 )
		PRESS();   // {  printf("press enter"); getchar();   };  // <== ; 때문에 에러!
	else 
	{
		//... 
	}


	printf("finish main\n");
}