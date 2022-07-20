#include <string>

void f1(std::string s) {} // call by value : 좋지 않은 코드

void f2(const std::string& s) {} // 좋은 코드(하지만 최선은 아님, 최선은 내일)

int main()
{
	std::string s1 = "hello";

	f2(s1); // ok.. 당연합니다.



	f2("hello"); // 이건 왜 되나요 ?
				// 1. std::string("hello") 즉. 임시객체를 만드는 표기법으로
				//	  string 타입의 임시객체 생성
				// 2. 임시객체를 f2 로 전달
				// 단, string 생성자가 explicit 가 아닐때만 가능.
}