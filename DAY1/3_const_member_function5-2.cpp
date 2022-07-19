#include <iostream>
#include <vector>

class Car
{
	int speed;
	int refcnt = 0;
public:
	~Car() { std::cout << "~Car" << std::endl; }

	void AddRef() { ++refcnt; }
	void Release()
	{
		if (--refcnt == 0)
			delete this;
	}
};

// Truck 도 참조계수 기술을 사용하고 싶다.
class Truck
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


