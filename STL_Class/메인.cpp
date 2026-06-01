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
#include <algorithm>
#include <vector>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	// "이상한 나라의 앨리스.txt"의 단어를 set<ZString>에 저장하라.
	std::ifstream in{ "이상한 나라의 앨리스.txt" };

	if (not in) {
		std::cout << "파일을 살펴보세요" << std::endl;
		return 20260601;
	}
	
	std::set<ZString> s{ std::istream_iterator<ZString>{in}, {} };

	for(const ZString& zs : s) {
		std::cout << zs << "  ";
	}
	std::cout << std::endl;
	
	std::cout << "단어 개수 - " << s.size() << std::endl;

	// vector에 정렬된 데이터를 복사하였다.
	// [문제] 단어를 입력받아 있는지 없는지 출력하라.
	std::vector<ZString> v;
	v.reserve(s.size());
	v.assign(s.begin(), s.end());

	while (true) {
		std::cout << "찾을 단어? : ";
		ZString word;
		std::cin >> word;

		// 정렬된 vector이기 때문에 이진탐색이 가능
		if (std::binary_search(v.begin(), v.end(), word)) {
			std::cout << "있는 단어" << std::endl;
		}
		else {
			std::cout << "없는 단어" << std::endl;
		}
	}
}