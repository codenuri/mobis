#include <iostream>
#include <algorithm>
#include <vector>

bool f1(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };
	
	// 1. 주어진 구간에서 3의 배수 찾기
	auto ret1 = std::find_if(v.begin(), v.end(), f1);

	int k = 0;
	std::cin >> k;

	// 핵심 : 주어진 구간에서 처음 나오는 k의 배수를 찾아 보세요!!!
	auto ret2 = std::find_if(v.begin(), v.end(), ?? );
}