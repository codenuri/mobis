#include <stdio.h>
#include <stdlib.h>

// 이번 단계의 핵심!!!
// => NODE 안에 데이타를 보관하지 말고!!!!
// => 데이타 안에 NODE 를 보관하자. - 이 기술의 핵심 부분!!!

// 아래 NODE 는 이제 데이타는 없습니다.
// => GENERIC 화 되려면 데이타의 종류에 상관없이 설계되야 하므로
//    데이타 자체를 제거. 
typedef struct _node
{
//	int data;
	struct _node* prev;
	struct _node* next;
} NODE;


//NODE* head = 0;  이렇게 전역변수로 관리하면 한개의 list 만사용!!!
//					head 도 함수 인자화 되어야 합니다.
//					그래야, 여러개 list 가능

// 더미노드도 사용자가 만들게 합니다.
void init_node(NODE* head)
{
	head->next = head;
	head->prev = head;
}

//--------------------------------------------------------
void __insert_node(NODE* node, NODE* prev, NODE* next)
{
	node->prev = prev;
	node->next = next;
	prev->next = node;
	next->prev = node;
}

void insert_front(NODE* node, NODE* head)
{
	__insert_node(node, head, head->next);
}

void insert_back(NODE* node, NODE* head)
{
	__insert_node(node, head->prev, head);
}

/*
void show()
{
	NODE* cur = head->next;

	for (; cur != head; cur = cur->next)
	{
		printf("%d, ", cur->data);
	}
}
*/

int main()
{
	// 이제 더미 노드도 만들어서 전달합니다.
	NODE* head = (NODE*)malloc(sizeof(NODE));

	init_node(head);

	for (int i = 0; i < 10; i++)
	{
		NODE* node = (NODE*)malloc(sizeof(NODE));

		insert_front(node, head);
	}

}

// 완성 
// => 핵심 list 관련 3개의 함수는 데이타는 모릅니다. 동적할당도 없습니다.
// => 단지, 인자로 받은 NODE 를 연결만 해줍니다.
// 어떻게 활용하는지는 다음소스