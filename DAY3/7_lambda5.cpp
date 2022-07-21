// conversion function pointer

int main()
{
	// 람다 표현식은 함수 포인터로 암시적 변환 가능합니다.
	int(*fp)(int, int) = [](int a, int b) { return a + b; };
							// class xxx{};
							// xxx(); 즉, 임시객체

//	함수포인터 fp = 임시객체;  // 임시객체.operator 함수포인터();
							// 즉, 변환 연산자가 있기 때문에 가능

}