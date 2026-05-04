//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			5월 4일			(9주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
// 중간고사 - 4월 21일 (8주 1일)
//---------------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - dynamic (size) array - free-store에 data 관리
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	// [문제] v에서 길이가 2인 ZString을 삭제하라.
	std::vector<ZString> v{ "1", "22", "333", "44", "4444", "33", "55", "55555" };

	// 조건식은 predicate을 사용하여 판단한다.
	// predicate - bool 값을 리턴하는 callable-type.
	/*auto newEnd = std::remove_if(v.begin(), v.end(), [](const ZString& zs) {
		if (2 == zs.size())
			return true;
		else
			return false;

		});
	v.erase(newEnd, v.end());*/ // 얘네는 erase_if로 대체가 가능하다

	std::erase_if(v, [](const ZString& zs) { return zs.size() == 2; });

	//std::remove_if(v.begin(), v.end(), [](const ZString& zs) { return zs.size() == 2; }); // STL 표준은 remove_if가 조건이 true인 요소 제거

	for (const auto& zs : v)
		std::cout << zs << std::endl;

}