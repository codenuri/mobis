#include <atomic> // C++헤더

int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;

    // 해결책은 메모리 펜스를 설치 해야 합니다
    // C언어 : 기계어 직접 사용
    // C++  : 표준 라이브러리리로 제공.
    std::atomic_thread_fence( std::memory_order_seq_cst);

	b = 1;
}

// thread B
void goo()
{
    if (b == 1)
    {
        // a == 1 을 보장할수 있을까 ? <<== 핵심
    }
}
