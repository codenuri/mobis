#include <iostream>
#include <vector>

// 참조계수를 책임지는 기반 클래스
class RefCount
{
	int refcnt = 0;
public:
	~RefCount() { std::cout << "~RefCount" << std::endl; }

	void AddRef() { ++refcnt; }
	void Release()
	{
		if (--refcnt == 0)
			delete this;
	}
};

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


