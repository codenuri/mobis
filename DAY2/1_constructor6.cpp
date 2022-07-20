#include <iostream>

// C50_ Use a factory function if you need “virtual behavior”
// during initialization

struct Base
{
	Base() { }

	void foo()	// void foo( Base* this )  핵심. this가 "Base*" 타입이라는점
	{
		init();	// this->init() 인데,  
				// this 가 Base* 타입이고 init이 가상함수가 아니므로
				// Base::init 호출	
				
				// init()이 가상함수라면 포인터 타입이 아닌 객체 조사후 호출하므로
				// Derived::init 호출
	};
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
	Derived d;
	d.foo();   // foo(&d) 처럼 호출되는 원리 입니다.
}

