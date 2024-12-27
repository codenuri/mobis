#include "chronometry.h"

// 재귀 호출
// => 자신이 다시 자신을 호출하는 것
// 장점 : 복잡한 알고리즘을 단순한 코드로 작성
//        트리 순회, 하노이 타워, 퀵소트 

// 단점 : 느리다. (함수 호출의 오버헤드)
//		 함수 호출이 많아 지면 "stack overflow" 발생

// 함수를 호출하면 stack 을 사용하게 됩니다.
// #1. 인자 전달을 위해 사용 ( 32bit 인 경우 )
// #2. 돌아올 주소를 저장하기 위해서 사용
// #3. rbp 보관 ( push rbp )
// #4. 지역변수를 만들기 때문에 사용



long long sum1(long long n)
{
	if (n == 1) return 1;
	return n + sum1(n - 1);
}

int main()
{
	long long cnt = 50000; 

	long long ret1 = sum1(cnt);

	printf("%lld\n", ret1);
}
