// 2_file_format6-1.c

int main()
{
	char sa[] = "Hello"; // 문자열 자체가 stack. R/W 가능

//	char* sp = "Hello";  // sp 는 stack. 문자열 자체는 .rdata 읽기만 가능
						 // 상수 메모리는 "상수가 아닌 것을 가리키는 포인터로 가리킨것"
						 // C언어(gcc) 허용, 
						 // C++(g++) 언어 에러(또는 경고)
						 // 
//	*sp = 'X'; // runtime error

	// 핵심
	// C 또는 C++ 에서 문자열 포인터를 만들때는
	// 반드시 char* 가 아닌 const char* 를 사용하세요
	const char* sp = "Hello"; // C/C++ 모두 가능. 아주 좋은 코드

	*sp = 'x'; // runtime error 가 아닌 컴파일 에러!!!
}