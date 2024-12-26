#include "chronometry.h"

// loop1. 루프를 적게 사용하라
// => 2~3회의 루프를 사용할것이라면 
//    루프를 사용하지 말고, 직접 하는 것이 효율적이다.
// => 루프 관련 코드의 오버헤드도 있다.
void foo(int n) {n = 10;}

void bad()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		foo(i);
	}
}

void good()
{
	foo(1);
	foo(2);
	foo(3);
}

int main()
{
	bad();
	good();
}


