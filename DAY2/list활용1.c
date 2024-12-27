#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// list.h 사용하기

// #1. 구조체 안에 NODE 를 멤버로 넣으세요.  

typedef struct _People
{
	char name[12];
	int  age;

	NODE vipList;	// 이 안에 prev, next 가 있습니다.
					// NODE 안에 데이타를 넣지 말고, 
					// 데이타 안에 NODE 를 넣자!!!
} People;

int main()
{
	// #2. 더미 노드 만들어서 init_list 에 전달
	NODE* vip_head = (NODE*)malloc(sizeof(NODE));
	init_list(vip_head);

	for( int i = 1; i < 10; i++)
	{
		People* p = (People*)malloc(sizeof(People));
		p->age = i;
		sprintf(p->name, "lee %d", i);	

		// #3. list 에 넣으려면 구조체 안의 NODE 멤버 주소를 전달하면 됩니다.
		insert_back(&(p->vipList), vip_head);
	}
}
// 이번 예제에서는 list 에 넣는 코드만..
// 출력은 다음 예제..