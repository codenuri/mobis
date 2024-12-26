#include "chronometry.h"
#include <stdlib.h>

const int count = 10000000;

// stack 과 heap 은
// => 메모리 할당 자체에 성능 차이는 크지만
// => 할당후 사용하는 것 에는 성능 차이는 거의 없습니다.


void ex1()
{
	int x[10];
	for (int i = 0; i < count; i++)
	{
		x[0] = 0;
	}
}

void ex2()
{
	int* x = (int*)malloc(sizeof(int)*10);
	
	for (int i = 0; i < count; i++)
	{
		x[0] = 0;
	}

	free(x);
}

int main()
{

	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}




