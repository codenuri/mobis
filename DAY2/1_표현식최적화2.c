#include <stdio.h>

// 비용이 적은 연산자를 사용하라.
int main()
{
	// #1. % 연산자 보다 비트 연산자가 빠르다.
	if (i % 2 == 1) { printf("%d 는 홀수 입니다 \n", i); } // bad
	if (i & 1)      { printf("%d 는 홀수 입니다 \n", i); } // good


	int i = 352;

	// #2. 나눗셈은 아주 느리다.
	// => 나누는 값이 2의 배수라면 "shift" 연산자로 대체 가능
	// => 32로 나누는 것은 ">> 5" 와 동일
	int ret1 = i / 32;	// bad	
	int ret2 = i >> 5;	// good
	
}
