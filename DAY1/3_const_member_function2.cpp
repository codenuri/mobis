// 상수 멤버 함수는 "선택"이 아닌 필수 문법 입니다.

// 객체의 상태를 변경하지 않은 모든 멤버 함수(getter) 는 "반드시" "상수 멤버함수"
// 가 되어야 합니다.

// 아래 코드에서 "getArea()" 로 만들면 틀린 코드 입니다.
//             "getArea() const" 가 되어야 합니다.

// 멤버 데이타를 수정하게 되는 멤버 함수만 const 를 붙이지 않습니다.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)		// user type 을 call by value 는 받는 것은 좋지 않습니다.
void foo( const Rect& r) // 이 코드가 좋습니다.
{
	int n = r.getArea(); 
}

int main()
{
	Rect r(1, 2, 3, 4);		// r은 상수 객체가 아닙니다.
	int n = r.getArea();	// ok. 문제 없습니다.

	foo(r);
}