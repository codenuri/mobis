#include "chronometry.h"
#include <stdlib.h>
#include <string.h>

#define INPUT_COUNT 100000

// 1,2,3,4 ... 를 순차적으로 반환.. 사용자 입력 시뮬레이션
int get_input()
{
	static int num = 0;
	++num;

	if (num == INPUT_COUNT)
	{
		num = 0;
		return -1;
	}
	return num;
}
// ------------------------------------------

void ex1()
{
	int n = 0;

	int size = 4;
	int* score = (int*)malloc(sizeof(int)*size);
	int count = 0;

	while (1)
	{
//		scanf("%d", &n);

		n = get_input(); // 1 ~ 100000 까지 반환하고 -1 반환

		if (n == -1)
			break;

		score[count++] = n;

		if ( count == size )
		{
			int* tmp = (int*)malloc(sizeof(int) * size * 2);

			memcpy(tmp, score, sizeof(int)* size);

			free(score);
			score = tmp;
			size = size * 2;
		}
	}
	free(score);
}

void ex2()
{
	int n = 0;

	int size = 4;
	int* score = (int*)malloc(sizeof(int)*size);
	int count = 0;

	while (1)
	{
//		scanf("%d", &n);

		n = get_input(); 

		if (n == -1)
			break;

		score[count++] = n;

		if ( count == size )
		{
			int* tmp = (int*)malloc(sizeof(int) * (size+1) ); // <==

			memcpy(tmp, score, sizeof(int)* size);

			free(score);
			score = tmp;
			size = size + 1; // <<== 
		}
	}
	free(score);
}
int main()
{
	CHRONOMETRY(ex1); // 메모리 부족시 "기존 크기의 2배" 로 키우는 모델
	CHRONOMETRY(ex2); // 메모리 부족시 "기존 크기 + 1 " 로 키우는 모델
}

// gcc(g++) : 많은 코드에서 2배 정도 증가 사용
// cl(ms컴파일러) : 많은 코드에서 1.5배 정도 증가 사용



