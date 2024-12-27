#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>  // 이 헤더에 offsetof  매크로가 있습니다.
#include "list.h"

typedef struct _People
{
	char name[12];
	int  age;

	NODE vipList;	
} People;


// 이번 예제의 핵심 : list 안에 있는 모든 People 출력하기
void show_vip_list(NODE* head)
{	
	NODE* cur = head->next;


	for ( ; cur != head; cur = cur->next)
	{
		// 현재 cur 의 주소는 People 객체(변수)의 주소가 아닙니다.
		// People 객체안에 있는 vipList 멤버의 주소 입니다.
		// => offsetof 로 People 로 부터 vipList 가 어디 있는지 위치를 찾고
		//    그정보로 People 객체의 주소를 얻어서 출력 
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
