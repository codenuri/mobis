#include <iostream>

// 함수가 예외가 없다면 noexcept 를 붙여라.
// => 컴파일러는 함수의 선언만을 조사하게 되므로..
// => 예외가 없다는 사실은 함수 제작자가 함수 선언뒤에 noexcept를 붙여서 알려주어야한다.
//    
void foo(); // 함수 선언(.h)

void foo()	// 함수 구현(정의, .cpp)
{
}
//--------------------
// noexcept 키워드는 2가지 일을 합니다
// 1. 함수가 예외가 없음을 알릴때 사용
// 2. 함수가 예외가 없는지 조사할때 사용

void f1() {}				// 예외가 발생할수 있다.
void f2() noexcept {}		// 예외가 없다는 의미.				
void f3() noexcept(true) {} // 예외가 없다는 의미
void f4() noexcept(false){} // 예외가 있다는 의미

int main()
{
	// 특정 함수가 예외 가능성이 있는지 조사하는 코드
	// => 원리 함수 선언뒤에 noexcept 가 있는지 조사.
	// noexcept(함수 호출하는 표기법) : 실제로 호출되지는 않습니다.
	bool b1 = noexcept( f1() );

	std::cout << b1 << std::endl;
	std::cout << noexcept(f2()) << std::endl;
	std::cout << noexcept(f3()) << std::endl;
	std::cout << noexcept(f4()) << std::endl;

}

