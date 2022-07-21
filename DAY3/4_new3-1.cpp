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
	
	std::cout << "-------------" << std::endl;
}