#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	mutable int refcnt = 0;
public:
	~RefCount() { std::cout << "~RefCount" << std::endl; }

	// 참조계수 관련 멤버 함수는 일반적으로 "상수 멤버 함수"로 하게 됩니다.
	// => 상수 객체도 수명관리 가능해야 합니다.
	void AddRef() const { ++refcnt; }

	void Release() const		
	{
		if (--refcnt == 0)
			delete static_cast<T*>(this); 
	}
};





class Truck : public RefCount< Truck  >
{
	int speed;
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	// 아래 코드를 생각해 봅시다.
	// => p를 통해서는 객체를 "Read" 만 하겠다는 의도.
	// => 읽기만 한다면 아래처럼 "const" 를 붙이는 것은 아주 좋은 코딩 스타일입니다.
	const Truck* p = new Truck;

	// 상수 객체라도 수명관리가 되어야 합니다.
	// => 아래 2개의 함수는 반드시 "상수 멤버 함수" 로 해야 합니다.
	p->AddRef();
	p->Release();
}


