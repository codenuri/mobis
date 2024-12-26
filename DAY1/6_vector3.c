#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	// 4. 사용자가 -1을 입력할때 까지 계속 입력 받고 싶습니다.
	//    단, 입력된 모든 값은 보관되어 있어야 합니다.
	int n = 0;

//	int score[4];	// 이렇게 하면 필요 없을때 제거할수 없습니다.
					// 지역변수의 수명이 개발자가 제어할수 없음.

	int size = 4;

	int* score = (int*)malloc(sizeof(int)*size);

	int count = 0;

	while (1)
	{
		scanf("%d", &n);

		if (n == -1)
			break;

		score[count++] = n;
	}

}


