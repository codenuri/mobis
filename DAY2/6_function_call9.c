#include <stdio.h>

// push, pop 을 사용하면
// => RSP 변경됩니다.

// 따라서, 인자나, 지역변수에 접근할때는
// rbp 를 사용하는데
// dword[rbp + @] : 함수 인자 접근 하는 코드
// dword[rbp - @] : 지역 변수 접근 하는 코드

// sub rsp, @  : 지역변수 공간 확보를 위해 RSP 내리는 코드
// add rsp, @  : 인자전달에 사용하 스택 파괴를 위해 RSP 올리는 코드


__attribute__((naked))
void Add()
{	
	// 아래 3줄이 함수의 prolog 입니다
	asm("push rbp");	  
	asm("mov  rbp, rsp");
	asm("sub  rsp, 24");


//	asm("mov dword[rbp-8], 10"); // 지역변수 사용


	asm("mov eax, dword[rbp + 12]"); 
	asm("add eax, dword[rbp + 20]");

	// 아래 3줄이 함수의 epilog 입니다.
//	asm("mov rsp, rbp");
//	asm("pop rbp");
	asm("leave"); // 이 명령이 위 2줄과 동일 

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