#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 특정함수의 성능을 측정하는 함수를 생각해 봅시다.
template<typename F> 
void chronometry(F f, int arg)
{
	// 현재 시간 측정
	f(arg);	
	// 함수 수행시간 출력
}

int main()
{
	int n = 10;

	foo(10);
	goo(n);

	std::cout << n << std::endl;
}
