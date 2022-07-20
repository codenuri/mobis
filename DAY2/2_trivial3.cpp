#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;

	Point() = default;

	Point(int a, int b) : x(a), y(b) {}

	// 사용자가 복사 생성자를 제공하면
	// trivial 하지 않습니다.( 모든 멤버를 얕은 복사를 해도.. )
	// => 아래 코드는 컴파일러가 생성하는 것과 동일한 모양입니다.
	// => 하지만 사용자가 제공했으므로 trivial 하지 않습니다.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};



template<typename T> 
void copy(T* dst, T* src, std::size_t size)
{
	if (std::is_trivially_copy_constructible<T>::value)
	{
		// 배열 전체 복사는 "memcpy" 가 빠릅니다.
		std::cout << "using memcpy" << std::endl;
		memcpy(dst, src, sizeof(T) * size);
	}
	else
	{
		std::cout << "복사생성자가 trivial 하지 않는경우" << std::endl;

		while (size--)
		{
			new(dst) T(*src); // 한개씩 복사 생성자로 이동
							  // 이 코드는 오후에 설명
			++dst, ++src;     
		}
	}
}

int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];

	copy(pt2, pt1, 5);

}