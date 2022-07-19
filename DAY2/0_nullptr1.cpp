// 

int main()
{
	int* p1 = 0; // C++98 시절 포인터 초기화
				 // 0의 정체는 포인터가 아닌 정수(int)
				 // 리터럴 0은 포인터로 암시적 형변환 가능
//	int* p3 = 10; // error

	int* p2 = nullptr; // C++11 이후의 권장 코드.. 

	// 장점 1. 가독성이 좋다.
	auto ret = fn();

	if (ret == 0) {} // 이 코드만으로 ret가 포인터 인지 정수인지 알수 없다.
	if (ret == nullptr) {} // ret가 포인터 라고 예측 가능
}






// github.com/codenuri/mobis

// "DAY2_사전소스.zip" 받으시면 됩니다.
