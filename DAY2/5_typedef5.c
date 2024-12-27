// 방법 #2. 구조체 포인터를 사용하는 기술 
// => windows, linux, osx 등의 OS 가 내부적으로 사용하는 기술

struct _HICON {};
struct _HBITMAP {};

typedef _HICON*   HICON;
typedef _HBITMAP* HBITMAP;


HICON CreateIcon() 
{
	 return 10; 
} 

void DrawBitmap(HBITMAP id) 
{
}

int main()
{
	HICON icon_id = CreateIcon();

	DrawBitmap(icon_id); 
}