// explicit1.cpp
// C46.인자가 한개인 생성자는 explicit 로 하는 것이 좋다.

class Vector
{
public:
	// explicit 생성자 : 직접 초기화만 가능하고
	//					복사 초기화에는 사용할수 없다.
	explicit Vector(int sz) {}

	explicit Vector(const Vector& v) {}
};

void fn(Vector v) {} // "Vector v = 10" 로 인자를 받게 됩니다.
					 // "Vector v = v3" 의 경우는 "복사 생성자" 사용
					 // => 컴파일러가 제공한 복사 생성자는 explicit 아닙니다.

int main()
{
	// 인자가 한개인 생성자가 있으면 아래 4가지 형태로 객체 생성이 가능합니다
	// C++98
	Vector v1(10);		// 직접 초기화(direct initialization) : =이 없는것
//	Vector v2 = 10;		// 복사 초기화(copy initialization)   : =이 있는것

	// C++11 
	Vector v3{ 10 };	// 직접 초기화(direct initialization)
//	Vector v4 = { 10 }; // 복사 초기화(copy initialization)

	// 함수의 인자 전달은 복사 초기화 코드 입니다.
//	fn(10);
	fn(v3);
}