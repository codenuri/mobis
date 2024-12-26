#include <stdio.h>

// 11page 그림에 정리하시면됩니다.

// 핵심 : 실행 파일 구조에 대한 이야기

// 전역변수의 초기값
int x = 0x99999999;
int y = 0x10203040;
int z = 0x90807060;
//	=> 인텔 호환 기종(intel, AMD 등)은
//  => 메모리에 데이타 보관시 바이트 단위로 거꾸로 보관합니다.
//  => 0x90807060 => 60 70 80 90 으로 보관
//  => "little endian" 방식이라고 합니다
//  => 네트워크 통신할때 중요한 이야기

int main()
{
	printf("%x, %x, %x\n", x, y, z);
}

// Windows 실행파일 : PE(Portable Executable)
// Linux   실행파일 : ELF(Executable Linking Format)

// 1. gccbuild 2_file_format1.c 로 빌드해서
// => gout.exe 만드세요

// 2. 구글에서 PEview 검색해서 받으세요
// => 2번째 링크
// => 실행파일 구조를 볼수 있는 유틸리티
// => 단, 32bit 용인데 우리 실행파일은 64 비트 용입니다.
//    하지만 기본 구조는 볼수 있습니다.