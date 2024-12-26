// 11 page 그림
// PEView - 32bit
#include <stdio.h>
#include <stdlib.h>

// 아래 코드를 보고, 각각의 초기값이 
// 실행파일(메모리)에 어디에 있는지 정확히 생각해 봅시다.

int  g1 = 0x11223344; 
char g2[] = "abcdefg";

void foo(void)
{
	// foo의 지역변수 만큼 스택 확보- 내일 자세히
	// => lx, p 의 크기만큼 확보

    static int sx = 0xAABBCCDD;
	// => 이미 초기값이 메모리에 있음.
	// => 실행시 넣는 것이 아님
	// => 컴파일시 .data 섹션에 초기값 있음.

    int lx = 0x55667788;
	// => 이코드는 실행시 스택에 값을 넣은것
	// => mov lx위치(스택주소), 0x55667788
    
	printf("hello world\n");

    int* p = (int*)malloc(sizeof(int) * 10);
    free(p);
}

int main(void)
{
    foo();
}
