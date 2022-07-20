#include <iostream>

// C150. 가상함수에서는 절대 디폴트 인자를 변경하지 말라(사용하지 않으면 더 좋다.)

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};

class Derived : public Base
{
public:
	virtual void foo(int a = 20) { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;

//	if (사용자입력 == 1) p = new Base;

	// 위 코드처럼 p가 가리키는 것은 실행시간에 변경 가능합니다.
	// 그래서, 컴파일러는, 컴파일시에는 p 가 가리키는 객체를 알수 없습니다.
	// 
	p->foo(); // 화면 출력 결과 예측해 보세요..("Derived : 10")
	
	// "p->foo()" 했을때
	// 1. 컴파일러는 p의 타입이 Base* 라는 것만 알고 있습니다.
	// 2. 따라서, Base 클래스에서 "foo" 가 가상인지 아닌지를 조사합니다.
	
	// A. 가상이 아니면 "무조건 Base foo" 호출
	// 
	// B. 가상함수 라면
	//    p->실행시간에 p가 가리키는 곳을 조사후에 결과에 따른 foo( 10 );

	// 핵심
	// 가상함수 : 실행시간에 동작하는 문법
	// 디폴트 파라미터 : 컴파일 시간에 채우는 문법.

}