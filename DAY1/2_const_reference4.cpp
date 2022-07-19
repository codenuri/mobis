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
}