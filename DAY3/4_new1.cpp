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

	// 2. 이미 할당된 메모리에 생성자 호출
	new(p2) Point(1, 2); // p2라는 메모리 주소에 있는 객체에 생성자 호출
						 // "placement new" 라고 불리는 기술
//	std::construct_at(p2, 1, 2); // C++20 부터 지원
	

	// 3. 메모리 해지 없이 소멸자만 호출
//	p2->~Point();        // C++98 시절 부터 사용되던 표기법
	std::destroy_at(p2); // C++17 부터는 이 함수를 사용해도 됩니다.


	// 4. 메모리만 해지 ( C 의 free와 유사 )
	operator delete(p2);
}

// malloc : 메모리 할당
// new    : 객체 생성( 메모리 할당 + 생성자 호출 )

// new      Point(1,2) : 새로운 메모리에        객체를 생성해 달라
// new(주소) Point(1,2) : 이미 할당된 메모리(주소)에 객체를 생성해 달라
//												(생성자 호출)	
//						 "placement new", "위치 지정 new" 라고 합니다.