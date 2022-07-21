// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// 아래 함수가 2개 이상의 스레드에 의해 실행된다고 가정해 봅시다.
void foo()
{
	m.lock();

	shared_data = 100;

	// 예외 발생..
	// => catch 로 이동하게 되는데, unlock 을 하지 않고 이동하게 되므로
	// => 대기 중인 스레드는 "깨어날수 없습니다."
	m.unlock();
}


int main()
{

}