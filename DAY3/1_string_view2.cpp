#include <iostream>
#include <string>
#include <string_view>  

void* operator new(std::size_t sz)
{
	printf("%d bytes alloc\n", sz);
	return malloc(sz);
}


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
	// 아래 처럼 "abcdefghijklmnopqrstu" 라는 문자열 리터럴을 사용하면
	// => "상수 메모리에 문자열이 놓이게 됩니다"
	f1("abcdefghijklmnopqrstu");	// 이 문자열을 가지고
									// string 의 임시객체를 생성해서
									// 전달 하므로 "오버헤드가 있습니다"

//	f2("abcdefghijklmnopqrstu");
}