#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }

	void set(int a, int b) { x = a; y = b; }
};
// 핵심 : temporary 의 특징 정리

int main()
{
	Point pt(1, 2);
	
	// 핵심 1. temporary 는 등호의 왼쪽에 올수 없다.(rvalue 이다.)
	pt.x = 10;			// ok. 	
//	Point(1, 2).x = 10;	// error. temporary 는 등호의 왼쪽에 올수없다.
						// temporary 는 lvalue 가 될수 없다.
						// temporary 는 rvalue 입니다.

	Point(1, 2).set(10, 20); // ok.. 함수 호출로 상태 변경은 가능
							 // 즉, temporary가 상수는 아닙니다.

	// 핵심 2. temporary 는 주소연산자로 주소를 구할수 없다.
	// => 단, 생성자에서 "this" 를 확인해 보면 주소를 알수는 있습니다.
	Point* p1 = &pt;			// ok	 
	Point* p2 = &Point(1, 2);	// error. 
								// Visual studio 일부버전(2017)은 에러가
								// 나지 않을수 있습니다.
								// => VC 가 C++문법을 확장한것. 
						
	// 핵심 3. temporary 는 lvalue reference 로 가리킬수 없다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error

	

	// 핵심 4. temporary 는 const lvalue reference 로 가리킬수 있다
	const Point& r3 = Point(1, 2); // ok.. 
						// => 이 경우 temporary 의 수명은 r3의 수명과
						//    동일합니다.
						// => 이름 없는 객체에 이름을 부여한것

	// 핵심 5. C++11을 만들때 "temporary" 를 상수성 없이 가리키고 
	//    싶었습니다
	// 그래서 "rvalue reference" 문법을 만들었습니다
	Point&& r4 = Point(1, 2); // ok.. const 없이 temporary 가르킴
	Point&& r5 = pt;          // error. 이름있는 객체(lvalue)를 가리킬수없다.

}







