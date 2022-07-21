#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	std::cout << __FUNCSIG__ << std::endl; // 현재 함수 이름 출력
}
int main()
{
	int n = 10;

	foo(n);  //
	foo(10); //
}




