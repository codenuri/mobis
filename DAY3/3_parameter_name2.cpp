// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// 동기화 자원을 직접 관리하면 "dead lock" 의 가능성이 있습니다.
// 생성자 소멸자로 관리해야 합니다

// RAII ( Resouce Acquision Is Initialization)
// 자원을 획득(lock) 하는 것은 "자원 관리객체"가 초기화 될때 이다.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

void foo()
{
	{
		// 위와 같은 lock_guard 가 이미 표준에 있습니다. ( C++11에서 추가)
		std::lock_guard<std::mutex> g(m);

//		lock_guard<std::mutex> g(m); // g의 생성자에서 m.lock 수행
									 // => 블럭 벗어날때 g 가 파괴될때 소멸자에서 unlock	
	//	m.lock();

		shared_data = 100;

		// 예외 발생시..
		// => catch 로 이동.. 
		// => 단, 이동전에 지역변수는 안전하게 파괴된다.(stack unwinding(풀기))
		// => g의 소멸자가 호출되므로 unlock 을 수행하게 된다.

	//	m.unlock();
	}

	//...
}





int main()
{

}