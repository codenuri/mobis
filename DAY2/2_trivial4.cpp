#include <iostream>
#include <type_traits>

// C90. memset, memcpy 에 의존하지 말라!

class Test
{
	int data;
public:
	virtual void foo() {}
};
void init(Test* p)
{
	// trivial : special member function 이 하는일이 
	//		     널리 알려진 대로 동작한다.
	//           => 함수의 동작에 대한 이야기

	// standard layout : 메모리 구조가 C 의 구조체와 동일한가 ?
	//					 가상함수가 있으면 "가상함수 테이블 포인터" 추가
	//					=>메모리의 구조에 대한 이야기

	// POD : Plain Old Data. 타입이 C의 구조체와 호환되는지 나타내는 용어.
	//       C++98 시절의 단어.

	// C++11 부터 POD = trivial + standard_layout

	// C 언어는 memset, memcpy 등을 많이 사용합니다.

	static_assert(std::is_trivial<Test>::value &&
		    	  std::is_standard_layout<Test>::value,
				  "error");

	memset(p, 0, sizeof(Test));
}


int main()
{
	std::cout << sizeof(Test) << std::endl;
			// sizeof(int) + sizeof(컴파일러가 추가한 가상함수 테이블포인터)
			// 4 + 8		
	Test* p = new Test;

//	init(p);
//	p->foo();

	delete p;
}