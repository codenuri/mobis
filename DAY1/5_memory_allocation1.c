#include "chronometry.h"
#include <string>

// block 안에서는 지역변수 선언.
// => "루프 안에서는 지역변수를 선언하지 말라" 라는 격언도 있지만
// => 그런데, int 같은 primitive 타입은 차이 거의 없습니다.
// => 동일한 기계어 코드 

// => 그런데, C++의 사용자정의 타입(std::string 같은)은 차이가 큽니다.
//    "소멸자 호출"

const unsigned long long count = 100000000;

void ex1()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		std::string s = "Hello";
		int n = 10 + 20;
	}
}

void ex2()
{
	int n = 0;
	std::string s = "Hello";

	for (unsigned long long i = 0; i <= count; i++)
	{
		s = "Hello";
		n = 10 + 20;
	}
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
	
}
