// 함수 인자로
// int&  : int 타입의 lvalue 만 받겠다는 의도
// int&& : int 타입의 rvalue 만 받겠다는 의도
// T&    : 임의 타입의 lvalue 만 받겠다는 의도.  
// T&&   : 임의 타입의 lvalue 와 rvalue 를 모두 받겠다는 의도..

// "모두 받는 것은" => "받을수 있는 함수를 생성" 하겠다는 것

f4(n) => f4(int&)  함수 생성
f4(3) => f4(int&&) 함수 생성

// 또 하나의 핵심 : 생성된 함수는 모두 "call by reference" 라는 것

// 꼭 외울것
f4(n)  => T=int&   T&& = int& && => int&   f4(int&)
f4(3) = > T=int    T&& = int&&             f4(int&&)



// 아래 f4가 핵심 입니다.
template<typename T> void f4(T&& a)
{
}
int main()
{
	int n = 3;

	// 1. 타입 인자를 전달할때
	f4<int>(3);    // T = int     T&& = int&&      f4(int&&) 
	f4<int&>(n);   // T = int&    T&& = int& &&    f4(int&)
	f4<int&&>(3);  // T = int&&   T&& = int&& &&   f4(int&&)

	// 2. 타입 인자를 생략할때
	//    함수 인자를 보고 컴파일러가 T 의 타입을 결정하는데..
	//    "어떤 타입이 되는지 완벽히 알고 있어야 합니다."

	f4(n);	// n 은 int 이므로 T = int 로 결정하면 f4(int&&)됩니다.
			// => 이렇게 생성되면 f4(n) 이 에러가 됩니다.
			
			// T = int& 로 결정하면 에러가 아닙니다.
			// 그래서 이때
			// "T = int&", "T&& = int&", f4(int&) 가 됩니다.<== 외우세요

	f4(3);	// T=int, int&& 모두 가능한데..
			// 컴파일러는 "T=int"로 결정합니다.
			// "T=int, T&&=int&&, f4(int&&)" 입니다.

}





