// 방법 #1. typedef 를 사용하자
// => 아래 코드는 가독성은 좋아 졌습니다. HICON, HBITMAP 등의 이름이 다르므로
// => 하지만 결국, HICON, HBITMAP 모두 int 타입이므로 잘못 사용해도 에러가 아닙니다.
// => 가장 좋은 방법은 HICON, HBITMAP, HCURSOR, HMENU 등을 모두 다른 타입으로 하는것
//    잘못사용하면 에러 나오도록

typedef int HICON;
typedef int HBITMAP;

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