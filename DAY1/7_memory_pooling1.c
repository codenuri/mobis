#include <stdio.h>
#include <stdlib.h>

// malloc/free 아래 처럼 직접하면
// 1. 할당/해지시에 성능(빈곳을 찾는 작업)
// 2. 서로 다른 크기를 여러개 할당하면 메모리 파편화 현상(fragment) 발생
// 3. 필요한 크기보다 좀더 크게 할당됨(메모리 할당시, 크기도 기록)
//    => malloc(sizeof(bullet)) 은 8 이 아니라 "8 + 할당한 메모리크기를 기록하기 위한 공간"할당

// 4. 일부 임베디드 환경에서는 malloc/free 사용금지!!

// 외와 같은 문제의 해결책
// => 메모리 풀링(pooling)

typedef struct _bullet
{
	int x;
	int y;
} bullet;
 

int main()
{
	bullet* p1 = (bullet*)malloc(sizeof(bullet)); // 화면에 총알등장
	bullet* p2 = (bullet*)malloc(sizeof(bullet));

	free(p1); // 화면에서 총알이 사라졌다.

	bullet* p3 = (bullet*)malloc(sizeof(bullet));

	free(p2);
	free(p3);

	// 수백개의 총알을 "메모리 할당/해지" 를 반복하면 너무 오버헤드가 큽니다.
}
