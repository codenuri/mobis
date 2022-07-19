#include <string>

void f1(std::string s) {} // call by value : 좋지 않은 코드

void f2(const std::string& s) {} // 좋은 코드(하지만 최선은 아님, 최선은 내일)

int main()
{
	std::string s1 = "hello";
	f2(s1); // ok.. 당연합니다.

	f2("hello"); // 이건 왜 되나요 ?

}