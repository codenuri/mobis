#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	// 핵심 : 2번째 인자는 포인터.. emplace_back 사용시 주의
	Point(int a, int* b) { std::cout << "Point()" << std::endl; }

	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};

int main()
{
	std::vector<Point> v;

	// 아래 코드가 실행되면 소멸자가 몇번 호출될까요 ?
	// vector에 요소 넣기. 
	// 방법 1. 이름 있는 객체를 만들어서 넣기
//	Point pt(0, 0);
//	v.push_back(pt);

	// 방법 2. 임시객체 형태로 넣기
	// => 위와 차이점은, 임시객체이므로 아래 문장끝에서 즉시 파괴
//	v.push_back( Point(0, 0) );

	// 방법 3. 객체를 만들어서 전달하지 말고
	//		  객체를 만들기 위한 생성자 인자를 전달합니다.
	//v.emplace_back(0, 0); // error
			// emplace_back 이 내부적으로 new Point(0,0) 으로 생성

	v.emplace_back(0, nullptr ); // ok.. 


	// 핵심 1. STL 컨테이너가 사용자 정의 타입을 보관한다면
	//		push_back 보다 emplace_back 이 좋습니다.

	// 2. emplace 사용시, 생성자 인자가 포인터 였다면
	//    0을 전달하면 에러 입니다. 반드시 nullptr 을 사용해야 합니다.

	std::cout << "-----" << std::endl;
}




