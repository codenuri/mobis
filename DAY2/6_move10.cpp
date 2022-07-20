#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}

	Object(const Object&) 
	{	
		std::cout << "copy" << std::endl;	
	}
	// move 생성자를 만들때는
	// 1. 되도록 예외가 발생하지 않게 만들고
	// 2. 예외가 없다는 사실을 컴파일러에게 알려주세요
	
	// 함수() noexcept : 함수가 예외가 없음을 컴파일러에게 알리는 것
	// move 생성자가 아니라도, 
	// "함수가 예외 가능성이 없다면, noexcept" 를 붙이면 좋습니다.(최적화가 잘됩니다.)
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 항상 복사 생성자
	Object o3 = std::move(o1); // 항상 move 생성자
								// noexcept 유무에 상관없이
	Object o4 = std::move_if_noexcept(o2); 
					// move 생성자에 예외가 없다면(noexcept 가 붙었다면) move생성자
					// noexcept 가 붙어 있지 않으면 복사 생성자
	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

