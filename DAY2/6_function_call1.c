#include <stdio.h>

// 함수 호출이란 ?
// 1. 인자를 약속된 장소에 넣고
// 2. 돌아올 주소를 스택에 넣고
// 3. 함수로 이동( jmp )
// 4. 반환 값은 약속된 장소에 보관
//    => C/C++ 은 eax 라는 레지스터에 보관

// C소스에 인라인 어셈블리가 포함되어 있으면 
// => 컴파일시에 어셈블리의 종류를 명시해야 합니다.( intel , at&t )
// => gcc 소스이름.c  -masm=intel   로 빌드
// => gccbuild.bat 에 이미 포함해 두었습니다.

int foo()
{
//	return 10;	// eax 레지스터에 10 을 넣은것

	asm("mov 	eax, 30");	// "return 10" 의 의미를 어셈블리어(기계어)로 직접 표기
}

int main()
{
	int n = 0; 
	
	n = foo();

	printf("%d\n", n);
}