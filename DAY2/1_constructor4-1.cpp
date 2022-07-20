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
// Stream 에서 파생된  새로운 Stream 제작
// => 아래 코드의 문제점 찾아 보세요

class PipeStream : public Stream
{
	Buffer mybuf{ 1024 };
public:
	//				 // 컴파일러 변경 코드
//	PipeStream() {}  // PipeStream() : Stream() {}  <= Stream 디폴트생성자가 없다

	// 기반 클래스에 디폴트 생성자가 없으면 
	// 파생 클래스에서 반드시 명시적으로 호출해야 합니다.
	PipeStream() : Stream(mybuf) {}
};
/*
// 위 코드는 컴파일러에의해서 아래 처럼 변경
class PipeStream : public Stream
{
//	Buffer mybuf{ 1024 }; // 이코드는 
	Buffer mybuf;			// 결국 이렇게 되고, 초기화는 
							// PipeStream의 초기화 리스트에서 초기화되는것
public:
	PipeStream() : Stream(mybuf), mybuf{ 1024 } {}
};
*/


int main()
{
	PipeStream ps;
}




