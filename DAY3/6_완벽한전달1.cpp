#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// "forwarding"         : 전달받은 인자를 다른 곳으로 보내는 것
// 
// "perfect forwarding" 
// => 전달받은 인자를 어떤 변화도 없이 그대로 다른 곳으로 보내는 것

// 특정함수의 성능을 측정하는 함수를 생각해 봅시다.
template<typename F> 
void chronometry(F f, const int& arg)
{
	// 현재 시간 측정
	f(arg);	
	// 함수 수행시간 출력
}
int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
