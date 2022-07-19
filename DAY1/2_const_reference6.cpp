#include <iostream>
#include <string>

class People
{
	std::string name;
	std::string addr;
public:
	// 아래 생성자 한개만 만드는 것은 "C++98시절"에는 최선의 코드 입니다.
	// 그런데, 이 생성자는 move를 지원하지 못합니다.
	People(const std::string& name, const std::string& addr)
		: name(name), addr(addr)
	{
	}
	// C++11 이후 최선의 코드가 되려면 위 한개 말고.. 아래 3개가 더있어야 합니다.
	// => "move"를 고려한 setter!!
	People(const std::string& name, std::string&& addr)
		: name(name), addr(std::move(addr)) 
	{
	}
	People(std::string&& name, const std::string& addr)
		: name(std::move(name)), addr(addr)
	{
	}
	People(std::string&& name, std::string&& addr)
		: name(std::move(name)), addr(std::move(addr))
	{
	}

	// 결론 : 인자가 2개인 setter 또는 생성자가 move를 지원하게 하려면
	//       위처럼 4개의 생성자(setter)가 필요 합니다.
	// 인자가 3개 => 8개
	// 인자가 N개 => N^2 개의 필요
	// 다른 해결책이 필요 합니다. => 3일차 나옵니다.(forwarding reference)
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2);
	People p2(s1, std::move(s2));
	People p3(std::move(s1), s2);
	People p4(std::move(s1), std::move(s2));
}