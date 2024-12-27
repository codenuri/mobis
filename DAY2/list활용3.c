#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>  // 이 헤더에 offsetof  매크로가 있습니다.
#include "list.h"

// 한명의 사람은 여러 조직에 소속될수 있습니다.
// => 친구들 목록
// => 회사 직원 목록
// => 가족 목록등 

typedef struct _People
{
	char name[12];
	int  age;
	
	// 아래 처럼하면 하나의 객체를 여러 list 에 포함할수 있습니다.
	NODE vipList;
	NODE friendList;

} People;



void show_vip_list(NODE* head)
{
	NODE* cur = head->next;

	for (; cur != head; cur = cur->next)
	{
		int ds = offsetof(People, vipList);

		People* p = (People*)((char*)cur - ds);

		printf("%s(%d), ", p->name, p->age);
	}
}

int main()
{
	NODE* vip_head = (NODE*)malloc(sizeof(NODE));
	init_list(vip_head);

	for (int i = 1; i < 10; i++)
	{
		People* p = (People*)malloc(sizeof(People));
		p->age = i;
		strcpy_s(p->name, 4, "lee");

		insert_back(&(p->vipList), vip_head);
	}

	show_vip_list(vip_head);
}

// 위 코드는 People 을 만들때 malloc 을 사용합니다.
// 오늘 1교시에 했더는 "전역변수를 사용한 bullet pool" 처럼
// People 의 pool 을 만들어 사용하면 
// malloc 없이도 "data 메모리를 사용한 linked list 를 만들수 있습니다."
// "pool_alloc()"


// 복습하시다가 질문있으면 메일(smkang@codenuri.co.kr)로 보내주세요.