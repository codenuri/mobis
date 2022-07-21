#include <iostream>

class Point { int x, y; };

// 방법 1. call by value
// => 특징 : 복사본이 생성된다.
// void foo(Point p) {}

// 방법 2. call by const lvalue reference
// => 특징 : 복사본은 아니지만 const 속성이 추가된다.
// void foo(const Point& p) {} 


// 방법 3. 복사본 없이, const 속성 추가도 없이 하려면 
//        함수 2개를 제공해야 한다.
// void foo(Point&  p) {}
// void foo(Point&& p) {}


// 방법 4. "방법3" 의 2개의 함수 구현부가 동일하면
// "forwarding reference"를 사용하면 "방법3"의 2개 함수를 자동 생성할수 있다.
template<typename T> void foo(T&& p) 
{
	std::cout << __FUNCSIG__ << std::endl; // 현재 함수 이름 출력
}

int main()
{
	Point pt;

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point());
}
