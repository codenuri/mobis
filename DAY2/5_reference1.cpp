struct Point
{
	int x;
	int y;
};

int main()
{
	Point pt;

	// 핵심 1. lvalue, rvalue 용어
	pt.x = 10; // ok.  named object pt 는 등호의 왼쪽에 올수 있습니다.
	           // => lvalue 입니다.

	Point().x = 10; // error. unnamed object(temporary)는 등호의 왼쪽에 올수 없습니다.
					// temporary 는 "rvalue" 입니다.


	// 핵심 2. 아래 규칙 3개 정확히 외우세요
	// 규칙 1. lvalue reference 는 lvalue 만 가리킬수 있다
	Point& r1 = pt;			// ok
	Point& r2 = Point();	// error


	// 규칙 2. const lvalue reference 는 lvalue, rvalue를 모두 가리킬수 있다
	const Point& r3 = pt;		// ok
	const Point& r4 = Point();	// ok

//	r4.x = 10;	// error. 즉, r4는 임시객체를 가리킬수 있지만
				// 변경할수 없습니다.
				// C++11 만들때, 임시객체를 변경하고 싶었습니다.

	// 규칙 3. C++11 만들때 임시객체를 "상수성 없이" 가리키고 싶었습니다.
	// 그래서, C++11 에서 새로운 reference 등장
	// "rvalue reference 는 rvalue 만 가리킬수 있다"
	Point&& r5 = pt;		// error
	Point&& r6 = Point();	// ok

}