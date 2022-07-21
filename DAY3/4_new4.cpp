#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point 는 디폴트 생성자가 없습니다.
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// 컨테이너 만들때, 저장할 타입에 대한 요구조건을
// 1. "디폴트 생성자가 있어야 한다" 라고 하지 말고
// 2. "복사 생성자가 있어야 한다" 라고 하자.
// => 최소의 조건을 요구하는 것이 좋다.
// => "Generic Container Idioms" 라는 이름을 가진 개념
// => "STL 설계시 적용한 철학"


// STL vector 의 구현을 생각해 봅시다.
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
//		buff = new T[size]; // 이렇게 하면 T가 반드시 "디폴트 생성자가 있어야 한다"
					        // 는 제약조건을 가지게 됩니다.

		// 그래서, 실제 vector는 아래 처럼 구현되어 있습니다.
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
//			new(&buff[i]) T;		// 이 코드는 디폴트 생성자 호출.
			new(&buff[i]) T(value); // 이 코드는 복사 생성자 호출.
		}
	}
	~vector()
	{

	}
};
int main()
{
//	vector<Point> v(10); // error
	vector<Point> v(10, Point(0,0)); // 디폴트 생성자가 없는 타입을 보관할때는
									// 반드시, 초기화에 사용할 객체 전달

}