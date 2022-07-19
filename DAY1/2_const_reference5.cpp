#include <iostream>
#include <string>

class People
{
	std::string name;
public:
	// 아래 코드는 "const reference" 를 사용하는 좋은 코드 입니다.
	// C++98 시절에는 "100점" 짜리 코드 입니다.
	// 그런데, C++11 이후에는 많이 부족한 코드 입니다.
	void setName(const std::string& s)
	{
		name = s;
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName( s1);				// s1의 자원을 복사해라
	p.setName( std::move(s2) );	// s2의 자원을 이동해라(뺏아가라는것)

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}

