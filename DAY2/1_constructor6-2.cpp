#include <iostream>

// C50_ Use a factory function if you need “virtual behavior”
// during initialization

struct Base
{
//	Base() { init(); }	// 핵심 1. 여기서 init 은 가상함수로 동작안합니다.	
	Base() { }

	// 객체의 생성 과정에서 가상함수를 호출하고 싶다면
	// 팩토리 함수를 사용해라!!
	template<typename T>
	static T* Create()
	{
		T* p = new T; // 객체를 생성하고
		p->init();    // 가상함수를 호출하고
		return p;     // 객체 주소를 반환 합니다.
	}

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1
};
struct Derived : public Base
{
	int x;

	Derived() : x(10) {}	

	void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
};
int main()
{
//	Derived d;

	Derived* p = Base::Create<Derived>(); 
}

