// const member function
// Con.1 : By default, make objects immutable
// Con.2 : By default, make member functions const  <== 이번 소스 핵심
// Con.3 : By default, pass pointers and references to consts

#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// void print() : 컴파일러는 print 내부적으로 x, y의 값을 변경할수도 있다고
	//				  생각하게 됩니다.
	//				  그래서 상수객체는 이 멤버 함수를 호출할수 없습니다.
	//				  핵심 : 컴파일러는 함수 선언으로만 판단하게 됩니다.

	// void print() const : 이 함수 안에서는 멤버 변수를 변경하지 않겠다는 약속

	void print() const 
	{
//		x = 10; // error. "상수 멤버 함수" 에서는 멤버 데이타를 변경할수 없습니다.

		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2);

	// pt가 상수 일때 아래 3줄을 생각해 봅시다.	
//	pt.x = 10;		// error. x는 public 이지만 상수 이므로
//	pt.set(10, 20);	// error.
	
	pt.print();		// error. 
					// "상수 멤버 함수"로 했다면 에러 아님.
}
// 핵심 : "상수 객체" 는 상수 멤버 함수만 호출가능합니다.
//      멤버 데이타를 수정하지 않은 모든 멤버 함수는 "반드시" 상수멤버함수로 해야 합니다.

