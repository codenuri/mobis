// 10_복사생성자
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자의 모양에 대해서 정확히 알아봅시다.
	
	// 모양 1. call by value
	// 인자를 받을때 "또 복사 생성자가 호출" 되는 형태 입니다.
	// 복사 생성자가 "무한히 호출" 되는 표기법 입니다.
	// 컴파일 에러.
//	Point(Point p) {} // Point p = p2;


	// 모양 2. call by reference
	// 컴파일이 가능합니다.
	// 그런데, rvalue 를 받을수 없습니다.(함수 반환값 을 받을수 없습니다)
	// Point ret = f() 가 안됩니다.
//	Point(Point& p) {} // Point& p = p2;

	// 모양 3. const lvalue reference
	// const lvalue reference 는 rvalue/lvalue 모두 받을수 있습니다.
	// => 그래서, "복사 생성자"이 정확한 모양이 아래 모양입니다.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point f()
{
	Point pt;
	return pt;
}

int main()
{
	Point p1;		// 1번 생성자 호출
	Point p2(1, 2);	// 2번 생성자 호출

	Point p3(p2);	// 복사 생성자 호출

	Point ret = f(); // Point ret( f() );
}




