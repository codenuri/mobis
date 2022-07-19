#include <iostream>
#include <vector>

// 참조계수를 책임지는 기반 클래스
class RefCount
{
	int refcnt = 0;
public:
	// 핵심 : "기반 클래스로 사용되는 클래스"는 반드시 소멸자가 가상함수 이어야 한다.
	virtual ~RefCount() { std::cout << "~RefCount" << std::endl; }

	void AddRef() { ++refcnt; }

	//	사용자 코드			// this의 원리,
	void Release()			// void Release( RefCount* this )
	{
		if (--refcnt == 0)
			delete this;	// 여기서 this는 RefCount* 타입이라는 것이 핵심!
							// 이때 소멸자가 제대로 호출되려면
							// 소멸자를 가상함수로 해야 합니다.
	}
};
// RefCount obj;
// obj.Release() => Release(&obj)



// Truck 도 참조계수 기술을 사용하고 싶다.
class Truck : public RefCount
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	Truck* p = new Truck;

	p->AddRef();
	p->Release();
}


