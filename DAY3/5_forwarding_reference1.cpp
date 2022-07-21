
// F.19: For “forward” parameters, 
//       pass by TP&& and only std::forward the parameter

template<typename T> void foo(T a)
{
	T& r = a;
}

int main()
{
	int n = 10;

	int&  r1 = n ; // ok.. int&  는 lvalue reference
	int&& r2 = 10; // ok.. int&& 는 rvalue reference

	// 핵심 1. 
//	int& & r3 = r1; // error. reference 의 reference 
					// 1. 포인터의 포인터는 만들수 있지만
					// 2. reference 의 reference 를 직접 코드로 만들수 없다.

	// 핵심 2. 타입 추론 과정에서 나오는 "reference 의 reference" 는
	//        에러가 아니다.
	//  

	using LREF = int&; // typedef int& LREF;
	using RREF = int&&;

	LREF r4 = n;
	RREF r5 = 10;

	// reference collapsing
	// => 양쪽이 모두 "&&" 인 경우만 "&&"로 해석되고
	// => 그외의 경우는 "&" 입니다.
	LREF& r6 = n;	// int&  &		=> int&
	RREF& r7 = n;	// int&& &		=> int&
	LREF&& r8 = n; // int&  &&		=> int&
	RREF&& r9 = 10;	// int&& &&		=> int&&
}





