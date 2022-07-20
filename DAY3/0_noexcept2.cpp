#include <iostream>
#include <string>

class People
{
public:
	std::string name;
	int   age;
public:
	People(const std::string& s, int a)	: name(s), age(a), address(addr)
	{
	}

	People(const People& p) : name(p.name), age(p.age)
	{
		std::cout << "copy" << std::endl;
	}

	People(People&& p) : name(std::move(p.name)), age(p.age) 
	{
		std::cout << "move" << std::endl;
	} 
};

int main()
{
	People p1("kim", 20);
	People p2 = std::move_if_noexcept(p1); // STL 의 대부분의 컨테이너가
											// 이렇게 구현
}





