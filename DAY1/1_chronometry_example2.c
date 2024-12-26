#include "chronometry.h"

const unsigned long long count = 10000000;

// 일반함수 
// add(1, 2);	
// => 인자 2개를 약속된 장소에 넣고 ( 32bit 환경 : 스택, 64bit 환경 : 레지스터)
// => 함수 로 이동 ( call add )
int add(int a, int b)
{
	return a + b;
}

// inline 함수
// => 함수 호출시, 해당 함수로 이동하는 것이 아니라.
// => 함수 구현부를 호출하는 위치에 치환해 달라.
// => C++ 에서 만들었지만, C언어도 나중에 지원
extern inline int inline_add(int a, int b)
{
	return a + b;
}

void ex1()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		int ret = add(1, 2);
	}
}

void ex2()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		int ret = inline_add(1, 2);
	}
}

int main()
{
	// 컴파일러 옵션에 따라 결과가 달라짐.
	// => 인라인 함수 같은 문법은 
	// => 최적화 옵션이 있을때만 적용됩니다.
	// => gcc 소스이름.cpp -O2
	// => gccbuild 소스이름.cpp -O2
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);	
}

// 성능 측정시 최적화 옵션(-O2)
// 1. -O2 옵션이 방해가 될수도 있습니다.
// => "불필요한 코드를 제거" 해서, 
// => 성능을 알고 싶은 코드가 제거 될수도 있습니다

// 2. -O2 옵션이 있어야 적용되는 문법도 있습니다.
// => inline 함수. 