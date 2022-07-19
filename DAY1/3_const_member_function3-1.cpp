// 3_const_member_function3-1
#include <iostream>

class Test
{
public:
	// 동일 이름의 "상수멤버함수" 와 "비상수멤버함수"를 동시에 만들수 있습니다.
	void foo()       { std::cout << "foo()" << std::endl; }		  // 1
	void foo() const { std::cout << "foo() const" << std::endl; } // 2
};

int main()
{
	Test t;		// 상수가 아닌 일반 객체는 1, 2 모두 호출가능한데..
	t.foo();	// 1번 호출, 
				// 1번이 없으면 2번 호출

	const Test ct;	// 상수 객체는 "상수 멤버 함수"만 호출가능 합니다.
	ct.foo();		// 2번 호출. 
					// 2번이 없으면 에러 입니다.
}