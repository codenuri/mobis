#include <stdio.h>
#include <stdlib.h>

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

void __insert_node(int data, NODE* prev, NODE* next)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;

	temp->prev = prev;
	temp->next = next;

	prev->next = temp;
	next->prev = temp;
}

// 이번소스의 핵심 
// => list 앞과 뒤에 삽입하기
// => 이소스에서 "더미 노드"의 장점이 등장합니다.

// list 의 제일 앞에 data 추가하기
void insert_front(int data)
{
	// 더미노드가 없다면
	// => list 가 비어있을때와 아닐때를 구별해야 합니다.

	// 더미가 있다면
	// => 더미(head) 와 더미다음(head->next) 사이에 넣으면 됩니다.
	__insert_node(data, head, head->next);
}




void insert_back(int data)
{
	// 마지막 노드(head->prev) 와 더미(head) 사이에 넣는다.
	// => 환영이므로 마지막 노드는 "더미->prev" 입니다.
	
	__insert_node(data, head->prev, head);
}

void show()
{
	NODE* cur = head->next; // 더미 다음 부터가 실제 데이타.

	for ( ; cur != head; cur = cur->next)
	{
		printf("%d, ", cur->data);
	}
}

int main()
{
	init_node();

	insert_front(10);
	insert_front(20);
	insert_front(30);
	insert_back(40);
	insert_back(50);

	show(); // 30 20 10 40 50 
}