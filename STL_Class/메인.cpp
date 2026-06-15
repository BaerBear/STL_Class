//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 15일			(14주 2일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// range
// range factory / range adaptor
// view - light - weight object
// filter - lazy evaluation		( <=> eager evaluation )
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

	auto 홀수 = [](int num) { 
		return num % 2 == 1; 
		};

	auto 소수 = [](int num) {
		if (num <= 1) return false;
		int limit = std::sqrt(num);
		for (int i = 2; i <= limit; ++i) {
			if (num % i == 0) return false;
		}
		return true;
		};

	for (int num 
		: std::views::iota(1, 1000) 	// iota(n, m). iota로 만든 n ~ m의 range. iota(n) -> n부터 무한대의 range.
		| std::views::filter(홀수)		// filter와 람다를 활용해 원하는 것들만 뽑아낼 수 있음. filter는 어댑터 중 하나임.
		| std::views::filter(소수)
		| std::views::reverse)
	{
		std::print("{:8}", num);
	}
	
}