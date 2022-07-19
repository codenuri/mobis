#include <iostream>
#include <vector>
template<typename T>
class RefCount
{
	int refcnt = 0;
public:
	~RefCount() { std::cout << "~RefCount" << std::endl; }

	void AddRef() { ++refcnt; }

	//	사용자 코드			// this의 원리,
	void Release()			// void Release( RefCount* this )
	{
		if (--refcnt == 0)
		//	delete this;	// this가 RefCount* 이므로  Truck 소멸자 호출안됨
			
			delete static_cast<T*>(this); // Truck*으로 변경해서 delete
	}
};

class Truck : public RefCount<   >
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


