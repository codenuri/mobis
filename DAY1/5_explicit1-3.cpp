#include <iostream>
#include <vector>

class Vector
{
public:
	explicit Vector(int sz) { std::cout << "Vector(int)" << std::endl; }
	Vector(std::initializer_list<int> s) { std::cout << "Vector(std::initializer_list)" << std::endl; }
};

int main()
{
	// 실행해서 결과 확인해 보세요.
	Vector v1(10); // 무조건 Vector(int) 생성자 호출

	Vector v2{10};  // 1. Vector(std::initializer_list)가 있으면 사용
					// 2. 없으면 Vector(int) 사용

//	Vector v3 = 10;		// error. explicit 생성자
	Vector v4 = { 10 };	// ok.    explicit 아님.

	// 왜!!! 이렇게 만들었나요 ?
	// => 생성자로 std::initializer_list 를 받으면 인자 갯수에 제한이없습니다.
	// => 그래서 아래 처럼 사용가능합니다
	Vector v5{ 1,2,3,4,5 };    // ok
	Vector v6 = { 1,2,3,4,5 }; // ok


	// 이해 되신 분은 아래 2줄 차이점이 뭘지 생각해 보세요
	std::vector<int> sv1(10, 3); // vector(int, int) 생성자
								 // => 10개 요소를 3으로 초기화

	std::vector<int> sv2{10, 3}; // vector(std::initializer_list) 생성자
								 // => 2개 요소를 10, 3으로 초기화
}
