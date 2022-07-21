// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// 동기화 자원을 직접 관리하면 "dead lock" 의 가능성이 있습니다.
// 생성자 소멸자로 관리해야 합니다
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

void foo()
{
	lock_guard<std::mutex> g(m);
//	m.lock();

	shared_data = 100;

//	m.unlock();
}



int main()
{

}