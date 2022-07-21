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

	bool b = f(10); // 10 이 k의 배수인지 조사.. false

	auto ret2 = std::find_if(v.begin(), v.end(), f);


	auto ret3 = std::find_if(v.begin(), v.end(), f1); // 함수만 전달

	auto ret4 = std::find_if(v.begin(), v.end(), IsMod(k) ); // 임시객체로전달
										//=> k를 캡쳐한 단항 함수객체


}