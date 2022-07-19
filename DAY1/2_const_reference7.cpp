#include <iostream>
#include <string>
#include <vector>

class People
{
	std::string name;
public:
	// setter 나 생성자만 move를 지원하면 됩니다.
	void setName(const std::string& s) { name = s; }  // 1
	void setName(std::string&& s) { name = std::move(s); } // 2

	// 단순히 읽기만 하는 인자는 move지원 필요 없습니다.
	// 아래 함수는 한개만 만들면 됩니다.
	void print(const std::string& s) 
	{
		std::cout << s << std::endl; 

		// 인자 s 를 다른 곳에 복사 할때는 move개념을 지원하면됩니다.
		// "name = s" 같은 코드가 있을때만
	}
};

int main()
{
	std::string s1 = "john";
	std::string s2 = "john";

	People p;
	p.setName(s1);			

	p.setName(std::move(s2));

	p.print(s1); // s1의 자원을 복사하거나 하지않고
				// 그냥 한번읽기만 하는 코드 입니다.
	p.print(std::move(s1)); // 에러 없습니다.
							// 하지만 print 는 전달받은 객체를
							// 다른 곳에 복사 하는 작업을 하지는 않습니다.
							// 그러므로 move 효과는 없습니다.
							

}

