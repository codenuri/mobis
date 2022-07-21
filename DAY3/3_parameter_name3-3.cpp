// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;


// 아래처럼 하면 컴파일러가 디폴트 생성자를 제공하는데
// => 디폴트 생성자가 explicit 가 아닙니다.
// struct adopt_lock_t {}; 

// 많은 개발자가 아래 코드를 보고 "왜 아무일도 하지 않은 생성자를 만드나요 ?"
// 안만들면 컴파일러가 제공하지 않나요 ??? 라는 질문을 합니다.
// => explicit 때문에.. 
struct adopt_lock_t
{
//	explicit adopt_lock_t() {} // 이렇게 하면 생성자가 trivial 하지 않습니다.
	explicit adopt_lock_t() = default; // 이렇게 하면 trivial 합니다.
};
// 되도록 이면 객체는 "상수"로 만들어라..
// => 멀티스레드 관련 코드에서 효율적인 기계어 코드 생성등의 장점.
// adopt_lock_t adopt_lock; // 이코드보다
constexpr adopt_lock_t adopt_lock; // 이코드가 좋습니다


void foo( adopt_lock_t )
{
}

int main()
{
	// adopt_lock : lock 을 이미 했다고 알려주는 주석의 효과
	foo(adopt_lock); // ok. 
	foo({}); // 되는게 좋을까요 ? 안되는게 좋을까요 ?
			 // adopt_lock_t 객체 = {}
}