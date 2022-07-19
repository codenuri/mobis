#include <iostream>

class Counter
{
	int value{ 0 };
public:
	Counter increment()
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