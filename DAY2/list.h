// list.h
#pragma once

// 핵심 : 아래 코드는 데이타는 없고, 오직 list 의 노드만 조작 합니다.

typedef struct _node
{
	struct _node* prev;
	struct _node* next;
} NODE;

// 더미 노드 초기화
void init_list(NODE* head)
{
	head->next = head;
	head->prev = head;
}

void __insert_node(NODE* temp, NODE* prev, NODE* next)
{
	temp->prev = prev;
	temp->next = next;

	prev->next = temp;
	next->prev = temp;
}

void insert_front(NODE* node, NODE* head)
{
	__insert_node(node, head, head->next);

}
void insert_back(NODE* node, NODE* head)
{
	__insert_node(node, head->prev, head);
}

// 이 헤더에 있는 list 를 사용하려면

// 1. 더미 노드를 만든후에 init_list() 함수에 전달
// 
// 2. insert_back, insert_after 는 아래 처럼 사용
//    insert_back(신규노드, head) 