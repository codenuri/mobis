#include <iostream>
#include <algorithm>
#include <vector>

bool f1(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	// 주어진 구간에서 "3" 찾기
	auto ret1 = std::find(v.begin(), v.end(), 3);

	// 주어진 구간에서 1번째 나오는 "3의 배수" 찾기
//	auto ret2 = std::find_if(v.begin(), v.end(), 함수(인자가한개인) );
	auto ret2 = std::find_if(v.begin(), v.end(), f1 );

}