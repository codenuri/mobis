#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// new가 하는 일
	// 1. 메모리 할당
	// 2. 생성자 호출
//	Point* p1 = new Point(1, 2);

	// 1. 소멸자 호출
	// 2. 메모리 해지 
//	delete p1;

	// 1. 메모리만 할당하기 ( C의 malloc 과 유사 )
	// => void* 반환이므로 캐스팅 필요
	Point* p2 = static_cast<Point*>( operator new( sizeof(Point) ) );


	// 4. 메모리만 해지 ( C 의 free와 유사 )
	operator delete(p2);

}