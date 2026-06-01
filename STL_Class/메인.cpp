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
	
	std::multiset<ZString> s{ std::istream_iterator<ZString>{in}, {} };

	for(const ZString& zs : s) {
		std::cout << zs << "  ";
	}
	std::cout << std::endl;
	
	std::cout << "단어 개수 - " << s.size() << std::endl;

	// [문제] 단어를 입력받아 있다면 몇개 있는지
	// 없다면 없다고 출력하라.

	while (true) {
		std::cout << "찾을 단어? : ";
		ZString word;
		std::cin >> word;
		

		auto [하한, 상한] = s.equal_range(word);
		// pair로 받아 코딩해 보세요
		
		if (하한 == 상한) {
			std::cout << "없는 단어" << std::endl;
		}
		else {
			std::cout << std::distance(하한, 상한) << "개" << std::endl;
			// contiguos 메모리가 아니므로 반드시 distance로 구해야 함.
		}
	}
}