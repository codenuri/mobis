#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}


template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}

// main					chronometry				hoo(int&&)
// hoo(10) =========================================> ok
// chronometry(10) =====> int&& arg = 10
//						  hoo(arg) =================> error
//				          hoo(static_cast<int&&>(arg) => ok

template<typename F> void chronometry(F f, int&& arg)
{
//	f(arg); // arg는 lvalue 이므로
			// hoo(int&) 를 찾게 됩니다.

	// 10 이라는 rvalue 를 받으면서 "arg"라는이름이 생겨서 
	// lvalue로 변경되었습니다.
	// 이것을 다시 rvalue로 변경해서 호출하면 됩니다.
	f(static_cast<int&&>(arg));
}




int main()
{
	hoo(10);  // ok
	chronometry(hoo, 10);
}




// 참고
/*
	int&& arg = 10;  // 10 은 rvalue 입니다.
					 // arg 는 rvalue 일까요 ? lvalue 일까요 ?
					 // => lvalue
					 // => 이름이 생겼고, 주소를 구할수 있고, 
	arg = 20;        // ok..  이코드도 가능합니다.

//	Point&& pt = Point();
					// Point() 는 rvalue
					// pt 는 lvalue 입니다.
*/
