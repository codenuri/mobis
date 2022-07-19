#include <iostream>

class Counter
{
	int value{ 0 };
public:
	// 핵심 : "*this" 를 반환할때는 반드시 "reference" 반환을 해야 합니다.
	//       아래 2줄의 차이점을 명확히 알아 두세요
//	Counter  increment()  // 복사본(temporary) 반환
	Counter& increment()  // 복사본 생성 안됨
	{
		++value;
		return *this;
	}
	int get() const { return value; }

	~Counter() { std::cout << "~Counter" << std::endl; }
};

int main()
{
	Counter c;	
	std::cout << "------------" << std::endl;

	c.increment().increment().increment();  
	
	std::cout << "------------" << std::endl;

	std::cout << c.get() << std::endl; // 1
}