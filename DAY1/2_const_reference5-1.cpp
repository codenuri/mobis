#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// setter 가 move 를 지원하게 하려면 2개를 만들어야 합니다.
	// lvalue : 이름있는 객체, rvalue : 이름없는 객체(temporary)
	// 
	// const std::string& : lvalue 와 rvalue 를 모두 받을수 있습니다.
	// std::string&&      : rvalue 만 받을수 있습니다.

	void setName(const std::string& s) { name = s;}  // 1
	void setName(std::string&& s)      { name = std::move(s); } // 2
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);				// s1은 lvalue 이므로 1번 호출

	p.setName(std::move(s2));	// std::move(s2)는 s2를 rvalue로 캐스팅하는것
								// 1, 2 번으로 모두 전달 가능합니다.
								// 그런데, 우선 순위로 2번이 선택됩니다.
								// 2번이 없으면 1번 사용

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; // ""
}

