#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	
	// 아무일도 하지 않은 디폴트 생성자가 필요하면..
//	Point() {}			// 이렇게 하지 말고..
	Point() = default;	// 이렇게 하세요.. 이코드가 좋은 코드입니다.
};

int main()
{
	Point p1;
	Point p2(1, 2); // ok
}