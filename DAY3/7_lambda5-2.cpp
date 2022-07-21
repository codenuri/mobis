#include <iostream>

// [](int a, int b) { return a + b; }; 를 보고 만든 클래스
class CompilerGeneratedName
{
public:
	int operator()(int a, int b) const { return a + b; }

	// 함수 포인터 변환을 위해 추가된 멤버 들.. 
	static int _invoke(int a, int b)
	{
		std::cout << "_invoke" << std::endl;
		return a + b;
	}

	using FP = int(*)(int, int);

	operator FP() const { return &CompilerGeneratedName::_invoke; }
};

int main()
{
//	int(*fp)(int, int) = [](int a, int b) { return a + b; };

	int(*fp)(int, int) = CompilerGeneratedName();

	int n = fp(1, 2); // 결국 _invoke 호출
}