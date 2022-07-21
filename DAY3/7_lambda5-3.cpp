#include <iostream>

// [](int a, int b) { return a + b; }; 를 보고 만든 클래스
class CompilerGeneratedName
{
	// 캡쳐한 람다 표현식은 아래와 같이 멤버 변수가 추가됩니다.
	int v1;
public:
	CompilerGeneratedName(int n) :v1(n) {}

	int operator()(int a, int b) const { return a + b + v1; }

	// 캡쳐한 람다 표현식이 생성하는 클래스에는 
	// 아래 멤버들(함수포인터로 변환)이 없습니다.
	/*
	static int _invoke(int a, int b)
	{
		std::cout << "_invoke" << std::endl;
		return a + b + v1; // <=== error. static 멤버 함수에서는
							//			  멤버 데이타 접근 안됨.. 
	}

	using FP = int(*)(int, int);

	operator FP() const { return &CompilerGeneratedName::_invoke; }
	*/
};

int main()
{
	int v1 = 0;

	// 결론 : 아래 코드는 에러 입니다.
	//      => 캡쳐한 람다표현식은 함수포인터로 변환될수 없습니다.
	//      => 이유는 위 class 를 생각해 보세요. 
	//	int(*fp)(int, int) = [v1](int a, int b) { return a + b + v1; };

	int(*fp)(int, int) = CompilerGeneratedName(v1);

	int n = fp(1, 2); 
}