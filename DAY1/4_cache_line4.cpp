// 성능 이야기가 아닌 멀티스레드의 어려움을 보여주는 코드.
// => foo(), goo() 는 다른 스레드가 실행합니다.
// => goo() 의  주석 생각해 보세요
// cache 와 reorder

int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;

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
// godbolt.org 에 위 코드 넣어 보세요





