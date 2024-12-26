#include "chronometry.h"

const unsigned long long count = 10000000;

void ex1(int a, int b)
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		int n = a + b;
	}
}

int main()
{
	// CHRONOMETRY 사용법
	// => CHRONOMETRY(함수이름, arg1, arg2, arg3, .... )
	// => 인자 갯수 제한이 없습니다.
	
	// 인자가 있는 함수도 사용가능.
	CHRONOMETRY(ex1, 1, 2);

}
