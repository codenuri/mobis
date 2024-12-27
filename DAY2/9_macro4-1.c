#include "chronometry.h"

void ex1(int a, int b) {}

int main()
{	
	CHECK(START);
	ex1(1, 2);
	printf("ex1 : ");
	CHECK(END);

	// 위 4줄을 아래 처럼 사용하도록 해 봅시다.
	chronometry(ex1, 1, 2);
}