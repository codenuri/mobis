#include <stdio.h>

int main()
{
	char sa1[] = "Hello";
	char sa2[] = "Hello";

	const char* sp1 = "Hello";
	const char* sp2 = "Hello";

	// 아래 코드 결과 예측해 보세요
	// => 같은 주소 ? 다른 주소 ?

	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);

}