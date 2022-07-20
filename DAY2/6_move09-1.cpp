#include <iostream>
#include <string>

class People
{
public:
	std::string name;
	int   age;
public:
	People(const std::string& s, int a) : name(s), age(a)
	{
	}

	// "logging" 등을 하기 위한 이유로 소멸자를 만들었습니다.
	// => 복사 생성자는 컴파일러가 지원하는데
	// => move 생성자는 지원 안합니다.
	~People() {}

	// 이런 경우를 대비해서 모든 함수를 "=default" 로 요청하면 편리합니다.
	People(const People&) = default;
	People(People&&) = default;

	People& operator=(const People&) = default;
	People& operator=(People&&) = default;
	
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




