#include "chronometry.h"

// 반복문에서 함수 호출 제거

void bad()
{
	char s[] = "to be or not to be";

	// 아래 코드는 strlen() 함수가 문자열의 길이 만큼 호출됩니다.
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
			s[i] = '*';
	}
}

void good()
{
	char s[] = "to be or not to be";

	int sz = strlen(s);
	
	for (int i = 0; i < sz; i++)
	{
		if (s[i] == ' ')
			s[i] = '*';
	}
}

int main()
{
	bad();
	good();
}
