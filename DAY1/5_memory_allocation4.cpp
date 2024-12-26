#include "chronometry.h"
#include <stdlib.h>
#include <vector>
#include <array>

const int count = 10000000;

void use_stack()
{
	int x[1000];
	x[0] = 0;
}

void use_heap()
{
	std::vector<int> v(1000); // 동적 메모리 할당
	v[0] = 0;
}

void ex1()
{
	for (int i = 0; i < count; i++)
	{
		use_stack();
	}
}

void ex2()
{
	for (int i = 0; i < count; i++)
	{
		use_heap();
	}
}

int main()
{

	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}




