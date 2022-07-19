#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
/*
void f1(Point  pt) {} // call by value     : 복사본 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨.

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/




//-----------------------------------
// 핵심 : "값 리턴" 과 "참조 리턴" 의 차이점을 완벽히 이해 해야 합니다. 
Point pt(1, 2);

Point f1() // return by value
{
	return pt;	// 이순간 pt가 반환되는것이 아니라
				// pt를 복사한 "리턴용 temporary"가 반환 됩니다.
}
Point& f2() // return by reference
{
	return pt; // pt 자체를 반환 해달라는 의도
				// temporary 가 생성되지 않습니다
}
int main()
{
	f1().x = 10; // error. 리턴용temporary.x = 10 이 됩니다.
	f2().x = 10; // ok..   pt.x = 10 이 됩니다.
}

Point& f3()
{
	Point p(1, 2);	// 지역 변수 입니다.
					// 함수 종료시 파괴 됩니다.

	return p;		// 버그.. 절대 지역변수는 참조 반환하면 안됩니다.
					// 컴파일 에러는 아닌데(경고 발생)
					// 절대 사용하면 안됩니다.
					// 값 반환만 가능합니다.
					
}
// 결론 
// 1. 지역변수를 반환 한다면 "값 반환" 해야 합니다. <== 대부분의 경우
// 
// 2. 전역변수나 멤버 변수, "*this" 등 함수 호출이 종료되어도 
//    파괴되지 않은 것들만 "참조 반환" 하세요.

