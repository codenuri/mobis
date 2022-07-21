#include <iostream>
#include <algorithm>
#include <vector>

struct IsMod
{
	int value;

	IsMod(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;

	auto ret1 = std::find_if(v.begin(), v.end(), IsMod(k));


	// C++11 부터는 함수객체를 간단히 만드는 문법이 제공됩니다.
	// 이것이 "람다 표현식" 입니다

	auto ret2 = std::find_if(v.begin(), v.end(), 
						[k](int n) { return n % k == 0; } );

	// 컴파일러는 위 한줄을 보고 아래 코드를 생성 합니다.
	class CompilerGeneratedName
	{
		int k;
	public:
		CompilerGeneratedName(int n) : k(n) {} 

		bool operator()(int n) const 
		{ 
			return n % k == 0; 
		}
	};

	auto ret3 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k) );
}