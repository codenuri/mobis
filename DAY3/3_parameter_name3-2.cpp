// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// 방법 2. tag dispatch 를 사용

// 단지 함수 오버로딩에 사용할 목적으로 타입이 필요할때는 "empty class" 기술
// 을 사용합니다.
// "empty class" : 아무 멤버도 없는 클래스, 크기는 1 바이트
//				   아무 멤버도 없지만 독립된 타입이므로 함수 인자로 사용가능
struct adopt_lock_t {};
adopt_lock_t adopt_lock;

template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m)			    : mtx(m) { mtx.lock(); }

	// 아래 코드의 2번째 인자는 실제 전달이 목표가 아닙니다.
	// 단지, 이 생성자 함수를 선택하기 위한 목표 입니다.
	// 이때는 함수 인자의 "이름을 생략"하는 것이 좋은 코드 입니다.
	lock_guard(T& m, adopt_lock_t ) : mtx(m) {  }
	~lock_guard() { mtx.unlock(); }
};

void foo()
{
	if (m.try_lock())
	{
		//	lock_guard<std::mutex> g(m); // 생성자에서 lock 수행
		lock_guard<std::mutex> g(m, adopt_lock); // 생성자에서 lock 수행 안함
	}

}



int main()
{

}