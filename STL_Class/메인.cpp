//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 15일			(14주 2일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL Algorithms
// - 정렬 관련 알고리즘 - 복잡도 순서대로
// - partition - 복잡도가 제일 낮음
// - nth_element
// - partial_sort
// - sort
// - stable_sort - 제일 복잡함
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ranges>
#include <numeric>
#include <print>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

std::default_random_engine dre{ std::random_device{}() };

//--------
int main()
//--------
{
	save("메인.cpp");

	// 1부터 100까지 숫자를 준비한다.
	std::vector<int> v(100);
	std::ranges::iota(v, 1);		// range 설명은 잠시뒤에
	std::ranges::shuffle(v, dre);

	for (int num : v) {
		std::print("{:4}", num);
	}
	std::cout << std::endl;
}