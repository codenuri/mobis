#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// setter 나 생성자만 move를 지원하면 됩니다.
	void setName(const std::string& s) { name = s; }  // 1
	void setName(std::string&& s) { name = std::move(s); } // 2

	// 단순히 읽기만 하는 인자는 move지원 필요 없습니다.
	// 아래 함수는 한개만 만들면 됩니다.
	void print(const std::string& s) 
	{
		std::cout << s << std::endl; 
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);			

	p.setName(std::move(s2));
							

}

