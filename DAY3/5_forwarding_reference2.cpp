// forwarding_reference1 - 아주 아주 중요!!

void f1(int&  r) {}
void f2(int&& r) {}

int n = 0;
f1(n);	// ok
f1(10); // error

f2(n);	// error
f2(10);	// ok.. 

// 함수 인자로
// int&  : int 타입의 lvalue 만 받겠다는 의도
// int&& : int 타입의 rvalue 만 받겠다는 의도
// 
// T&  :  ? 핵심 !
// T&& :  ? 핵심 !   <= T=int&, T=int&& 등에 따라서 달라집니다.


template<typename T> void f3(T& a)
{
}

template<typename T> void f4(T&& a)
{
}
