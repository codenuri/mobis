#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	// 4. 사용자가 -1을 입력할때 까지 계속 입력 받고 싶습니다.
	//    단, 입력된 모든 값은 보관되어 있어야 합니다.
	int n = 0;

	int score[4];
	int count = 0;

	while (1)
	{
		scanf("%d", &n);

		if (n == -1)
			break;

		score[count++] = n;
	}

}


