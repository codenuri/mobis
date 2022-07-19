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
};

int main()
{
	vector<int> v(10);

	v[0] = 0; 

	int a = v[0];
}