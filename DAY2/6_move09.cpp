#include <iostream>
#include <string>

class People
{
public:
//	char* name;
	std::string name;
	int   age;
public:
	People(const std::string& s, int a) : name(s), age(a)
	{
	}
};

int main()
{
	People p1("kim", 20);
	People p2("kim", 20);
	People p3 = p1;
	People p4 = std::move(p2);

	std::cout << p1.name << std::endl; // "kim", 자원복사 했으므로
	std::cout << p2.name << std::endl; // "",    자원이동 했으므로
}




