#include <stdio.h>

// 문자열 배열 vs 문자열 포인터 - 10p

int main(void)
{
	// 아래 2줄의 차이점을 생각해 보세요
    char sa[] = "Hello";  
				// => "Hello" 자체 초기값은 코드메모리에 보관하고 있다가
				// => 실행시 스택을 6개 확보하고, 값을 넣은 것.

    char* sp = "Hello";   
				// => "Hello" 가 .rdata 섹션에 생성되고
				// => 실행시간에 스택에는 포인터 변수(sp)만 생성되고
				// => sp 가 .rdata 섹션에 있는 문자열을 가리키게 됩니다.

//    *sa = 'A'; // ok. 스택은 R/W 가능
    *sp = 'A'; // runtime error. sp 가 가리키는 곳은
				// 상수 메모리(.rdata) 이므로 

	printf("finish\n");
}
// 정리
// 문자열 배열(지역변수) : 스택에 문자열이 있으므로 R/W 가능
// 문자열 포인터        : 문자열 자체는 ".rdata" 에 있다.
//						 상수 메모리 이므로 Read 만 가능. Write 할수 없다. (runtime error)