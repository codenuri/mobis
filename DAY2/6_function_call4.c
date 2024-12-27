#include <stdio.h>

// 핵심 : 함수를 호출하는 방법
// "call 함수이름" 사용
// => 돌아올 주소를 스택에 넣는 것을 꼭 기억하세요 (핵심 입니다.)

__attribute__((naked))
void Add()
{
	asm("mov   eax, 30"); // 반환값을 약속된 장소(eax) 에 넣고

	// ret가 하는일이  아래 2줄 입니다.
	asm("ret");		// pop rbx(임의레지스터)   <= 스택에 있는 돌아갈 주소를 꺼내서 rbx에 담고
					// jmp rbx				  <= 그 주소로 이동
}

__attribute__((naked))
int asm_main()
{
	asm("call Add");	// push .NEXT   <= 돌아올 주소를 스택에 넣고
						// jmp  Add
						// .NEXT		<= 이 위치의 주소를 코드에서 사용하기 위한 LABEL
//-------------------------
	asm("ret");
}
int main()
{
	int n = asm_main();

	printf("main : %d\n", n);
}