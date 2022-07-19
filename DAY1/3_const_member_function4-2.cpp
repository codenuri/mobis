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


	// 상수 vector 라도 int n = v2[0] 가 되어야 합니다.
	// operator[] 를 상수 멤버 함수로.. 
	// 그런데... 아래 main 결과 예측해 보세요
	T& operator[](int idx) const { return buff[idx]; }
};
int main()
{
	      vector<int> v1(10, 3); 
	const vector<int> v2(10, 3); 

	int n1, n2;

	// 아래 4줄을 보고 O, X 로 답해 보세요(에러가 발생하면 X)
	//		      원하는 것      현재 상태(문법적으로는)
	v1[0] = 10; // O            O
	v2[0] = 10; // X            O // <== 에러가 나지 않는 것이 문제 입니다.
	n1 = v1[0]; // O            O
	n2 = v2[0]; // O            O

	// v2자체는 상수지만 v2가 가진 버퍼는 상수가 아니므로
	// v2.buff[0] 를 T& 로 반환하면 v2[0] = 10 코드가 에러가 아닙니다.
}
