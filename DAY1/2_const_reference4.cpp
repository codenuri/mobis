#include <iostream>
#include <string>

int main()
{
	std::string s1 = "abcdefghijklmnopqrstu";
	std::string s2 = "abcdefghijklmnopqrstu";

	std::string s3 = s1;			// 복사 생성자 : 자원(문자열)의 (깊은)복사
	std::string s4 = std::move(s2); // move 생성자 : 자원의 이동

	std::cout << s1 << std::endl; // "abcdefghijklmnopqrstu"
	std::cout << s2 << std::endl; // ""


	const std::string s5 = "abcdefghijklmnopqrstu";
	
	std::string s6 = std::move(s5); // 핵심!!
					// => 이코드는 move 생성자가 아닌 복사 생성자를 호출합니다
					// => 즉, 자원의 이동이 아닌 자원의 복사 입니다.

	// 핵심 : 상수객체는 move 될수 없습니다.
}