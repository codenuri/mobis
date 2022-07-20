#include <iostream>

// 생성자 호출순서 를 알아 두세요.

struct BM  // Base Member 라는 의미로 "BM" 이라고 했습니다.
{
	BM() { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM 
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};
struct Base
{
	BM bm;
	
	// 사용자코드		// 컴파일러가 변경한 코드
	Base()			// Base() : bm()		=> call BM::BM()
	{
		std::cout << "Base()" << std::endl;
	}
	~Base() 
	{
		std::cout << "~Base()" << std::endl; 

		// ~BM(); // 멤버 데이타의 소멸자 호출
	}
};
struct Derived : public Base
{
	DM dm;
	
	// 사용자코드		// 컴파일러가 변경한 코드
	Derived()		// Derived() : Base(), dm() <= 순서가 중요합니다.
	{											// 사용자가 변경할수 없습니다.
		std::cout << "Derived()" << std::endl;
	}
	~Derived()
	{
		std::cout << "~Derived()" << std::endl; 

		// ~DM::DM()  멤버 데이타 소멸자 먼저 호출
		// ~Base()    기반 클래스 소멸자 호출.  
	}
};
int main()
{
	Derived d; // 이 순간의 결과를 예측해 보세요.
			   // call Derived::Derived() 입니다.
}
