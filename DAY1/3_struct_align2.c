#include "chronometry.h"

const unsigned long long count = 100000000;

// padding 이 있을때
typedef struct _packet1
{
	char cmd;
	int data;
} PACKET1;

// padding 제거. 
#pragma pack(1)
typedef struct _packet2
{
	char cmd;
	int data;
} PACKET2;


PACKET1 packet1;
PACKET2 packet2;

void ex1()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		packet1.data = i;
	}
}

void ex2()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		packet2.data = i;
	}
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);

	printf("%p\n", &(packet1.data) ); // 4의 배수
	printf("%p\n", &(packet2.data) ); // 4의 배수 아님.
}
// 결론
// => 컴파일러가 구조체 멤버의 시작 주소를 4바이트로 맞춰 놓으면
// => 그렇지 않을때보다 아주 빨라 집니다.

// 16비트 CPU : 주소선이 16개 => 64k 메모리만 사용가능. (2^16)
//             => 그런데, 주소 1을 1번지가 아닌 4번지로 생각하면 "4배의 메모리" 를 더 연결가능.
//			   => 그래서 CPU 가 주소선으로 3을 보내면 3*4해서 12번지를 의미 합니다.

// 결론 : CPU 는 메모리에서 4의 배수 주소 단위로 읽어 오게 됩니다.
// 1. 1004 번지에서 4바이트 읽기 : 한번에 읽어 오게 됩니다.

// 2. 1001 번지에서 4바이트 읽기
//    => A. 1000번지에서 4바이트 읽고
//    => B. 1004번지에서 4바이트 읽어서
//	  => A에서 3바이트, B에서 1바이트를 꺼내서
//       4바이트로 만들어어서 사용. 

// 결론 
// => N/W 에서 사용되는 데이타는 padding 이 있으면 안되지만
// => 일반적인 구조체라면 모든 멤버의 시작 주소를 4의 배수로 되도록 하는 것이 빠르게 동작합니다.



