#include "chronometry.h"

// 루프에서는 포인터를 "dereferencing" 사용하지 말라.

// [first ~ last] 구간의 합을 s 에 담는 함수. 
void bad(int first, int last, int* s)
{
	for (int i = first; i <= last; i++)
	{		
		*s += i;
	}
}

void good(int first, int last, int* s)
{
	int local = *s;

	for (int i = first; i <= last; i++)
	{	
		// 루프 안에서 결과는 지역변수에 담고..	
		local += i;
	}
	*s = local;
}

int main()
{
	int s1 = 0;
	int s2 = 0;

	CHRONOMETRY(bad,  1, 1000000, &s1 );
	CHRONOMETRY(good, 1, 1000000, &s2 );
}
