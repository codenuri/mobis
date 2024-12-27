#include <stdio.h>

// 가변인자 함수의 핵심
// => 전달된 인자를 꺼낼수 있어야 합니다.
// => 32bit 건 64bit 건 가변인자의 함수 인자는 모두 스택에 있습니다.

// 관례
// 1. 모든 인자를 가변으로 하지 말고 1번째 인자는 이름 있는 인자 사용
// 2. 1번째 인자를 통해서 나머지 인자의 갯수와 타입전달

int sum( int cnt, ...  )
{
	int* p = &cnt; 

	p += 2;	// 스택에서 cnt 의 다음 칸으로 이동

	for( int i = 0; i < cnt; i++)
	{
		printf("%d\n", p[i*2] );
	}

	return 0;
}

int main()
{
	int n = sum(5, 1,2,3,4,5);

	printf("%d\n", n);
}


