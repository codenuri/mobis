#include <stdio.h>

// 2번 예제는
// => 컴파일러의 종류, 32/64 bit 여부에 따라 결과가 달라 질수 있습니다.
// => 제대로 동작하지 않을수 있습니다.
// => 그래서 C 표준이 제공하는 방식으로 꺼내야 합니다.
// => 2번은 원리 설명예제, 실전은 3번 처럼.   

#include <stdarg.h>

int sum( int cnt, ...  )
{
	va_list ap;			// 대부분의 환경에서 char* 타입입니다.

	va_start(ap, cnt);	// ap = &cnt + 4 또는 8. 즉, cnt 의 다음 스택을 가리키도록 설정

	int s = 0;

	for( int i = 0; i < cnt; i++)
	{
		s += va_arg(ap, int); // 1. ap 가 가리키는 곳에서 int 만큼 꺼내고
							 // 2. ap 자체는 sizeof(int) 만큼 이동
	}

	va_end(ap);	// 대부분 컴파일러에서는 va_end() 는 하는 일이 없는데..
				// 표준에서는 한번 호출하라고 규정되어 있습니다.
				// 컴파일러에 따라 어떤 작업을 할수도 잇습니다.
	return s;
}

int main()
{
	int n = sum(5, 1,2,3,4,5);

	printf("%d\n", n);
}


