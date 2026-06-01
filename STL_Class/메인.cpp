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
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

// std::less를 ZString에 대하여 특수화(specialization)
template <>
struct std::less<ZString> {
	// predicate
	// 조건자 - 참거짓을 판단하는 callable type
	// 조건자, 서술자, 술어 -> 보통 쓰는 말 / 비교자 -> 이상한 말임 들은적 없음
	bool operator()(const ZString& a, const ZString& b) const {
		return a.size() < b.size();
	}
};

//--------
int main()
//--------
{
	save("메인.cpp");

	std::set<ZString, std::less<ZString>> s{"2026년", "6월", "1일", "월요일"};

	for(const ZString& zs : s) {
		std::cout << zs << std::endl;
	}
	
}