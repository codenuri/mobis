#include <stdio.h>

// godbolt.org 에서 아래 코드의 어셈블리 코드를 확인해 보세요

// 일반적인 C 함수
// => 아무 일도 하지 않아도, 함수 호출을 위해
//    반드시 필요한 기계어 코드가 생성되게 됩니다.
//    "stack frame" 이라고 합니다.
void f1()
{
}

// __attribute__((naked)) : stack frame 을 만들지 말라
// => 모든 것을 직접 (어셈블리로) 만들겠다는것
// => 디바이스 드라이버나 성능에 민감한 코드 작성시 사용

__attribute__((naked))
void f2()
{
	// 개발자가 stackframe 등을 직접 만들어야 합니다.
}

int main()
{
}