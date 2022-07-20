// 10_복사생성자
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자의 모양에 대해서 정확히 알아봅시다.
	
	// 모양 1. call by value
	Point(Point p) {}
};

int main()
{
	Point p1;		// 1번 생성자 호출
	Point p2(1, 2);	// 2번 생성자 호출

	Point p3(p2);	// 복사 생성자 호출				
}




