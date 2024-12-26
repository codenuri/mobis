#include "chronometry.h"
#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>

#define INPUT_COUNT 1000000

int get_input()
{
	static int num = 0;
	++num;

	if (num == INPUT_COUNT)
	{
		num = 0;
		return -1;
	}
	return num;
}
//======================================

// C++ 언어에는 linked list, vector, tree, hash 등 다양한 자료구조가 이미 라이브러리
// 형태로 제공됩니다.
// 흔히 STL 이라고 부릅니다.

// std::vector : 우리가 앞에서 만든 동적 배열(원리는 거의 동일, gcc 2배, vc 1.5배 증가)

// std::list   : 자료구조에서 배우는 double linked list



// 10만개의 데이타를 vector 와 list 에 끝에 넣었을때 성능의 차이
// => -O2 없으면 "디버깅 코드도 포함된것"
// => -O2 있으면 최적화도 지원

// 단, 전방또는 중간 삽입은 vector 가 더 느릴수도 있습니다.
// => 기존 요소를 뒤로 복사해야 하므로!!
// => 후방 삽입은 당연히 vector 가 빠릅니다.

void using_cpp_vector()
{
	int n = 0;
	std::vector<int> c;
	
	while (1)
	{
		n = get_input();

		if (n == -1)
			break;

		c.push_back(n);
	}
}

void using_cpp___list()
{
	int n = 0;
	std::list<int> c; // 더블링크드 리스트 

	while (1)
	{
		n = get_input();

		if (n == -1)
			break;

		c.push_back(n);
	}
}



int main()
{
	CHRONOMETRY(using_cpp_vector);
	CHRONOMETRY(using_cpp___list);
}

