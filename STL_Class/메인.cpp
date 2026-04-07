//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 7일			(6주 1일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - std::string과 유사한 ZString을 만들어서 컨테이너 본질에 접근
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <memory>
#include "save.h"

class ZString {
public:
	ZString() = default;
	
	ZString(const char* s) {
		len = strlen(s);						// 글자 수 세서 len에 저장
		p = std::make_unique<char[]>(len);		// 글자 수 만큼 unique_ptr로 char 배열을 관리
		memcpy(p.get(), s, len);				// s에서 len 글자만큼 p로 복사. 제일 밑바닥에 있는 메모리 카피 함수. 초고속 카피 가능

	}

	friend std::ostream& operator<<(std::ostream& os, const ZString& zs) {
		for (size_t i = 0; i < zs.len; ++i) {
			os << *(zs.p.get() + i);
		}
		return os;
	}

private:
	size_t len{};
	std::unique_ptr<char[]> p{};

};

//--------
int main()
//--------
{
	// string이 나온 이유 -> char* 쓰지말라고
	ZString s{ "2026" };
	std::cout << s << std::endl;
	
	
	save("메인.cpp");
}
