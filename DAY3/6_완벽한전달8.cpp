#include <iostream>
#include <string>
#include <vector>
class People
{
	std::string name;
public:
	// move 지원 setter 만들기 #1
	// => 2개의 함수 만들기 
//	void setName(const std::string& s) { name = s; }			// 1
//	void setName(std::string&& s) { name = std::move(s); }		// 2

	// 방법 2. forwarding reference 사용
	template<typename T> 
	void setName(T&& s)
	{
//		name = s; // 무조건 복사
//		name = std::move(s); // 무조건 move

		name = std::forward<T>(s);	// setName() 사용시
									// rvalue를 보냈으면 rvalue 캐스팅 => move 호출
									// lvalue를 보냈으면 lvalue 캐스팅 => copy 호출
	}

	// 그런데, 이 예제에서는 1번이 좋습니다.
	// => 인자가 std::string 버전만 있으면 됩니다.
};


int main()
{
	std::string s = "john";

	People p;
	p.setName(s);				// 1번 호출
	p.setName(std::move(s));	// 이 코드는 위 함수에서 1, 2로 모두 전달될수 있지만
}



