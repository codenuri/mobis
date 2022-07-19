#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	int refcnt = 0;
public:
	~RefCount() { std::cout << "~RefCount" << std::endl; }

	void AddRef() { ++refcnt; }


	void Release()			
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
	const Truck* p = new Truck;

	p->AddRef();
	p->Release();
}


