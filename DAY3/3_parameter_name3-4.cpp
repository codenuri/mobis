#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

void foo()
{
	if (m.try_lock())
	{
		// 앞에서 만든 모든 내용은 "C++표준"에 이미 있습니다.
		// "std::lock_guard" 선택후 오른쪽 버튼 누르고 "정의로 이동"해 보세요
		std::lock_guard<std::mutex> g(m, std::adopt_lock);
	}
}

int main()
{

}