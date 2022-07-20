#include <iostream>
#include <string>

void f1() noexcept {}

class People
{
public:
	std::string name;
	int   age;
public:
	People(const std::string& s, int a)	: name(s), age(a)
	{
	}

	People(const People& p) : name(p.name), age(p.age)
	{
		std::cout << "copy" << std::endl;
	}
	
	// 핵심 1. move 생성자, move 대입 연산자를 만들때는 되도록 noexcept 붙이세요
	// 2. 단, move 생성자 안에 있는 모든 코드가 예외 없음을 보장해야 합니다.
	//  => STL 을 사용할때는 표준 문서를 참고 하면 됩니다.
	//  => 사용자 정의 타입이나, 함수를 사용할때는 조사하면 됩니다.

	People(People&& p) 
		noexcept( std::is_nothrow_move_constructible<std::string>::value
			      && noexcept(f1()) )
		: name( std::move(p.name) ), age(p.age) 
	{
		f1();
		std::cout << "move" << std::endl;
	} 
};

int main()
{
	People p1("kim", 20);
	People p2 = std::move_if_noexcept(p1); // STL 의 대부분의 컨테이너가
											// 이렇게 구현

	std::pair<int, int> p;
}





