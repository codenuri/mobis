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

	// [] 연산자 재정의의 특징
	// => 상수 객체와 상수 객체가 아닌경우를 모두 고려해야 합니다.

	// 상수 객체가 아닌 경우를 위한 [] 연산자
	// => Write : "v[0] = 10"  
	// => Read  : "n = v[0]"  
	// 이 모두 가능해야 합니다. reference 반환이 핵심

	T& operator[](int idx) { return buff[idx]; }

	// 상수 객체를 위한 [] 연산자
	// => Write : "v[0] = 10"    <== 에러
	// => Read  : "n = v[0]"	 <== 에러 아님

	// 즉, 함수 호출을 등호의 왼쪽에 놓을수 없어야 합니다.
//	T        operator[](int idx) const { return buff[idx]; }
	const T& operator[](int idx) const { return buff[idx]; }

	// 반환 타입에 따른 차이
	// T : return by value 입니다. 
	//     임시객체 생성되어 반환, 임시객체는 rvalue 입니다.
	//	   임시객체는(rvalue) 는 주소 연산자로 주소를 구할수 없습니다.
	//     "&v[0]" 표기법 안됩니다.

	// const T& : return by reference 입니다.
	//			  임시객체 생성 안됩니다. 따라서 효율적이고 성능이 좋습니다.
	//		      T& 로 하면 쓰기도 되므로
	//            const 를 붙여서 의도적으로 Write 를 되지 않게 하고 있습니다
};





int main()
{
	vector<int> v1(10, 3);
	const vector<int> v2(10, 3);

	int n1, n2;

	//		      원하는 것      현재 상태(문법적으로는)
	v1[0] = 10; // O            O
//	v2[0] = 10; // X            X 
	n1 = v1[0]; // O            O
	n2 = v2[0]; // O            O

	const int* p = &v2[0];	// 되는 것이 좋을까요 ? 안되게 하는게 좋을까요 ?
						// vector 는 배열 대신 사용하기 위한 도구 입니다.
						// 1번째 요소의 주소를 구할수 있어야 합니다.
						// 실제 표준 vector 도 이 코드 가능합니다.
}
