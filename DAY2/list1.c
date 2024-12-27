#include <stdio.h>

// C++ : 표준라이브러리(STL) 이 있어서 list, vector 를 제공
// C   : linked list 가 필요하면 직접 만들어서 사용해야 합니다.

// linux 커널에서 사용하는 list 를 직접 만들어 봅시다.
// (윈도우 OS 내부에서도 동일한 기술로 사용, 즉, 유명한 기술!!)
// => 재사용가능하게 잘 만들어진 코드. 
//-------------------------------------------------
// 더블리스트 입니다.

// #1. NODE 구조체 모양 알아 두세요
// #2. 더미 노드가 있으면 편리 합니다. 
//     => 실제 데이타를 저장하지 않지만 코드를 단순화 하고, 안전하게 하기 위해
//     => 일반적인 list 는 list 가 비었을때 와 비어 있지 않을때의 경우를 고려해서 코드 작성
//        
//     => 더미 노드가 있으면 구별할 필요 없습니다.

// #3. 원형(circular) 구조.. 

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

//	head->next = 0;
//	head->prev = 0; // 원형 구조 아닙니다.

	head->next = head;
	head->prev = head; // 원형 구조입니다.
}

int main()
{
	init_node();
}