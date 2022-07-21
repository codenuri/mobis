#include <iostream>

template<typename T> class List
{
public:
	List(int sz, T value) {}
};

// List 를 생성하는 함수 템플릿
template<typename T> 
List<T> make_list(int sz, const T& value)
{
	return List<T>(sz, value);
}

int main()
{
	std::pair<int, double> p(1, 3.4);

	List<std::pair<int, double>>   s3(10, p); 

	auto s = make_list(10, p); // 위와 동일한 의미.
}







