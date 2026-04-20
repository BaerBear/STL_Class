//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 20일			(7주 2일)
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
#include <windows.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true


//--------
int main()
//--------
{
	SetConsoleOutputCP(CP_UTF8);
	save("메인.cpp");

	std::vector<ZString> v;

	// [문제] "메인.cpp"에 있는 모든 단어를 v에 저장하라.

	std::ifstream in{ "메인.cpp" };
	if (not in)
		return 20240420;

	ZString zs;
	while (in >> zs) {
		v.push_back(zs);
	}

	std::sort(v.begin(), v.end(), [](const ZString& a, const ZString& b) {
		return a.size() < b.size();
		});

	for (const ZString& zs : v) {
		std::cout << zs << '\n';
	}
}