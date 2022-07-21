#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// F.19: For “forward” parameters, 
//       pass by TP&& and only std::forward the parameter

// 전달 받은 인자를 다른 곳으로 완벽히 보내려면
// 1. 인자를 받을때는 "T&&" 로 받고
// 2. 다른 곳에 보낼때는 "static_cast<T&&>(arg))" 로 캐스팅해서 전달
//                ===>"std::forward<T>(arg)" 로 묶어서 전달

template<typename F, typename T&&>
void chronometry(F f, T&& arg)
{
//	f(static_cast<T&&>(arg));
	f(std::forward<T>(arg)); // 위 캐스팅을 하는 함수
}

int main()
{
	int n = 10;

	chronometry(foo, 10);	
	chronometry(goo, n);	
}

