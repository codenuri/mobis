// 4_new3-1
#include <iostream>
#include <vector>

class DBConnect
{
public:
	DBConnect() { std::cout << "connect DB" << std::endl; }
	~DBConnect() { std::cout << "close DB" << std::endl; }
};

int main()
{
	std::vector<DBConnect> v(5);

	std::cout << "-------------" << std::endl;
	
	v.resize(3); // 이 순간을 생각해 보세요
				// 이순간, 버퍼(메모리)는 제거되지 않습니다.
				// 하지만, 줄어든 2개의 객체에 대해서는 소멸자를 호출합니다.	
				// 메모리 해지 없이 소멸자만 호출하는 코드가 필요 합니다.
				// buff[4].~DBConect()  같이 호출.
	
	std::cout << "-------------" << std::endl;

	v.resize(4); // 늘어난 한개를 위한 메모리 공간은 있습니다.
				 // 그래서, 추가 메모리 할당은 없지만
				 // 기존 메모리 공간에 대한 "생성자 호출"이 필요

	std::cout << "-------------" << std::endl;

}