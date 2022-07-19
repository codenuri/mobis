// F43 ~ F44 ( 22 page)

int x = 10;

int f1() { return x; }	// 1. x가 가진 값 10을 반환 ==> 답.. 
						// 2. x라는 메모리를 반환

int& f2() { return x; } // x의 값 10 이 아닌
						// x의 별명을 반환해 달라는 것

int main()
{
	int ret = f1();

	f1() = 20; // error. 10 = 20
	f2() = 20; // ok.. x = 20 의 의미. 

	// 핵심 : 참조를 반환하면 함수 호출을 등호의 왼쪽에 놓을수 있습니다.
}
// 정리
// 함수가 "value" 로 반환하면
int x = 10;
int   f1() { return x; }  // x의 값(10)을 반환
Point f2() { return pt; } // pt의 복사본(temporary)로 반환


// 함수가 "reference" 를 반환하는 의도
// 1. primitive reference
int& f3() { return x; } 
f3() = 10;  // 함수 호출을 등호의 왼쪽에 놓겠다는 의도

// 2. user type reference
Point& f4() { return pt; } // temporary 를 만들지 말라ㅏ.


// 단, 지역변수는 절대 reference 반환 하면 안됩니다.




