#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);	// 이렇게만 하면 됩니다.

	f( static_cast<int&>(arg) ); // 필요없는 캐스팅입니다.
						// 하지만, 있어도 문제 되지 않습니다.
						// 결국, 컴파일러에 의해 제거 됩니다.
						
						// 이렇게 놓고 보면.. 이제 아래 함수와 유사합니다.
						// T&& 로 묶을수 있습니다.
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// int&, int&& 가 필요하면 "T&&" 로 자동생성되게 할수 있다
// => 그런데, 그렇게 하려면 구현이 동일해야 한다.

template<typename F, typename T&&> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;
							 
	chronometry(foo, 10);	// T = ?,     T&& = ?
							// static_cast<?>(arg)
	chronometry(goo, n);	//
}

