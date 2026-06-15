//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 15일			(14주 2일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// - range
//   range factory / range adaptor
//   view - light - weight object
//   filter - lazy evaluation		( <=> eager evaluation )
// 
// concept
// type traits
// 
// C++ Constrained Algothm ( Range + Concept )
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ranges>
#include <numeric>
#include <print>
#include <list>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

std::default_random_engine dre{ std::random_device{}() };

//--------
int main()
//--------
{
	save("메인.cpp");

	std::vector<int> v = {1, 2, 3, 4, 5};

	v.begin();		// 전통적인 range. v.begin()은 1을 가리키는 클래스 객체.
	v.end();		// v.end()는 5의 다음을 가리키는 클래스 객체.
	// [v.begin(), v.end())
	// [v.begin(), 홀수인동안)
	// [v.begin(), 무한)
	// 이런게 다 가능한데, 끝을 판독하기 위해 만든게 iterator pair.

	// for (int num : ??? ) - ???가 range임. range for문.
	for (int num : {1, 2, 3, 4, 5}) // 이런식으로도 range로 쓸 수 있다
		std::cout << num << ' ';
	
}