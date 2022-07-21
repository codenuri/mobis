// F50(25page) ~ F54 - 람다 표현식 사용한 관한 코딩 관례
#include <iostream>

struct plus
{
	int operator()(int a, int b) 
	{
		return a + b;
	}
};

int main()
{
	plus p; // plus 라는 구조체의 "객체 p" 입니다.
			// => p는 함수가 아닌 객체 입니다.

	int n = p(1, 2); // 객체 p를 함수 처럼 사용합니다.
					 // => "함수 객체" 라고 합니다.
					 // => p.operator()(1,2) 를 찾게 됩니다.

	int n2 = p.operator()(1, 2); // ok
}
// 핵심 : () 연산자를 재정의하면 함수 처럼 사용가능 합니다

