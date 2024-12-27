#include <stdio.h>
#include <stdlib.h>

// int 뿐 아니라 모든 타입을 보관가능하게 #1. 

typedef struct _node
{
	int data;			// 이렇게 하면 int 만 저장할수 있습니다.

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

//--------------------------------------------------------
// 이번 단계의 핵심 - GENERIC 하도록. 
// => 라이브러리화 하기 위해서 list 관련 함수는 데이타 관련 작업을 하지 말고
//    NODE 관리만 하자

// => 즉, 인자로 data(int)를 받지 말고, NODE 자체를 받아서 관리하자.



//void __insert_node(int data, NODE* prev, NODE* next)
void __insert_node(NODE* node, NODE* prev, NODE* next)
{
	// 이제 이 함수는 데이타는 알필요 없고, NODE 작업만 하게 됩니다.
	node->prev = prev;
	node->next = next;
	prev->next = node;
	next->prev = node;
}

void insert_front(NODE* node)
{
	__insert_node(node, head, head->next);
}

void insert_back(NODE* node)
{
	__insert_node(node, head->prev, head);
}

void show()
{
	NODE* cur = head->next; 

	for (; cur != head; cur = cur->next)
	{
		printf("%d, ", cur->data);
	}
}

int main()
{
	init_node();
	
	for (int i = 0; i < 10; i++)
	{
		// list 사용자가 NODE를 만들어서 데이타를 채우고, list에 넣어야 합니다.
		NODE* node = (NODE*)malloc(sizeof(NODE));
		node->data = i;

		insert_front(node);
	}

	show(); // 9 8 7 6 5 4 3 2 1 0 
}