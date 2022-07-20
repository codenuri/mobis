#include <iostream>
#include <string>
#include <string_view>  

// 함수가 "읽기 전용 문자열"을 받는 다면
// std::string 보다 std::string_view가 좋습니다.

//void f1(std::string s1)      {}  // 나쁜 코드
void f1(const std::string& s1) {}  // 나쁘지 않지만 아래가 더 좋습니다.
void f2(std::string_view s2)   {}  // 좋은 코드

int main()
{
//	std::string s = "sfjsdjflsdjflsjlfks";
//	f1(s);
//	f2(s);

	// 아래 코드가 f1, f2 함수의 결정적인 차이점입니다.
	// 잘 생각해 보세요
	f1("abcdefghijklmnopqrstu");
	f2("abcdefghijklmnopqrstu");
}