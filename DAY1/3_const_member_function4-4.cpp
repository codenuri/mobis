#include <iostream>

// STL vector를 흉내낸 클래스르 생각해 봅시다.
template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz, int value = 0);
	~vector();

	      T& operator[](int idx); 
	const T& operator[](int idx) const;
};
// 핵심 1. 상수 멤버 함수는 "선언과 구현" 모두에 const 를 붙여야 합니다.

//     2. 함수 인자의 디폴트값은 선언부에만 표기해야 합니다.

//     3. 클래스 템플릿의 멤버 함수 외부 구현시 
//        "vector::" 가 아니라 "vector<T>::" 입니다.

template<typename T>
vector<T>::vector(int sz, int value /*= 0*/) : buff(new T[sz]), size(sz)
{
	for (int i = 0; i < sz; i++)
		buff[i] = value;
}
template<typename T>
vector<T>::~vector()
{
	delete[] buff; 
}
template<typename T>
T& vector<T>::operator[](int idx)
{
	return buff[idx]; 
}
template<typename T>
const T& vector<T>::operator[](int idx) const
{
	return buff[idx]; 
}




int main()
{
	vector<int> v1(10, 3);
	const vector<int> v2(10, 3);

	int n1, n2;

	v1[0] = 10; 
//	v2[0] = 10; // error
	n1 = v1[0]; 
	n2 = v2[0]; 
}
