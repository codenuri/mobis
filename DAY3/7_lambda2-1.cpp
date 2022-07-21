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
	// => f1에서 main 의 지역변수인 "k" 사용할수 있어야 한다
	
	auto ret2 = std::find_if(v.begin(), v.end(), 

					"단항함수 + main함수의 지역변수인 k" );

	// 클로져(closure)
	// => 자신이 포함된 문맥의 지역변수를 캡쳐 해서 자신과 같이 전달가능한
	//    일급 함수
	// 일반 함수는 "클로져"가 될수 없지만 "함수객체" 는 클로져가 될수 있다.
}