// SL.con.4: don’t use memset or memcpy for arguments that are 
//           not "trivially-copyable"

#include <iostream>

// trivial : 하는 일이 "자명(널리 알려진 디폴트 방식대로 동작)" 하다는 의미.
// trivial 생성자      : 아무 일도 하지 않은 생성자
// trivial 복사 생성자 : 모든 멤버를 얕은 복사하는 복사 생성자.

class A
{
};

// B의 생성자는 trivial 할까요 ?
// => 생성자가 한개도 없으므로 "컴파일러가 디폴트 생성자" 제공. 
class B 
{
	int data;
public:
	virtual void foo() {}
};

int main()
{
	// malloc을 사용하면 생성자 호출이 안됩니다.
	B* p = static_cast<B*>(malloc(sizeof(B)));


	new(p) B; // 이 코드가 생성자만 호출하는 코드입니다. 

	// 결국 아래 코드는 생성자 호출없이 만든 객체를 사용하는 코드입니다.
	// 생성자가 하는 일이 없었다면 아래 코드가 문제 없어야 합니다.
	p->foo();

	std::cout << "main 종료" << std::endl;
}