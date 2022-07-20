#include <iostream>

class Point
{	
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	
	Point() {}			
//	Point() = default;	
};
int main()
{
	int n1 = 0; // 0으로 초기화
	int n2;	    // 쓰레기값
	int n3{};	// 디폴트값(0)으로 초기화
				// "value initialization" 이라는 기술입니다

	Point p1;	// 모든 멤버가 쓰레기값(생성자에 초기화 코드가 없다면) 
	Point p2{};	// 모든 멤버가 0으로 초기화

	std::cout << p2.x << std::endl;
}