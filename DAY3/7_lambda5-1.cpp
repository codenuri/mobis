#include <iostream>

// [](int a, int b) { return a + b; }; 를 보고 만든 클래스
class CompilerGeneratedName
{
public:
	int operator()(int a, int b) const { return a + b; }
	
	static int _invoke(int a, int b) 
	{
		std::cout << "_invoke" << std::endl;
		return a + b; 
	}

	// 함수 포인터로 변환하기 위한 변환연산자 
	using FP = int(*)(int, int);

//	operator FP() const { return 함수 주소; }
//	operator FP() const { return &CompilerGeneratedName::operator(); }
				// => 멤버 함수주소는 일반함수 포인터와 호환 안됨
				// => static 멤버 함수 이어야 가능.
				// => 그런데,operator() 는  static이 될수 없다.. 
	operator FP() const { return &CompilerGeneratedName::_invoke; }
};

int main()
{

	int(*fp)(int, int) = CompilerGeneratedName();

	int n = fp(1, 2); // 결국 _invoke 호출
}