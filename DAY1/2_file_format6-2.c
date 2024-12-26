#include <stdio.h>

int main()
{
	// 문자열 배열
	char sa1[] = "Hello";
	char sa2[] = "Hello";

	// 문자열 포인터
	const char* sp1 = "Hello";
	const char* sp2 = "Hello";

	// 아래 코드 결과 예측해 보세요
	// => 같은 주소 ? 다른 주소 ?

	printf("%p, %p\n", sa1, sa2); // 다른 주소
	printf("%p, %p\n", sp1, sp2); // 같은 주소. 상수 메모리 이므로
									// 동일한 문자열을 여러번 만들필요 없다.

}

// 결론 
// 프로그램에서 "읽기만 하는 문자열" 이 필요하면
// => 문자열 배열 보다 문자열 포인터 권장(공유!!)
// => 문자열 포인터를 만들때는 "char*" 가 아닌 "const char*" 로 해야 항상 안전!!
//		실수로 수정하게 되면 runtime error 가 아닌 compiler time error

// RUST 언어
// String 타입 : 문자열을 소유하는 타입(R/W 가능), C 언어의 문자열 배열과 유사
// str    타입 : C언어의 const char*. 상수 메모리에 있는 읽기 전용 문자열(공유됨.) 

// C++
// string : 문자열 소유
// string_view : const char* 의 의미. 