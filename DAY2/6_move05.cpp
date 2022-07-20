#include <cstring>
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	// 복사 생성자
	// lvalue/rvalue 모두 받을수 있다.
	Cat(const Cat& c) : age(c.age)
	{
		std::cout << "복사 생성자" << std::endl;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	// 임시객체를 위한 복사 생성자 - "move 생성자" 라고 합니다.
	// => 임시객체는 rvalue 이다.
	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		std::cout << "move 생성자" << std::endl;

		// 임시객체가 사용하던 포인터는 reset
		// => 이 코드가 되려면 임시객체를 상수성없이
		//    가리킬수 있어야 합니다.
		c.name = nullptr;
	}

};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; // 복사 생성자

	Cat c3 = foo(); // 이 한줄에 대한 메모리를 잘 생각해 보세요
					// => move 의 핵심 입니다.
					// Cat c3 = 리턴용임시객체;
					// move 생성자
}