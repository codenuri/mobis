// 2_file_format6-1.c

int main()
{
	char sa[] = "Hello"; // 문자열 자체가 stack. R/W 가능
	char* sp = "Hello";  // sp 는 stack. 문자열 자체는 .rdata 읽기만 가능

	*sp = 'X'; // runtime error
}