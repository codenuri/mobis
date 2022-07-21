#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없습니다.
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};

int main()
{
	// Point 객체를 힙에 한개만 만들어 보세요
	Point* p1 = new Point(1, 2);

	// Point 객체를 힙에 10개 만들어 보세요
//	Point* p2 = new Point[10]; // error.
						// 이 표기법은 "Point"에 디폴트 생성자가 있어야 합니다.

	// C++11 부터는 아래 처럼할수는 있습니다
	// => 그런데, 갯수가 많아지면 ... ???
//	Point* p2 = new Point[10]{ {0,0},{0,0}, {0,0}, {0,0}, {0,0},
//							   {0,0},{0,0}, {0,0}, {0,0}, {0,0} };

	// 이경우, 메모리 할당과 객체 생성을 나누어서 하면 됩니다.
//	Point* p2 = new Point[10]; // "메모리할당 + 생성자 호출" 을 하려고 하므로 에러
	
	// 1. 메모리만 할당
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	
	// 2. 할당된 메모리에 객체 생성(생성자 호출)
	for (int i = 0; i < 10; i++)
	{
//		new(주소)    Point(0, 0);
		new(&p2[i]) Point(0, 0);
	}
	
	// 10개 객체의  소멸자 호출후
	for (int i = 0; i < 10; i++)
		p2[i].~Point();

	// 메모리 제거.
	operator delete(p2);

}