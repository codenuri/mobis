#include <iostream>
#include <type_traits> 

class Test
{
//	int data;
	int data = 10; // 이 코드는 결국 생성자에서 "Test() : data(10)"가 됩니다.
					// 즉, 생성자가 하는일이 있습니다
public:
//	virtual void foo() {} 
			// 가상함수가 있으면 생성자에서 가상함수 테이블 초기화 수행
			// 즉, 생성자가 하는일이 있음(생성자가 trivial 하지 않음)

	void goo() {}	// 멤버 함수가 있어도, 생성자가 추가로 할일은 없음.
	
//	Test() {}	// 사용자가 만든 생성자, 컴파일러는 하는 일이 있다고 생각
				// trivial 하지 않음.

	Test() = default;	// 컴파일러가 만든 생성자
						// 컴파일러는 하는일이 있는지 없는지 정확히 알고 있다.
						// 가상함수가 있다면 하는 일 있음.

};

int main()
{
	// trivial 여부를 조사하는 방법
	bool b = std::is_trivially_default_constructible<Test>::value;

	std::cout << b << std::endl;
}