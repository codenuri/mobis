// 5_explicit1-1
#include <iostream>
#include <string>
#include <vector>

void f1(std::vector<int> v) {}
void f2(std::string s) {}

int main()
{
	std::string s1("hello"); // 인자가 한개인 생성자가 있습니다.
	std::vector<int> v1(10); // 인자가 한개인 생성자가 있습니다.

	// 아래 2줄의 코드는 되는게 좋을까요 ? 안되는게 좋을까요 ?
	f1(10);			// ?
	f2("hello");	// ?
	
}