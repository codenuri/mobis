
// 다음중 좋은 코드는 ? (읽기만 하려고 합니다.)
void f1(int n)        {}
						// 내부 원리
void f2(const int& n)	// void f2(const int* p)
{						//
	int k = n;			// int k = *p;
}

// int 등의 primitive 타입은
// 1. 크기가 크지 않습니다.
// 2. 복사 생성자, 소멸자도 없습니다.
// 그리고, 참조 사용시
// 내부 원리는 결국 포인터 입니다.
// 그래서 "call by reference 보다 call by value"가 좋습니다.

// 핵심
// 1. 인자값을 변경해야 한다면
//  => 포인터 또는 참조 모두 좋습니다.(요즘은 참조가 더 많이 사용)
void inc1(int* p) { ++(*p); }
void inc2(int& r) { ++r; }

// 2. 인자값을 변경하지 않는 경우
// primitive type : call by value            void f1(int n)
// user type      : call by const reference  void f2(const Rect&)




