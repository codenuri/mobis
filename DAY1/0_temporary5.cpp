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
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
	std::cout << static_cast<Base>(d).value << std::endl; // 10


//	static_cast<Base>(d).value = 30; // error. 임시객체.value = 30 
//	static_cast<Base&>(d).value = 30; // ok. 
}







