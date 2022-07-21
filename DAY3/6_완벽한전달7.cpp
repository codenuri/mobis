#include <iostream>

void f0() {}
void f1(int& a) {}
void f3(int n, int& r, double d) {}

// 한 개 이상의 인자를 forwording 하려면
// C++11 의 "가변 인자 템플릿"을 사용하면 됩니다.

template<typename F, typename ... T&&>
void chronometry(F f, T&& ... arg)
{
	f(std::forward<T>(arg)... ); 
}

int main()
{
	int n = 10;

	chronometry(f0); // 인자가 없는 경우
	chronometry(f1, n); 
	chronometry(f3, 3, n, 3.4);
}

