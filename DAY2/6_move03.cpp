#include <cstring>
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1; // 복사 생성자 호출
				 // 얕은 복사(shallow copy) 발생
}