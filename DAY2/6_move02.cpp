#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 174page
/*
template<typename T>
void Swap(T& a, T& b)
{
	// 아래 코드는 문자열 복사가 3회 발생합니다.
	// 느립니다.
	T tmp = a;
	a = b;
	b = tmp;
}
*/
template<typename T>
void Swap(T& a, T& b)
{
	// 아래코드는 자원의 이동( 포인터 자체 복사)
	// 으로 만든 Swap 입니다.
	// 빠릅니다.
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}
// move 관련 알아야 하는 2가지
// 1. Swap 같은 알고리즘 작성시 적절히 std::move()를 사용하면 빨라집니다.
//    내가 작성하는 알고리즘에서 "a=b" 할지 "a=std::move(b)" 할지 잘 판단하세요

// 2. 개발자가 People 같은 클래스를 만들때
//    People 클래스가 move 를 지원하려면 어떻게 해야 할까 ?
People p1("kim", 20);
People p2 = std::move(p1); // 이코드가 되려면 어떻게 해야 할까 ?




