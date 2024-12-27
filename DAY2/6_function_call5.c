#include <stdio.h>

// 핵심 : 함수의 인자 전달
// 레지스터 : CPU 내부에 있는 메모리, 아주 빠르지만, 갯수 제한 있음
// 스택     : 보통 1M 이므로 충분한 크기지만, 외부 메모리 라서 레지스터 보다 느림.

// 32bit C 컴파일러 : 스택으로 전달
// 64bit C 컴파일러 : 레지스터로 전달

// 인라인 어셈을 사용하면 개발자가 위 2개 방법 모두 가능. 

// #1. 레지스터로 전달.
// => 호출자와 피호출자 사이에 약속만 하면 된다.
// => 보통 edi, esi 등의 레지스터를 많이 사용

__attribute__((naked))
void Add()
{
	// 약속된 장소(레지스터) 에서 꺼내서 사용하면 됩니다.
	asm("mov   eax, edi"); // eax = edi
	asm("add   eax, esi"); // eax += esi 
							// return 1번째 인자 + 2번째 인자

	asm("ret");		
}

__attribute__((naked))
int asm_main()
{
	asm("mov edi, 1");
	asm("mov esi, 2");
	asm("call Add");	// Add(2, 1)	
//-------------------------
	asm("ret");
}
int main()
{
	int n = asm_main();

	printf("main : %d\n", n);
}