#include <stdio.h>

// #2. 스택(메모리) 로 전달하는 방식
// => 32 bit C 컴파일러가 사용하는 방식


__attribute__((naked))
void Add()
{
	asm("mov   eax, edi"); 
	asm("add   eax, esi"); 
							

	asm("ret");		
}

__attribute__((naked))
int asm_main()
{
	asm("mov edi, 1");
	asm("mov esi, 2");
	asm("call Add");	
//-------------------------
	asm("ret");
}
int main()
{
	int n = asm_main();

	printf("main : %d\n", n);
}