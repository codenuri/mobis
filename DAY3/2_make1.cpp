#include <iostream>

// T44. Use function templates to deduce class template argument types
// => STL 에서 아주 많이 사용.

template<typename T> T square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};



int main()
{
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3); // 정확한 표기법
					// => 타입 인자를 직접 전달하는 경우. 

	square(3);	// 사용자가 타입 인자를 생략하면 
				// 함수 인자를 보고 타입을 추론하게 됩니다.
				// "3"을 전달했으므로 T=int 로 추론.

	List<int> s1(10, 3); // ok.  10개를 3으로 초기화 하겠다는 의도..
	List      s2(10, 3); // C++17 부터 가능.
						 // C++14 까지는 에러

	// 함수 템플릿의 타입 추론              : C++98 부터 가능
	// 클래스 템플릿 타입 추론(생성자를 통한) : C++17 부터 가능

	// 클래스 템플릿은 타입 추론이 안되었기 때문에 복잡한 코드가 많았습니다.
	std::pair<int, double> p(1, 3.4);


	// pair 10개를 보관하는 List 를 만들고 싶습니다.
	// => 컴파일러는 p가 std::pair<int, double> 라는 것을 알지만
	// => C++14까지는 타입을 표기해야 하므로 아래 처럼 복잡해 집니다.
	List<std::pair<int, double>>   s3(10, p); // 10 개를 p로 초기화 해달라.
		

}







