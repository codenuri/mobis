#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "버퍼 크기 " << size << "로 초기화" << std::endl;
	}
	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//-------------------

// 핵심 : 기반 클래스(Stream) 생성자가 멤버 데이타(Buffer) 생성자보다 먼저 호출됩니다.
//       => 사용자는 절대 호출순서를 변경할수는 없습니다

// 해결책 : 기반 클래스보다 먼저 초기화 하고 싶은 멤버 데이타가 있으면
//		   또다른 기반 클래스를 설계해서 멤버로 넣으세요
class PipeBuffer
{
protected:
	Buffer mybuf{ 1024 };
};

// 그리고, 아래 처럼 다중 상속으로 해결
// 실제 이기술이 C++의 cout 만들때 사용한 기술 입니다.
class PipeStream : public PipeBuffer, public Stream
{	
public:
	PipeStream() : Stream(mybuf) {}
};


int main()
{
	PipeStream ps;
}




