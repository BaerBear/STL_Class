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
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <array>
#include <list>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	std::vector<ZString> v{ "1", "22", "4444", "55555" };
	// [문제] "22" 다음에 "333"을 추가하라.
	관찰 = true;
	for (int i = 0; i < 10; ++i)
		v.emplace(v.begin() + 2, "333"); // 중간에 끼워넣는 동작은 벡터한테 굉장히 큰 무리다.
	관찰 = false;

	for (const ZString& zs : v)
		std::cout << zs << std::endl;


}