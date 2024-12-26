// 1_표현식.c

// 요즘 새로나오는 언어를 이해하려면 "표현식(expression)" 을 정확히 이해해야 합니다.

// expression(표현식) : 한개의 값으로 결정되는 코드의 집합(operator + operand)
// statement(문장)    : ; 으로 끝나는 한줄의 코드. 실행 단위

int main()
{
	int n = 1;

	n * 2 + 3 + 7;

	// 표현식은 한개의 값을 만들기 때문에 등호의 오른쪽에서 초기값으로 사용가능합니다
	int k = n * 2 + 3 + 7;
	
	// 왜 ? expression 이 중요한가요 ??
	// => 요즘 언어는 if, switch 가 "statement" 일수도 있고
	//    expression 일수도 있습니다.

	// C 언어 : if 는 statement 이고 expression 이 아닙니다.
	// Rust  : if 는 statement 이기도 하고 expression 이기도 합니다.
	//			등호의 오른쪽에 올수 있다는것.
	
	int ret = if ( n == 1 ) 10 else 20; // else 문 생략 안됨. 
										// 하나의 값을 만들어야 하므로
										// C 은 이렇게 안되지만 대신 ?: 있음

	// C# 은 switch 가 expression 입니다.
	int ret2 = n switch { 1 => 10,  2 => 20, _ => 30 }; // C# 코드 
 
}