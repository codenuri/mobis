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
    static int sx = 0xAABBCCDD;

    int lx = 0x55667788;
    
	printf("hello world\n");

    int* p = (int*)malloc(sizeof(int) * 10);
    free(p);
}

int main(void)
{
    foo();
}
