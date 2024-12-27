// 3_loop2-1.cpp


int main()
{
	// C++언어의 reference 문법은 C 언어의 포인터 와 완전히 동일합니다.

	int n = 0;

	int* p = &n;
	int& r = n; // 이 코드는 결국 위 한줄과 동일합니다

	*p = 10;
	r  = 10; // 이 코드도 위와 동일한 코드 입니다.
}