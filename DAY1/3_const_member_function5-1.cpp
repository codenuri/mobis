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
int main()
{
	Car* p1 = new Car;
	p1->AddRef(); // 규칙 1. 객체를 만들면 참조계수 증가

	Car* p2 = p1;
	p2->AddRef(); // 규칙 2. 객체주소를 복사해도 참조계수 증가

	p1->Release();
	p2->Release(); // 규칙 3. 객체 사용후 참조계수 감소
					// => 이순간 참조계수가 0이므로 delete 됩니다.
}