// 방법 #2. 구조체 포인터를 사용하는 기술 
// => windows, linux, osx 등의 OS 가 내부적으로 사용하는 기술

// 아래 구조체 들은 "구조체" 자체를 사용 하라고 만든것이 아닙니다.
// => 구조체의 포인터 타입만 사용하려고 만든것 입니다.
// => 아무 멤버도 없는 구조체를 허용하지 않은 컴파일러도 있습니다.
//    이럴때는 에러는 피하기 위해서, 아무 멤버나 하나 넣으면 됩니다.
struct _HICON   { int not_used;};
struct _HBITMAP { int not_used;};

typedef struct _HICON*   HICON;
typedef struct _HBITMAP* HBITMAP;

// 서로 다른 구조체의 포인터 타입은 다른 타입 이므로
// => HICON, HBITMAP 은 모두 다른 타입입니다.
// => 또한, 포인터(주소)도 결국 정수이므로, 포인터 타입을 "정수를 담는 용도로" 사용해도 됩니다.

HICON CreateIcon() 
{
	 return (HICON)10; 
} 

void DrawBitmap(HBITMAP id) 
{
}

int main()
{
	HICON icon_id = CreateIcon();

	DrawBitmap(icon_id); // 이제는 컴파일 에러!!	
						 // 잘못 사용할수 없으므로, 안정성이 향상 되었습니다.
}