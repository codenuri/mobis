#include "chronometry.h"
// => 내부적으로는 win32 api 의 QueryPerfomanceTimer 사용

const unsigned long long count = 100000000; // 1억

// 정수를 사용한 1억번의 덧셈
void ex1()
{
	long long s = 0;	// 64bit 정수

	for (unsigned long long i = 0; i <= count; i++)
		s += i;
}

// 실수를 사용한 1억번의 덧셈
void ex2()
{
	double s = 0;

	for (double i = 0; i <= count; i++)
		s += i;
}

int main()
{
	/*
	CHECK(START); // 현재 시간 기록
	ex1();
	CHECK(LAB);   // 수행시간 출력후, 다시 시간 기록
	ex2();
	CHECK(END);   // 수행시간만 출력
	*/

	CHRONOMETRY(ex1); // ex1() 를 수행하고, 소요시간 출력
	CHRONOMETRY(ex2);
}

