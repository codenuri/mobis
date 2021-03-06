// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

void foo()
{
//	lock_guard<std::mutex> g(m); // 생성자에서 m.lock() 수행

	// mutex 를 획득(lock)하는 것은 여러가지 방법이 있습니다.
//	m.lock();		// 획득하지 못하면 대기
//	m.try_lock();	// 획득하지 못하면 대기하지 않고 false 반환

	if (m.try_lock())
	{
		// m의 lock 은 직접 했지만(try_lock)
		// unlock 은 lock_guard 를 활용하고 싶다.

		lock_guard<std::mutex> g(m);// 그런데, 생성자에서 또 lock 하게된다.
									// 현재, m은 이미 lock 획득
									// lock 을 하지 않는 생성자가 필요하다
		//.....

//		m.unlock(); // unlock 을 직접 사용하면 예외등 다양한 문제가 있습니다.
	}

}



int main()
{

}