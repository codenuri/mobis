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
	      vector<int> v1(10, 3); 
	const vector<int> v2(10, 3);

	int n1, n2;

	// 아래 4줄을 보고 O, X 로 답해 보세요(에러가 발생하면 X)
	//		      원하는 것      현재 상태
	v1[0] = 10;
	v2[0] = 10;
	n1 = v1[0];
	n2 = v2[0];
}

//4번 복사해서 4-1 번 만드세요..