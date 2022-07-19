// nullptr 의 원리

void f1(int*  p) {}
void f2(char* p) {}

// 아래 코드가 nullptr 의 원리.
struct nullptr_t
{
	// 변환 연산자 함수 : 객체를 다른 타입으로 암시적 변환되게 하고 싶을때 사용
	// 특징 : 함수이름에 반환타입이 표기되어 있기 때문에, 별도로 반환타입을 표기안함
	template<typename T>
	operator T*() const { return 0; }	
};
nullptr_t mynullptr; // mynullptr 이 nullptr 의 원리..

int main()
{
	f1(mynullptr);	// nullptr_t ==> int* 로의 암시적 형변환이 필요 합니다
					// "mynullptr.operator int*()" 
	f2(mynullptr);
}

// nullptr 의 역사
// 1. boost 라이브러리에서 "위 코드 처럼" 구현해서 사용했었습니다.
// 2. C++11 에서 표준에 추가되면서, "키워드"로 되었습니다(위처럼 구현이 있는것은 아님)