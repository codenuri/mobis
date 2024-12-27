#include <stdio.h>

typedef struct _node
{
	int data;
	struct _node* prev;
	struct _node* next;
} NODE;

NODE* head = 0;

void init_node()
{
	head = (NODE*)malloc(sizeof(NODE));
	head->data = 0;

	head->next = head;
	head->prev = head;
}

// 이번 소스 핵심 : 2개의 NODE 사이에 data 넣기
// => 복습 할때 "2개 노드를 그려 놓고, 아래 코드만 이해하시면 됩니다" !!
// => 가장 중요한 부분이므로 꼭 이해 하세요
void __insert_node(int data, NODE* prev, NODE* next)
{
	// 새로운 NODE 생성
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;

	// 1. 그림을 그리세요
	// 2. 변해야 하는 곳을 체크 하세요
	// 3. 변해야 하는 순서를 적으세요(중요, 항상 새로운 것을 먼저 설정)

	temp->prev = prev;
	temp->next = next;

	prev->next = temp;
	next->prev = temp;
}

int main()
{
	init_node();
}