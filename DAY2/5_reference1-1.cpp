#include <iostream>

struct Point
{
	int x;
	int y;
};

void foo(Point& pt)       { std::cout<< "Point&" << std::endl; }	  //1
void foo(const Point& pt) { std::cout<< "const Point&" << std::endl; }//2
void foo(Point&& pt)      { std::cout<< "Point&&" << std::endl; }	  //3

int main()
{
	Point pt;

	foo(pt);	// 1, 2 번이 모두 가능하지만, 우선순위가 정해져 있습니다.
				// 1번 호출, 1번이 없으면 2번 호출

	foo(Point());// 2, 3 번이 모두 가능하지만, 우선순위가 정해져 있습니다.
				 // 3번 호출, 3번이 없으면 2번 호출

}