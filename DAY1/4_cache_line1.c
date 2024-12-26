// 105 page
#include "chronometry.h"

#define count 10000

// #1. 2차원 배열!
int arr[count][count]; // 10000*10000 2차원 배열

// #2. 배열의 모든 요소를 순차(메모리에 놓인 순서로 접근)
void ex1()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			arr[i][j] = 0;
		}
	}
}

// #3. 배열의 모든 요소를 순차적이지 않은 방식으로 접근
void ex2()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			arr[j][i] = 0; // <= [i][j] 가 아닌 [j][i]
		}
	}
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}
