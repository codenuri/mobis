// 106 page
#include "chronometry.h"
#include <thread>  

const int sz = 10000000; 


// 아래 코드는 나쁜 코드
// => 2개의 스레드가 각각 n1, n2 만 사용한다면
//    2개의 변수는 메모리에서 캐쉬 크기 만큼 떨어 뜨려 놓어야 합니다.
// => 그렇지 아래 2개의 변수가 각각 다른 CPU 의 캐쉬에 동시에 놓이게 될때
//    캐쉬 무효화가 계속 발생해서 성능 저하가 있습니다.
// long long n1 = 0;
// long long n2 = 0;

// 해결책 #1. padding 넣기
/*
long long n1 = 0;
char padding[64]; // 2개의 변수를 떨어뜨리기 위해 만든 코드
long long n2 = 0;
*/

// 해결책 #2. C/C++ 언어에서 변수의 시작주소를 align 하는 문법이 제공됩니다.
//			 C11, C++11 부터, 

// C언어   : _Alignas (C11)
// C++언어 : alignas  (C++11)

#ifdef __cplusplus			// 현재 컴파일러가 C인지 C++인지 조사
	alignas(64) long long n1 = 0;
	alignas(64) long long n2 = 0;
#else 
	_Alignas(64) long long n1 = 0;
	_Alignas(64) long long n2 = 0;
#endif

void f1()
{
	// 이 함수 안에서는 n1 만 사용합니다.
	for (int i = 0; i < sz; i++)
	{
		n1 += 1;
	}
}

void f2()
{
	// 이 함수 안에서는 n2 만 사용합니다.
	for (int i = 0; i < sz; i++)
	{
		n2 += 1;
	}
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