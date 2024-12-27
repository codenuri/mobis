// 3_loop2-1.cpp


int main()
{
	// C++언어의 reference 문법은 C 언어의 포인터 와 완전히 동일합니다.
	// => reference 는 기존 변수의 "alias" 라고 배우지만
	// => 기계어 코드 레벨에서는 결국 포인터 입니다.
	// => 아래 코드를 godbolt.org 에 넣어 보세요.  언어는 C++

	int n = 0;

	int* p = &n;
	int& r = n; // 이 코드는 결국 위 한줄과 동일합니다

	*p = 10;
	r  = 10; // 이 코드도 위와 동일한 코드 입니다.
}

// 인자로 전달 받은 것을 읽기만 하려고 합니다.
// 다음중 좋은 코드는 ?
void f1(int n)        { int ret = n;}
void f2(const int& n) { int ret = n;}