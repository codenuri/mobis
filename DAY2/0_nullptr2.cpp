// caller : 함수와 인자를 받아서, 함수를 호출하는 도구
template<typename F, typename ARG>
void caller(F f, ARG arg) // int age = 0 인데.. f(arg) 하므로 error
{
	// 현재 시간 기록
	f(arg);
	// 함수 수행시간 출력
}
void foo(int* p) { }

int main()
{
	int n = 0;
	foo(0);	// ok     리터럴 0 은 포인터에 전달가능하지만
	foo(n); // error. 0으로 초기화된 정수형 변수는 안된다.

	// 현재 예제에서는 아래코드가 에러라는것을 꼭 기억해 주세요..
//	caller(foo, 0); // foo(0) 처럼 호출해 달라는 것
					// 하지만, error
					//

	caller(foo, nullptr); // ok..  이렇게 사용하려고 nullptr을 만든것. 
	
}