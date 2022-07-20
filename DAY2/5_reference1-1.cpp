#include <iostream>

struct Point
{
	int x;
	int y;
};

void foo(Point& pt)       { std::cout << "Point&" << std::endl; }
void foo(const Point& pt) { std::cout << "const Point&" << std::endl; }
void foo(Point&& pt)      { std::cout << "Point&&" << std::endl; }

int main()
{
	Point pt;

	foo(pt);

	foo(Point());

}