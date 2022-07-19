#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
	int x;
	int y;

	// 객체의 상태를 문자열로 표현할때 성능향상을 위해 "캐쉬"개념도입
	// mutable : 상수 멤버 함수 안에서는 수정할수 있게 해달라는 키워드
	//		     toString()은 논리적으로 상수 멤버함수가 되는게 맞지만
	//			 테크닉상, 아래 변수를 수정할수 있어야 한다.
	mutable char cache[32]; 
	mutable bool cache_valid = false;

public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 객체의 상태를 문자열로 반환하는 함수(java, C# 등에 있는 개념)
	// => "상수 멤버 함수로 할까요 ? 하지 말까요 ?" => 이런 판단이 중요합니다.
	// => const Point p(1,2) 라도 p.toString()이 가능해야 합니다.
	const char* toString() const 
	{
	//	static char s[32];
	//	sprintf(s, "%d, %d", x, y);
	//	return s;

		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}
};
int main()
{
	Point pt(1, 2);

	std::cout << pt.toString() << std::endl; // "1, 2"
	std::cout << pt.toString() << std::endl;
}

