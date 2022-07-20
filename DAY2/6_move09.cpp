#include <iostream>
#include <string>

// rule of 0
// => char*, int* 등을 사용하지 말고, 자원을 자동으로 관리하는 타입을 사용 하자
// => char* => string, int* => vector 또는 스마트 포인터

// => 이경우, 복사 생성자, 소멸자, 대입연산자 등을 만들필요 없다.
// => 아무것도 만들지 않으면 컴파일러가 모두 제공한다.

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




