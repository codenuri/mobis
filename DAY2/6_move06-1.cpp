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
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		std::cout << "복사 생성자" << std::endl;
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
	/*
	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		std::cout << "move 생성자" << std::endl;
		c.name = nullptr;
	}
	*/
};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	

	// 핵심 1. 클래스 사용자는 어떠한 타입에 대해서도 std::move() 사용가능합니다.

	// 1. Cat 안에 move 생성자가 있으면 move 생성자 사용
	//    => 빨라집니다.

	// 2. Cat 안에 move 생성자가 없으면 copy 생성자 사용
	//    => 즉, 에러는 없다는 것
	//    => 단, move 되지 않고, 복사 되므로 성능향상은 없습니다.

	Cat c3 = std::move(c1); // 단지, 캐스팅일 뿐입니다.
						// static_cast<Cat&&>(c1);


	// 핵심 2. move 개념은 user define type 만 적용됩니다.
	//        primitive type 은 의미 없습니다.
	
	std::string s1 = "hello";
	std::string s2 = std::move(s1); // => string 클래스 안에 있는
									//    move 생성자 호출. 

	int n1 = 10;
	int n2 = std::move(n1); // int n2 = static_cast<int&&>(n1) 인데
							// int n2 = n1 과 동일합니다.

	std::cout << n1 << std::endl; // 이경우 n1 이 "0"이 되나요 ??
								  // => 아닙니다. 그냥 10 입니다.

	int* p1 = &n1;
	int* p2 = std::move(p1);	// int* p2 = p1 과 동일합니다.
								// p1이 0 으로 reset 되는거 아닙니다.	

	std::cout << p1 << std::endl; //
}