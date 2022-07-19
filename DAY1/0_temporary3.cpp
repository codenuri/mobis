#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

//void foo(Point& pt) {}	// 이렇게 하면 temporary를 받을수 없습니다
void foo(const Point& pt) {}	// 이렇게 해야 temporary를 받을수
								// 있습니다.

// 그래서, C++에서 함수 인자를 받을때 "const lvalue reference" 로
// 하는 것이 좋습니다.

int main()
{
//	Point pt(1, 2); // 이 pt 를 함수 인자로만 사용한다면
//	foo(pt);		// 이 다음줄 부터는 pt가 필요 없습니다
					// => 그런데, pt는 블럭을 벗어날때 까지파괴 안됩니다.

	// 핵심 : 함수의 인자로만 사용되는 객체가 필요 하면
	//       temporary 형태로 전달하는 것이 좋습니다.
	foo( Point(1, 2) );	


	std::cout << "-----" << std::endl;
}





