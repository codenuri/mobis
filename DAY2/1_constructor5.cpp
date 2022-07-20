#include <iostream>

class Point
{
	int x, y;
public:
//	Point() : x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};
// 핵심 : Point 에 디폴트 생성자가 없다는 점
// Point p1;		// error
// Point p2(0,0);	// ok

class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	// 사용자 코드	// 컴파일러가 변경한 코드
//	Rect()			// Rect() : ptFrom(), ptTo()  <= 핵심, 항상 디폴트 생성자 호출하는 코드 생성

	// 핵심 1. 디폴트 생성자가 없는 타입이 멤버 데이타로 있는 경우
	//		  사용자가 명시적으로 생성자를 호출하면 됩니다.
	Rect() : ptFrom(0, 0), ptTo(0, 0)
	{
		std::cout << "Rect()" << std::endl;
	}
};
class Rect2
{
	// 핵심 2. C++11 부터는 아래 처럼 해도 됩니다.
	// => 그런데, 이코드는 결국 위와 완전히 동일합니다.
	// => 필드 초기화에 있는 초기값을 가지고, 컴파일러가 생성자 초기화 리스트
	//    로 옮겨 놓은것(위와 동일)
	Point ptFrom{ 0, 0 };
	Point ptTo{ 0, 0 };
//	Point ptTo(0, 0); // error. 이 위치는 {}만 가능합니다.
public:
	Rect() 
	{
	}
};




int main()
{
	Rect r;
}




