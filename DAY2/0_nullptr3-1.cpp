// 0_nullptr3-1
#include <iostream>

int main()
{
	// 1. 프로그램에서 사용되는 "값" 들을 리터럴(literal)이라고 합니다.
	// 2. 모든 리터럴은 타입이 있습니다.
	10;		// int
	3.4;	// double
	3.4f;	// float
	"hello";// const char[6]  이 정확한 타입
	true;	// bool
	nullptr;// std::nullptr_t

	std::nullptr_t mynull = nullptr;

	// 이제 nullptr 대신 mynull 을 사용해도 동일 합니다.
	int* p1 = nullptr;
	int* p2 = mynull; // 위와 완전히 동일
}