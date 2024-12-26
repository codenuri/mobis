// 106 page
#include "chronometry.h"
#include <thread>  

const int sz = 10000000; 

long long n1 = 0;
long long n2 = 0;

// 해결책 #3. 함수 안에서 전역변수를 직접 사용하지 말고
// => 지역변수로 연산후에
// => 결과만 전역변수에 담는다.

void f1()
{
	long long local = n1;

	for (int i = 0; i < sz; i++)
	{
		local += 1;
	}

	n1 = local;
}

void f2()
{
	long long local = n2;

	for (int i = 0; i < sz; i++)
	{
		local += 1;
	}
	n2 = local;
}

void single_thread()
{
	// 한개의 스레드가 2개의 작업을 순차적으로 수행
	f1();
	f2();
}


void multi__thread()
{
	// 2개의 스레드가 각각 작업을 수행.. 
	// => 공유자원등이 없으므로 동기화등도 필요 없음. 
	std::thread t1(f1);
	std::thread t2(f2);
	t1.join();
	t2.join();
}

int main()
{
//	CHRONOMETRY(multi__thread);
	CHRONOMETRY(single_thread);
	CHRONOMETRY(multi__thread);

	// 아래 결과로 나오는 주소가 핵심입니다.
	printf("&n1 : %p\n", &n1);
	printf("&n2 : %p\n", &n2);
}
// 위 예제는 C++ 사용하므로
// gppbuild 소스.cpp  또는

// g++ 소스.cpp