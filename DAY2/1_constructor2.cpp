#include <iostream>

// C.47: Define and initialize member variables 
//       in the order of member declaration

// 아래 클래스는 어떤 문제가 있을까요 ?
struct vector
{
	int* buff;
	int size;
public:
	// 생성자의 초기화 리스트 실행 순서는, 코드가 놓인 순서가 아닙니다.
	// 멤버 데이타가 선언된 순서로 초기화 됩니다
	// 즉, 아래 코드에서 (1)이 먼저 실행됩니다. 이경우, size 값은 초기화 안되었습니다
	//					(2)		        (1)
//	vector(int sz) : size(sz),          buff(new int[size])
	vector(int sz) : buff(new int[sz]), size(sz)
	{
	}
	~vector()
	{
		delete[] buff;
	}
};

int main()
{
	vector v(10);
}