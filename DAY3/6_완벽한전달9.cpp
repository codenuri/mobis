#include <iostream>
#include <string>
#include <type_traits>

class People
{
	std::string name;
	std::string addr;
public:
	/*
	// 아래 생성자는 C++98 이라면 완벽한 코드입니다
	People(const std::string& name, const std::string& addr) : name(name), addr(addr)
	{
		std::cout << "ctor 1" << std::endl;
	}

	// 하지만 C++11의 move를 지원하려면 3개가 더 필요..
	People(std::string&& name, const std::string& addr) : name(std::move(name)), addr(addr)
	{
		std::cout << "ctor 2" << std::endl;
	}
	People(const std::string& name, std::string&& addr) : name(name), addr(std::move(addr))
	{
		std::cout << "ctor 3" << std::endl;
	}
	People(std::string&& name, std::string&& addr) : name(std::move(name)), addr(std::move(addr))
	{
		std::cout << "ctor 4" << std::endl;
	}
	*/

	// 위처럼 직접 만들면 너무 많은 함수를 만들어야 합니다.
	// 이때 forwarding reference를 사용합니다.
	/*
	template<typename T1, typename T2>
	People(T1&& s1, T2&& s2)
		: name(std::forward<T1>(s1)), addr(std::forward<T2>(s2))
	{
	}
	*/

	// 아래 처럼하면 T1, T2를  string으로 한정할수 있습니다.
	template<typename T1, 
		     typename T2,
			 typename = std::enable_if_t< 
					std::is_constructible_v<std::string, T1> && 
					std::is_constructible_v<std::string, T2> > >
	People(T1&& s1, T2&& s2)
		: name(std::forward<T1>(s1)), addr(std::forward<T2>(s2))
	{
	}

};

int main()
{
	std::string s1 = "john";
	std::string s2 = "seoul";

	People p1(s1, s2); 
	People p2(std::move(s1), s2); 
	People p3(s1, std::move(s2)); 
								  
	People p4(std::move(s1), std::move(s2));

}