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

	Cat(const Cat& c) : age(c.age)
	{
		std::cout << "복사 생성자" << std::endl;

		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		std::cout << "move 생성자" << std::endl;
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

	Cat c2 = c1;	// 복사 생성자, c1는 lvalue
	Cat c3 = foo(); // move 생성자

	Cat c4 = static_cast<Cat&&>(c1); // move 생성자 호출
	Cat c5 = std::move(c2);	// 이 함수가 결국 위처럼 캐스팅하고 있습니다.

	// 주의.  std::move() 함수가 자원을 이동하는 일을 하는것이 아닙니다.

	// 1. std::move(c2) 는 c2를 Cat&& 로 캐스팅만 합니다.
	
	// 2. 캐스팅의 결과로, 복사 생성자가 아닌 move 생성자가 호출됩니다.

	// 3. 따라서 자원을 이동하는 것은 Cat 클래스를 만든 사람이
	//    move 생성자를 제공했기 때문에 되는 것입니다.

}