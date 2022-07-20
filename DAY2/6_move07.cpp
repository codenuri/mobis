#include <iostream>

// Rule Of 3/5

// 클래스 안에 포인터가 있고, 동적 할당을 사용하면
// => 소멸자, 복사 생성자, 대입연산자를 만들어야 합니다.
// => 이것을 "Rule Of 3" 라고 합니다

// 그런데, C++11 이 나오면서 위 3개 외에도
// => move 생성자, move 대입연산자도 만드는 것이 좋다.
// => 이것을 "Rule Of 5" 라고 합니다


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
	// move 생성자
	People(People& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;
	}

	// move 대입 연산자
	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		age = p.age;
		delete[] name;
		
		name = p.name;
		p.name = nullptr;

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




