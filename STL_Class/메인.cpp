//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 1일			(12주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL Associative Container
// - set / multiset - key-value, key == value
// - map / multimap - key-value, key값을 정렬기준으로 하여 0(log N) value를 찾는다.
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	// "메인.cpp"의 단어를 set<ZString>에 저장하라.
	std::ifstream in{ "메인.cpp" };
	if (not in) {
		std::cout << "파일을 살펴보세요" << std::endl;
		return 20260601;
	}

	// set<ZString>에 in의 단어를 저장하라.
	// 정렬순서는 ZString의 id 기준 오름차순이다.

	class Dog {
	public:
		bool operator()(const ZString& lhs, const ZString& rhs) const {
			return lhs.getId() > rhs.getId();
		}
	};

	std::set<ZString, Dog> s{ std::istream_iterator<ZString>{in}, {} };

	관찰 = true;
	for(const ZString& zs : s) {
		zs.show();
	}
	관찰 = false;
	
}