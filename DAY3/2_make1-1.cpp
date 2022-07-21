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

	// 클래스 템플릿을 직접 사용하면 항상 코드가 복잡해 보입니다.
	List<std::pair<int, double>> s1(10, p); 

	// 하지만, 클래스 템플릿의 객체를 생성하는 함수 템플릿을 사용하면
	// 코드가 간결해 집니다.
	// => "Object Generator" 라고 불리는 기술
	auto s2 = make_list<std::pair<int, double>> (10, p); // 위와 동일한 의미.
	auto s3 = make_list(10, p);
}







