// 113 page. 코드 안정성을 위한 기술.

// 아이콘, 커서, 비트맵 등에
// 고유의 ID를 부여해서 관리하려고 합니다.
// => 아래 코드는 아이콘, 비트맵 등의 ID 관리를 위해 int 타입을 사용하는 코드

int CreateIcon() 
{
	// 아이콘을 생성해서 
	// 아이콘의 번호를 반환
	 return 10; 
} 

void DrawBitmap(int id) 
{
	// 비트맵의 ID 를 받아서 
	// 그림을 그리는 함수
}

int main()
{
	int icon_id = CreateIcon();

	DrawBitmap(icon_id); // 실수로 비트맵 번호가 아닌 아이콘 번호 전달 ??
						 // 컴파일 에러 날까요 ??
						 // 비트맵과 아이콘의 번호를 같은 타입으로 관리하기 때문에 에러 아님!!
						 // 에러 나게 할수 없을까요 ?
}