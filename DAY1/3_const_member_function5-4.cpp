#include <iostream>
#include <vector>

template<typename T>
class RefCount
{
	mutable int refcnt = 0;
public:
	~RefCount() { std::cout << "~RefCount" << std::endl; }

	// 참조계수 관련 멤버 함수는 일반적으로 "상수 멤버 함수"로 하게 됩니다.
	// => 상수 객체도 수명관리 가능해야 합니다.
	void AddRef() const { ++refcnt; }

//	void Release()			// void Release(RefCount* this)
//							// 즉, this가 const 가 아닙니다.

	void Release() const	// void Release(const RefCount* this)		
	{						// 즉, this가 const를 가리키는 포인터 입니다

	//	멤버변수 = 10;        // this->멤버변수 = 10 인데
							 // this가 const 를 가리키는 포인터 이므로 에러

		if (--refcnt == 0)
			//delete static_cast<T*>(this); 
					// const RefCount* => Truck* 로 변환.. 
					//				그런데 static_cast 는 const 제거가 안됩니다.

//			delete static_cast<T*>(const_cast<RefCount*>(this));
					// const RefCount* => RefCount* 캐스팅후
					// RefCount* => Truck*          캐스팅

			delete static_cast<const T*>(this);
					// const RefCount* => const Truck* 로 캐스팅
					// 즉, const 는 유지하면서 타입만 변경
	}
};





class Truck : public RefCount< Truck  >
{
	int speed;
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	// 아래 코드를 생각해 봅시다.
	// => p를 통해서는 객체를 "Read" 만 하겠다는 의도.
	// => 읽기만 한다면 아래처럼 "const" 를 붙이는 것은 아주 좋은 코딩 스타일입니다.
	const Truck* p = new Truck;

	// 상수 객체라도 수명관리가 되어야 합니다.
	// => 아래 2개의 함수는 반드시 "상수 멤버 함수" 로 해야 합니다.
	p->AddRef();
	p->Release();
}


