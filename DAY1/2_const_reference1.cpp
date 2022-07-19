// F16 ~ F20  ( 10 page ~)

#include <iostream>
#include <string>

struct Rect
{
	int left, top, right, bottom;
};

// call by value 의 단점
// 1. 복사본를 만들게 되므로 메모리 사용량 증가
// 2. 복사 생성자 호출
// 3. 소멸자 호출.
void f1(Rect rc) {}

// 아래 같은 코드의 경우에..
// string의 복사 생성자에서 문자열 자체를 깊은 복사합니다.
// 복사생성자에 의한 오버헤드가 큽니다.
// 그래서 const reference 를 사용해야 합니다.
void f2(std::string s) {}


// 결국, call by value 보다 call by reference가 좋습니다.

void f3(Rect& rc) {}	// 전달된 객체를 R/W 하겠다는 의도
						// => 임시객체를 전달할수 없다.

void f4(const Rect& rc) {}	// 전달된 객체를 R 만 하겠다는 의도
							// => 임시객체 전달 가능.


int main()
{
	Rect rc;
	f1(rc);

	std::string s = "sldkfjsldjfsldjfldfsd";
	f2(s); // 이순간을 생각해보세요
}
