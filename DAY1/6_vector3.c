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


		if ( count == size )
		{
			// #1. 기존 버퍼의 2배 크기 버퍼(배열) 할당
			int* tmp = (int*)malloc(sizeof(int) * size * 2);

			// #2. 작은 버퍼의 내용을 큰 버퍼로 이동
			memcpy(tmp, score, sizeof(int)* size);
					// => score 가 "가리키는 메모리 내용"을
					// => tmp 가 "가리키는 메모리로"
					// => sizeof(int)* size 만큼 복사

			// #3. 기존 버퍼 제거
			free(score);

			// #4. score 가 새로운 버퍼를 가리키도록
			score = tmp;

			// #5. 마지막 작업은 ? - size 변경
			size = size * 2;
		}
	}
	printf("할당한 메모리 크기 : %d\n", size);
	printf("입력한 요소의 갯수 : %d\n", count);

	// 더이상 필요없으면 버퍼 제거
	free(score);
}
// 실행해서 9개쯤 입력해 보세요. 1 2 3 .... 9
// 그리고 -1 입력

// 한글 문제 : chcp 65001

// 배열 : 한번 할당하면 크기를 변경할수 없습니다.

// 위처럼 크기를 계속 키워가면서 사용하는 기술을
// => "동적 배열" 또는 다른 말로 "vector" 라고 합니다.
// => Python 의 list 도 위와 거의 동일합니다.