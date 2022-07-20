#include <string>

class People1
{
	std::string name;
	int age;
public:
	People1(const std::string& s, int a) 
		: name(s), age(a)	// <= name 의 생성자를 호출하는 코드를 
							//    사용자가 직접 작성했으므로
							//    컴파일러가 추가 안함
	{
	}
};

class People2
{
	std::string name;
	int age;
public:
	// 사용자 코드						 // 컴파일러가 추가한것
	People2(const std::string& s, int a) // : name()   <= 1. 생성자 호출
	{
		name = s;	// 대입.  <= 2. 대입연산자 호출 name.operator=(s)
		age = a;
	}
};
// People2 p2("kim", 20)





int main()
{
	std::string s = "john";

	People1 p1(s, 20);
	People2 p2(s, 20);


	// 초기화 vs 대입
	// primitive type : 거의 유사한 기계어 코드 생성
	// user define type : 초기화가 빠릅니다(한번의 함수 호출)
	int a = 20;		// 초기화. 만들면서 넣는것 

	int b;
	b = 20;			// 대입. 만든후에 넣는것

	
	std::string s1 = "kim";	// 초기화. 인자가 한개인 생성자 호출
							// => 즉, 한번의 함수 호출로 객체 초기화

	std::string s2;	// 1. 디폴트 생성자 호출
	s2 = "kim";		// 2. 대입연산자 호출 ( s2.operator=("kim"))	
					// 즉, 2번의 함수 호출로 객체에 값을 넣은것
}