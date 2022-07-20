#include <iostream>

class Point
{	
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	
//	Point() {}		// 이 코드는 생성자의 구현을 사용자가 제공한것 입니다.
					// => 컴파일러는 생성자에서 어떤일을 하고 있다고 생각합니다.
					// => 컴파일러는 함수의 선언만 보고 생각하기 때문에

	Point() = default;	// 컴파일러가 생성자의 구현을 제공
						// => "Point()= default" 표기는 선언부에 작성
						// => 그럼, 컴파일러는 생성자가 아무 일도 하지 않는다는것을
						//    알고 있음. 
						// (또는 상황에 따라 어떤일을 하는지도 알고 있음)
};
int main()
{
	int n1 = 0; // 0으로 초기화
	int n2;	    // 쓰레기값
	int n3{};	// 디폴트값(0)으로 초기화
				// "value initialization" 이라는 기술입니다

	Point p1;	// 모든 멤버가 쓰레기값(생성자에 초기화 코드가 없다면) 
	Point p2{};	// 모든 멤버가 0으로 초기화
				// 1. 사용자가 생성자를 만든경우 - 무조건 사용자 생성자 호출
				// 2. = default 로 한경우 - 모든 멤버를 0으로 초기화
				

	std::cout << p2.x << std::endl;
}