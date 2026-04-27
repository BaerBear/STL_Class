//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 27일			(8주 2일)
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
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	// [문제] "메인.cpp"에 알파벳 소문자가 몇 개나 있는지 다음과 같이 출력하라.
	// a - 10
	// b - 5
	// ...
	// z - 1

	// 이 문제는 26개로 정해져있기 때문에 array 자료구조를 사용하자.
	// vector 수업을 하고있었다고 해서 vector를 써야하는건 아니다. 문제에 맞는 자료구조를 쓰는게 중요하다.
	// 소신을 가져라!! 
	std::array<size_t, 26> alpha{};		// {} 모든 메모리 초기화하고 시작해야함.

	std::ifstream in{ "메인.cpp" };
	if (not in) {
		std::cout << "메인.cpp - 열 수 없습니다." << '\n';
		return 1;
	}

	std::for_each(std::istreambuf_iterator<char>{in}, std::istreambuf_iterator<char>{}, [&alpha](char c) {
		if (std::islower(c)) {
			++alpha[c - 'a'];
		}
		});

	for (size_t i = 0; i < alpha.size(); ++i) {
		std::cout << static_cast<char>('a' + i) << " - " << alpha[i] << '\n';
	}

}