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

int main()
{
	Rect r;
}




