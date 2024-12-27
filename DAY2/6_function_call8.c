#include <stdio.h>

// 지역변수 만들고 파괴 하기 

__attribute__((naked))
void Add()
{	
	asm("push rbp");	  
	asm("mov  rbp, rsp");
	asm("sub  rsp, 24");// 필요한 지역변수 크기 만큼 rsp 를 아래로 이동
						// 요즘은 실제 필요한것 보다 좀더 넉넉하게 잡아 놓습니다.
						// 이 코드가 지역변수 할당

	// 지역변수는 스택에 있으므로 그냥 스택에 보관하면 됩니다
	asm("mov dword[rbp-8], 10");


	asm("mov eax, dword[rbp + 12]"); 
	asm("add eax, dword[rbp + 20]");

	// 함수 호출이 끝나면 지역변수는 파괴 되어야 합니다.
	// => 만들어 보세요

	asm("pop rbp");
	asm("ret");		
}


__attribute__((naked))
int asm_main()
{
	asm("push 2");	
	asm("push 1");
	asm("call Add");
	asm("add rsp, 16"); 


//-------------------------
	asm("ret");
}

int main()
{
	int n = asm_main();	

	printf("main : %d\n", n);
}