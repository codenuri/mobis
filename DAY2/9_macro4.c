#include <stdio.h>

// 가변인자 매크로
// => ... 위치에 보내는 모든 것을 __VA_ARGS__ 위치에 놓어 달라.

#define debug( ... ) printf( "[debug]" __VA_ARGS__ )

int main()
{
	int a = 1;
	int b = 2;

	debug("message");
	debug("a = %d, b = %d", a, b);
}

