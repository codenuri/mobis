#include <stdio.h>

int main()
{
	int cnt = 0;

	printf("학생수를 입력해 주세요 >> ");
	scanf("%d", &cnt);

	// 3. 실행시간에 입력된 학생수 만큼 다시 점수를 입력 받아야 합니다.
 //	int score[cnt];  // 배열의 크기로, 변수를 사용 ?? 
					 // 가능합니다.
					 // 그런데, 일부 컴파일러는 안되므로
					 // 모든 컴파일러에 호환되는 코드가 필요하면 malloc 으로 해야 합니다.
	int* score = (int*)malloc(sizeof(int) * cnt);

	free(score);
}



// 배열의 크기로 변수 사용
// C89 문법 : 안됨
// C99 문법 : 가능.. 
// 단, gcc(clang) 는 지원하는데, visual studio(cl.exe) 지원 안됨.
