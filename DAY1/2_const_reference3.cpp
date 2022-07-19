#include <iostream>

struct Rect
{
	int left, top, right, bottom;
};

void f1(Rect& rc)       {}
void f2(const Rect& rc) {}

int main()
{
	Rect rc;
	f1(rc); // ok
	f2(rc); // ok

	f1(Rect()); // error
	f2(Rect()); // ok  

	// 핵심 : const 가 있어야 임시객체를 받을수 있습니다.
}