#include <iostream>
#include <string>

// 규칙 1. 사용자가 복사 계열과 move 계열 함수를 모두 만들지 않으면
//        컴파일러가 모두 제공한다.
// => 컴파일러 제공 복사 생성자는 모든 멤버데이타를 복사해준다.
// => 컴파일러 제공 이동 생성자는 모든 멤버데이타를 이동(move) 해준다.


// 규칙 2. 사용자가 복사계열만 제공하면
// => 컴파일러는 move 계열을 제공하지 않는다.
// => std::move() 사용시 사용자가 만든 "복사 생성자" 사용

// 이때 move 기능이 필요하면
// 1. move 생성자를 직접 만들거나
// 2. "=default"로 요청하면 된다.  <== 권장, trivial 하므로!!


// 규칙 3. 사용자가 move 계열만 제공하면
// => 복사 계열 함수는 "삭제(=delete)" 됩니다.
// => 복사 계열 함수를 사용하는 코드 가 있으면 컴파일 에러

// => 역시 이경우도 "=default" 로 복사 생성자를 만들어 달라고 
//    요청할수 있습니다.

class Object
{
public:
	std::string name = "kim";
	Object() = default;

	// 복사만 만들고, 나머지는 컴파일러에게 요청하는 코드
//	Object(const Object& obj) : name(obj.name) { std::cout << "copy" << std::endl; }
//	Object(Object&& obj) = default;
//	Object& operator=(Object&&) = default;      // move 대입
//	Object& operator=(const Object&) = default; // copy 대입

	Object(Object&& obj) : name(std::move(obj.name)) 
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object obj1;
	Object obj2;
	Object obj3 = obj1;
	Object obj4 = std::move(obj2);
	
	std::cout << obj1.name << std::endl;  // "kim"
	std::cout << obj2.name << std::endl;  // ""
}