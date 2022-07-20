#include <iostream>

// Rule Of 3/5

// 클래스 안에 포인터가 있고, 동적 할당을 사용하면

class People
{
	char* name;
	int   age;
public:
	People(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy_s(name, strlen(s)+1, s);
	}
	~People() { delete[] name; }

	// 복사 생성자
	People(const People& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name );
	}

	// 대입 연산자
	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		age = p.age;
		delete[] name;

		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		return *this;
	}
};






int main()
{
	People p1("kim", 20);
	People p2 = p1; 
	p2 = p1; 

	People p3 = std::move(p1);
	p3 = std::move(p2);		  
}




