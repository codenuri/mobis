#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v(10);

	v.resize(7); // 구현 원리를 생각해 봅시다.

	std::cout << v.size() << std::endl; // 7
	std::cout << v.capacity() << std::endl; // 10 

	v.resize(8);	// 현재는 capacity > 8 이므로 
					// 메모리 재할당 필요 없습니다.

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10 

	v.shrink_to_fit(); // size==capacity로 해달라는 것

	std::cout << v.size() << std::endl; // 8
	std::cout << v.capacity() << std::endl; // 10 

}
