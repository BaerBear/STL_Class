//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 2일			(13주 1일)
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
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in) {
		std::cout << "이상한 파일" << '\n';
		return 20260602;
	}

	std::vector<ZString> v{ std::istream_iterator<ZString>{ in }, {} };

	//std::copy(std::istream_iterator<ZString>{ in }, {}, std::back_inserter(v));
	std::cout << "읽어온 단어 수 - " << v.size() << '\n';

	for (const ZString& zs : v) {
		std::cout << zs << " ";
	}
	std::cout << std::endl;

	// [문제] 어떤 단어가 가장 많이 사용되었는지 알고 싶다.
	// 많이 사용된 단어부터 단어와 개수를 화면에 출력하시오.
	// the - 1nnn
	// a - nnn
	// zigzag - 1

	std::map<ZString, size_t> 단어와개수;
	for (const ZString& zs : v) {
		++단어와개수[zs];
	}

	for (const std::pair<ZString, size_t>& p : 단어와개수) {
		std::cout << p.first << " - " << p.second << '\n';
	}
	std::multimap<size_t, ZString> 개수와단어;
	
}