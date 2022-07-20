// move 개념 - 171 page~
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";
	std::string s3 = s1;	// 자원의 복사	
	std::string s4 = std::move(s2); // 자원의 이동

	std::cout << s1 << std::endl; // "hello"
	std::cout << s2 << std::endl; // ""

}

