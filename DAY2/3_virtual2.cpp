#include <iostream>

// C35. 기반 클래스 소멸자는 virtual 이거나 protected 이어야 한다.

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; } 
};

int main()
{
	// 1. 아래 코드 문제 없습니다.
//	Derived d;

	// 2. 아래 코드도 문제 없습니다.
//	Derived* p = new Derived;	// 1. 메모리 할당
								// 2. 생성자 호출.
//	delete p;	// 1. 소멸자 호출
				// 2. 메모리 해지

	// 3. 아래 코드가 문제 입니다.
	Base* p = new Derived;	// Derived 생성자 호출

	delete p;	// 1. 소멸자 호출
				//	  => 컴파일러는 p가 Base* 라는 것만 알고 있다.
				//	  => 그래서, "Base 클래스를 조사해서" 소멸자가 가상인지 확인
				//	  A. 소멸자가 가상함수가 아니면 "~Base()" 만 호출
				//    B. 소멸자가 가상함수라면 p가 가리키는 곳을 조사후 호출
				// 
				// 2. 메모리 해지


}