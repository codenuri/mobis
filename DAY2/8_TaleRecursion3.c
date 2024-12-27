#include "chronometry.h"

// long long
long long sum1(long long n)
{
	if (n == 1) return 1;
	return n + sum1(n - 1);
}

long long sumTail(long long n, long long result)
{
	if (n == 1) return result;
	return sumTail(n - 1, result + n);
}
long long sum2(long long n)
{
	return sumTail(n, 1);
}

long long sum3(long long n)
{
	long long s = 0;

	for (long long i = 0; i <= n; ++i)
		s += i;
	return s;
}

int main()
{
	long long cnt = 10000;

	CHECK(START); 	long long ret1 = sum1(cnt);	// 일반 재귀
	CHECK(LAB);     long long ret2 = sum2(cnt);	// 꼬리 재귀
	CHECK(LAB);     long long ret3 = sum3(cnt);	// 반복문
	CHECK(END);

	printf("%lld\n", ret1);
	printf("%lld\n", ret2);
	printf("%lld\n", ret3);
}
