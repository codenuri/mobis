#include <stdio.h>

typedef struct _packet1
{
	char cmd;
//	char padding[3]; 	// 컴파일러가 추가한 코드
	
	int data;	// 이 data 멤버의 시작주소를 
				// 4의 배수로 만들기 위해서 위에 padding 추가
} PACKET1;


// N/W 이나 RS232 등의 통신에는 컴파일러가 추가한 멤버(padding) 이 
// 있으면 안됩니다.
#pragma pack(1)			// struct 의 멤버 align 을 1byte 단위 로 해달라는 것
typedef struct _packet2
{
	char cmd;
	int data;
} PACKET2;

int main()
{
	printf("%d\n", sizeof(PACKET1)); // 8
	printf("%d\n", sizeof(PACKET2)); // 5

	PACKET1 p1;
	PACKET2 p2;

	// 아래 코드의 결과로 나오는 주소를 잘보세요(4의 배수인지 아닌지)
	printf("%p\n", &(p1.cmd));
	printf("%p\n", &(p1.data));
	printf("%p\n", &(p2.cmd));
	printf("%p\n", &(p2.data));
}
