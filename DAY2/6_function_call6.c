#include <stdio.h>

// #2. 스택(메모리) 로 전달하는 방식
// => 32 bit C 컴파일러가 사용하는 방식

// => 이번 단계가 중요합니다. 
// => "스택에 어떤 데이타가 어떤 순서로 있는지 정확히 파악해야 합니다.""

__attribute__((naked))
void Add()
{
	// 스택에 있는 인자를 꺼내야 한다!!
	asm("pop esi");  // 스택 제일 위의 값을  꺼내서 esi 에 담기
					 // 안됩니다. 지금 스택 꼭대기는 "돌아갈주소"가 있습니다.

							

	asm("ret");		
}

__attribute__((naked))
int asm_main()
{
	asm("push 2");	// 스택에 마지막 인자 부터 차례대로 넣고
	asm("push 1");
	asm("call Add");// 함수로 이동	



//-------------------------
	asm("ret");
}

int main()
{
	int n = asm_main();

	printf("main : %d\n", n);
}