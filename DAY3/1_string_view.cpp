#include <iostream>
#include <string>
#include <string_view>  // C++17 부터 지원되는 클래스 입니다.
						// 중요한 개념을 담고 있습니다.

int main()
{
	std::string s = "sfjsdjflsdjflsjlfks";

	// 핵심 : 아래 2줄의 차이점(메모리 그림)을 알아 두세요.
	std::string      ss = s; // 문자열 복사
	std::string_view sv = s; // s의 문자열을 가리키게 됩니다.

	ss[0] = 'A'; // ok.. ss 는 자신이 문자열 소유하므로 변경가능합니다.
	sv[0] = 'A'; // error. sv 는 s가 가진 문자열에 대한
				 //        읽기용 view 입니다. 쓰기는 안됩니다
	
}