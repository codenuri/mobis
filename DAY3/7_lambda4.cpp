#include <iostream>

// C170. 람다표현식이 오버로딩이 필요 하면 generic 람다를 사용해라. - C++14

int main()
{
	//핵심 1. 람다 표현식의 결과는 임시객체 입니다.
	// => 따라서, lvalue reference 에 담을수 없습니다.
//	auto& r = [](int a, int b) { return a + b; }; 
				// class xxx { operator()(int a, int b) {} }; xxx();

//	const auto& r1 = [](int a, int b) { return a + b; }; // ok


	// 그런데. 보통은 아래처럼 값 타입에 담습니다.

//	auto add = [](int a, int b) { return a + b; };

	// C++14 부터, 람다 표현식에 auto 사용 가능합니다.
	auto add = [](auto a, auto b) { return a + b; };

	std::cout << add(1,   2) << std::endl;
	std::cout << add(1.1, 2.2) << std::endl;
	std::cout << add(1,   2.2) << std::endl;
	std::cout << add(1.1, 2) << std::endl;
}

// 원리.. 컴파일러가 생성한 클래스의  () 연산자가 템플릿 입니다.
class CompilerGeneratedName
{
public:
	// 핵심 2개의 인자가 서로 다른 템플릿
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};

