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

	// [] 연산자 재정의  : 객체를 배열처럼 사용가능하게 합니다.
	// int  f1(){ return x;} 일때 f1() = 10 은 error
	// int& f2(){ return x;} 일때 f2() = 10 은 ok..

	// 즉, [] 연산자는 함수 호출이 =의 왼쪽에 놓일수 있어야 합니다.
	// reference return 을 사용해야 합니다.
	T& operator[](int idx) { return buff[idx]; }

};

int main()
{
	vector<int> v(10);

	v[0] = 10; // v.operator[](0) = 10; 으로 해석됩니다.
			  // 

	int a = v[0];
	std::cout << a << std::endl; // 10
}