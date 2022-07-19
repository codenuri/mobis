#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error.. 
							  // explicit vector(int size) 라는 의미

	std::vector<int> v3{ 10 };	 // ok
	std::vector<int> v4 = { 10 };// ok .. 이건 왜.. 되나요 ?
		
}