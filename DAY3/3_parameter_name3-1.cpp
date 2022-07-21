// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// lock 을 수행 하는 생성자와
// lock 을 수행 하지 않는 생성자가 필요 하다.

// 방법 1. bool 변수 사용

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m, bool b = true ) : mtx(m) 
	{
		if ( b ) mtx.lock();
	}

	~lock_guard() { mtx.unlock(); }
};


void foo()
{
	if (m.try_lock())
	{
//		lock_guard<std::mutex> g(m); // 생성자에서 lock 수행
		lock_guard<std::mutex> g(m, false); // 생성자에서 lock 수행 안함
	}

}



int main()
{

}