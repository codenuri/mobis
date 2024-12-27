#include <stdio.h>

// godbolt.org 에서 아래 코드의 어셈블리 코드를 확인해 보세요

int Add(int a, int b)
{
	return a + b;	// mov eax, a + b
}

int main()
{
	int n = Add(10, 20);	// mov n, eax 
	
	printf("%d\n", n);
}