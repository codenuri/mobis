#include <iostream>

// C50_ Use a factory function if you need “virtual behavior”
// during initialization

// 핵심 : 생성자에서는 "가상함수"가 동작하지 않습니다.
// => 왜 이렇게 동작하도록 언어를 설계했는지 이유를 생각해 봅시다.
// => 만약 아래 코드에서 "A" 부분에서 "Derived::init" 가 호출된다면
//    초기화 되지 않은 멤버 x 를 사용하게 됩니다.
//    그래서 C++은 생성자에서는 가상함수가 동작하지 않는다.. 라는 문법을 만들었습니다.
struct Base
{
	Base() { init(); }		// "A"    "Base::init"

	void foo() { init(); }; // "Derived init()" 호출
	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1
};
struct Derived : public Base
{
	int x;

	// 사용자가 만든 코드		// 컴파일러가 변경한 코드
	Derived() : x(10) {}	// Derived() : Base() , x(10) {}

	void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
};
int main()
{
	Derived d;
//	d.foo();   
}

