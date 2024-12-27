#include "chronometry.h"

// sum1 과 sum2 의 차이점

// sum1 : 호출이 종료되어서 return 될때, 돌아가서 해야 할일이 추가적으로 있습니다.
//        아래주석 참고
// sum1(5) => return 5 + sum1(4)
//						 return 4 + sum1(3)
//								    return 3 + sum1(2)
//											   return 2 + sum1(1)
//														  return 1

int sum1(int n)
{
	if (n == 1) return 1;
	return n + sum1(n - 1);
}

// sum2 : 함수 호출 종료되면 호출자에 돌아가서 할일이 없습니다.
//        그렇다면 호출자로 돌아갈 필요없이 최초 함수로 한번에 가면 됩니다.
// sum2(5) => sumTail(5, 1)
//			  return sumTail(4, 6)
//                   return sumTail(3, 10)
//						    return sumTail(2, 13)
//								   return sumTail(1, 15)
//										  return 15

// 핵심 : 재귀 호출이 함수의 끝에서 발생한다면(꼬리 재귀)
//       호출정보를 스택에 쌓을 필요도 없고, 돌아갈때도 최초함수로 돌아가면 됩니다.
//       즉, 꼬리 재귀를 사용하면 컴파일러가 최적화를 지원합니다.

int sumTail(int n, int result)
{
	if (n == 1) return result;
	return sumTail(n - 1, result + n);
}
int sum2(int n)
{
	return sumTail(n, 1);
}
//========================================
int main()
{
	long long cnt = 10000; 

	int ret1 = sum1(cnt);
	int ret2 = sum2(cnt);

	printf("%d\n", ret1);
	printf("%d\n", ret2);
}
