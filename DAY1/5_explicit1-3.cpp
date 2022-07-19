#include <iostream>

class Vector
{
public:
	Vector(int sz) { std::cout << "Vector(int)" << std::endl; }
};

int main()
{
	// 실행해서 결과 확인해 보세요.
	Vector v1(10);
	Vector v2(10);
}
