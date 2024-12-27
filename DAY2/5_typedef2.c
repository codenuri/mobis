
int n;			// n 은 int 타입의 "변수" 입니다.
int a[2];		// a 는 int[2] 타입의 배열 "변수" 입니다.
int b[2][2];	// b 는 int[2][2] 타입의 배열 "변수" 입니다.
void (*f)();	// f 는 함수 포인터 타입의 "변수" 입니다.

// typedef : 변수 위치의 심볼을 "타입" 으로 만들어 달라 
// => 변수를 선언하는 문장의 앞에 놓여서, 변수가 아닌 타입을 선언하는 것 
typedef int n;			// n 은 int 타입의 "타입" 입니다.
typedef int a[2];		// a 는 int[2] 타입의 배열 "타입" 입니다.
typedef int b[2][2];	// b 는 int[2][2] 타입의 배열 "타입" 입니다.
typedef void (*f)();	// f 는 함수 포인터 타입의 "타입" 입니다.

int main()
{
	a x;  // int x[2];
	b y;  // int y[2][2];
}

