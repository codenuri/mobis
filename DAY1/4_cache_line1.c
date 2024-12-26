// 105 page
#include "chronometry.h"

#define count 10000

// #1. 2차원 배열!
int arr[count][count]; // 10000*10000 2차원 배열

// => 코드에서는 arr[0][1] 이런식으로 접근하지만
// => 메모리 자체는 연속된 메모리..



// #2. 배열의 모든 요소를 순차(메모리에 놓인 순서로 접근)
// => 1번째 요소 접근시 "메모리 => CPU 캐쉬" 로 이동후 사용하게 되는데 
// => 이때 2, 3... 번째 요소도 같이 캐쉬로 이동하게 됩니다.
// => 따라서, 순차적으로 사용하면 캐쉬에 있는 데이타를 차례대로 사용하므로 빠릅니다.

// => 순차적으로 접근하지 않으면 
//    새로운 데이타 접근시 계속 캐쉬를 update 해야 합니다. 
//    성능저하.. 

void ex1()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			arr[i][j] = 0;
		}
	}
}

// #3. 배열의 모든 요소를 순차적이지 않은 방식으로 접근
void ex2()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			arr[j][i] = 0; // <= [i][j] 가 아닌 [j][i]
		}
	}
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}
