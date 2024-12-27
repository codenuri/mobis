#include <stdio.h>


__attribute__((naked))
void Add()
{	
	// 함수 시작시 RSP 값을 RBP에 보관
	// 단, 다른 함수에서 RBP를 사용할수도 있으므로 스택에 RBP 보관했다가 끝날때 복구
	asm("push rbp");	  // rbp 예전값 보관
	asm("mov  rbp, rsp");


	// 인자에 접근하기 전에 이 위치에서 스택을 사용하면 RSP 변하게 됩니다
//	asm("push 100"); // 이순간 RSP 변경
					 // 하지만 rbp 는 변경 안됨.


	asm("mov eax, dword[rbp + 12]"); 
	asm("add eax, dword[rbp + 20]");

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