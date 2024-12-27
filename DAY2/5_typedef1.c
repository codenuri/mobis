// typedef 해석 방법
// typedef A B => B 는 A의 alias 이다. 라고 해석하면
//									  복잡한 typedef 를 해석할수 없습니다

typedef int DWORD;
typedef int ARR[2];

int main()
{
	DWORD n;
	ARR   a;
}
