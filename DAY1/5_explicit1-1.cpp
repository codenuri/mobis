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
	f1(10);			// 안되는게 좋다.  그래서 error 입니다. 
	f2("hello");	// 되는게 좋다.    그래서 ok..

	// 그렇다는 이야기는
	std::vector<int> v2 = 10; // 안됩니다. explicit 생성자
	std::string s2 = "hello"; // 됩니다.  explicit 아님. 

	// vector v1(10)는 되는데, vector v1 = 10 이 안되면 
	// explicit 생성자라고 생각하세요
	
}