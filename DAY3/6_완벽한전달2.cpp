#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// 완벽한 전달을 하려면
// => lvalue, rvalue 를 모두 어떠한 변화 없이 참조로 받아야 합니다.
// => int&, int&& 를 각각 제공해야 합니다.
// => 아래 코드는 단 한개의 문제가 있습니다. 다음 예제에서 문제점 설명
template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);
}
int main()
{
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n);  

	std::cout << n << std::endl;
}
