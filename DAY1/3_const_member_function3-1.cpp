// 3_const_member_function3-1
#include <iostream>

class Test
{
public:
	// 동일 이름의 "상수멤버함수" 와 "비상수멤버함수"를 동시에 만들수 있습니다.
	void foo()       { std::cout << "foo()" << std::endl; }
	void foo() const { std::cout << "foo() const" << std::endl; }
};

int main()
{
	Test t;
	t.foo();

	const Test ct;
	ct.foo();
}