#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl;}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};

int main()
{
//	Point pt(1, 2); // 이름 있는 객체(named object)
				    // 수명 : 자신을 선언한 블럭을 벗어날때 파괴.

//	Point(1, 2); // 이름 없는 객체(unnamed object)
				 // 임시객체(temporary) 라고도 합니다.
				 // 수명 : 자신을 선언한 문장의 끝

	// 아래 코드 출력 결과 예측해 보세요.
	Point(1, 2), std::cout << "X" << std::endl;

	std::cout << "-------" << std::endl;
}






// 1. VC 에서 "DAY1" 프로젝트 열어보세요

// 2. 버전을 설정해야 합니다.
//  => 프로젝트 메뉴 선택 후
//  => "DAY1 속성" 메뉴 선택

//  "플랫폼도구집합", "Windows SDK" 버전 설정해 주세요
//  => 각 PC 에 설치된 버전중에 아무것이나 설정하면됩니다.
//  => 되신분은 "Ctrl + F5" 로 빌드해서 문제 없으면 됩니다.

// 3. 각, 소스 파일을 빌드 참여/제외 하는 방법
//  => 파일에서 오른쪽 버튼 누른후에 "속성" 메뉴 선택
/// => 나타나는 창에서 "빌드에서 제외" 항목에서 변경

