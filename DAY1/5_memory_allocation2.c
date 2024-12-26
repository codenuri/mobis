#include "chronometry.h"
#include <stdlib.h>

const int count = 10000000;

// stack vs heap 의 차이

// stack : 대부분 1M 의 크기(컴파일 옵션으로 변경가능)
//		   스레드당 한개씩 할당
//		   순차적으로 사용.
//         나중에 만든 변수가 먼저 파괴
//         메모리 할당에 오버헤드 없다.

// heap : 자유 기억 공간
//		  필요 없을때 언제라고 해지 가능
//        크기도 자동증가
//        메모리 할당에 오버헤드 있음(빈곳 찾아야 한다.)
//		  모든 스레드 공유
//		  메모리 파편화(조각) 현상발생. 

// 결론 : 자주 호출되는 함수(루프안에서 호출)
// => 되도록 힙을 사용하지 말고 스택을 사용하세요

void use_stack()
{
	int x[1000]; // stack 을 4k 사용
	x[0] = 0;
}

void use_heap()
{
	int* x = (int*)malloc(sizeof(int) * 1000);
				// heap 을 4k 할당해서 사용

	x[0] = 0;

	free(x);
}
void ex1()
{
	for (int i = 0; i < count; i++)
	{
		use_stack();
	}
}

void ex2()
{
	for (int i = 0; i < count; i++)
	{
		use_heap();
	}
}

int main()
{

	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}




