//#include <stdio.h>

// 매크로를 학습하거나 사용할때
// => -E, -P 옵션을 활용하면 편리합니다.

// gcc 소스.cpp -E -P  해보세요

#define SQUARE(x) x * x
#define MAX 5

int main()
{
	int n = MAX;

	int ret = SQUARE(++n);

//	printf("%d\n", ret);
}