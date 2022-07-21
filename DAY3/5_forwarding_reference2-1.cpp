// 함수 인자로
// int&  : int 타입의 lvalue 만 받겠다는 의도
// int&& : int 타입의 rvalue 만 받겠다는 의도
// T&    : 임의 타입의 lvalue 만 받겠다는 의도.  
// T&& : 

template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 3;

	// 1. 타입을 명시적으로 전달하는 경우.. ? 채워 보세요
	// => 타입을 전달했으므로 "함수인자로 추론하지 않고" 무조건 전달한 타입사용

	f3<int>(n);   // T=int   T& = int&     생성된함수 : f3(int& )
	f3<int&>(n);  // T=int&  T& = int& &   생성된함수 : f3(int& )
	f3<int&&>(n); // T=int&& T& = int&& &  생성된함수 : f3(int& )

	// 2. 타입을 전달하지 않은 경우
	// => 컴파일러는 함수 인자를 보고, 함수를 생성하기 위해
	//    T 의 타입을 결정한다.
	f3(3);	// 3 은 int 이므로 T=int 로 결정하고 함수 생성하면
			// f3(int&) 가 되므로 3을 받을수 없다.
			// T=int&, T=int&&, 로해도 받을수 없다.
			// 컴파일 에러. 

	f3(n);  // T=int, int&, int&& 중 어느것으로 결정해도 ok.
			// T = int 로 결정(규칙)
}








template<typename T> void f4(T&& a)
{
}
