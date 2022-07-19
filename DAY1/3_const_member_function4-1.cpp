#include <iostream>

// STL vector를 흉내낸 클래스르 생각해 봅시다.
template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz, int value = 0) : buff(new T[sz]), size(sz)
	{
		for (int i = 0; i < sz; i++)
			buff[i] = value;
	}
	~vector() { delete[] buff; }


	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	      vector<int> v1(10, 3); // R/W 가 가능한 동적 배열
	const vector<int> v2(10, 3); // R 만 가능한 동적 배열
								 // => 물리적으로는 v2가 상수지만
								 // => 버퍼를 상수 처럼 생각하겠다는것

	int n1, n2;

	// 아래 4줄을 보고 O, X 로 답해 보세요(에러가 발생하면 X)
	//		      원하는 것      현재 상태(문법적으로는)
	v1[0] = 10; // O            O
	v2[0] = 10; // X            X
	n1 = v1[0]; // O            O
	n2 = v2[0]; // O            X   <== 이 부분이 문제!!
}

//4번 복사해서 4-1 번 만드세요..