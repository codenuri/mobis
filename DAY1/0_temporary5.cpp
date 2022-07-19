#include <iostream>

struct Base
{
	int value = 10; 

	Base() {  }
	Base(const Base& other) : value(other.value)
	{
		std::cout << "Base copy ctor" << std::endl;
	}
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl; // 20

	// 기반 클래스의 value 에 접근 하려면 아래처럼 캐스팅하면 됩니다.
	// => 그런데, 아래 2줄의 차이점을 생각해 보세요.. 
//	std::cout << static_cast<Base&>(d).value << std::endl; // 10
	std::cout << static_cast<Base>(d).value << std::endl; // 10


//	static_cast<Base>(d).value = 30; // error. 임시객체.value = 30 
//	static_cast<Base&>(d).value = 30; // ok. 
}

// 결론 : 임시객체(temporary)는

// 1. 개발자가 의도적으로 만들기도 하고
//    => 함수 인자로 전달하는 경우
//    => foo( Point(1,2))

// 2. 개발자의 코드에 따라 생성되기도 합니다.
//   => 값을 반환하는 함수
//   => 값으로 캐스팅. 





