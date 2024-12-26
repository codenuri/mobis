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



