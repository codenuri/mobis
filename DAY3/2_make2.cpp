#include <iostream>
#include <tuple>
#include <vector>

int main()
{
	std::pair<int, double> p1(3, 3.4);
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4);


	// STL 에는 수많은 make_xxx() 함수가 제공됩니다.
	auto p2 = std::make_pair(3, 3.4);		   // 위 p1과 동일
	auto t2 = std::make_tuple(3, 3.4, 3, 3.4); // 위 t1과 동일

	// 그런데, 이 기술이 C++17 부터는 없어도 됩니다.
	std::pair p3(3, 3.4);
	std::tuple t3(3, 3.4, 3, 3.4);

	std::vector v = { 1,2,3,4 }; // ok.. C++17 부터는 타입인자 없어도 됩니다.

}