#include <iostream>
#include <algorithm>
#include <vector>

bool f1(int n) { return n % 3 == 0; }

struct IsMod
{
	int value; // 핵심.. 값 보관 가능

	IsMod(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0; // 자신이 보관하던 value 로 나누어 떨어지는가 ?
	}
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;
	IsMod f(k); // k를 캡쳐한 단항 항수
	auto ret2 = std::find_if(v.begin(), v.end(), f);
}