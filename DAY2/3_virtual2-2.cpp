#include <iostream>

// C35. 기반 클래스 소멸자는 virtual 이거나 protected 이어야 한다.

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }

	// Base 안에 다른 가상함수가 여러개 있다면(이미 가상함수 테이블이 생겼으므로)
	// 소멸자도 그냥 아래처럼 가상함수로 하세요.(항목 하나 늘어나는 것은 큰문제 아닙니다.)
//	virtual ~Base() { std::cout << "~Base()" << std::endl; }

	// 그런데, 이 클래스가 아주 간단한 클래스이고
	// 가상 소멸자의 오버헤드가 싫으면, protected 소멸자를 사용하세요
protected:
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() 
	{
		std::cout << "~Derived()" << std::endl; 

		// ~Base() // 컴파일러가 추가한 코드
	}
};

int main()
{
	Base* p = new Derived;

	// Base 소멸자가 protected 라면 아래 코드는 에러 입니다.
//	delete p;	// error
				// 소멸자를 호출해야 하는데 protected 멤버를 외부에서 
				// 호출할수 없다.

	// 결국 의도는 "Base*" 인채로는 delete 하지 말고
	// Derived* 로 캐스팅해서 delete 하라는 의도
	delete static_cast<Derived*>(p);

}