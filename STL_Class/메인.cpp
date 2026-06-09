//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 9일			(14주 1일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL Algorithms
// 1. Non-modifying sequence operations
// 2. Modifying sequence operations
// 3. Sorting and related operations
// 
// 시험에 Set operations 사용한 문제 낼거임.
// 큰 파일 두개를 주고 공통된 단어를 찾아내기. 뭐 이런거
// 
// STL Algorithm을 살펴보면
// constrained Algorithm (C++ 20)이 보이는데,
// 이거의 기본이 되는 개념이 concept과 range - [begin, end) 임.
// lazy - evaluation (views, filter)
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

std::default_random_engine dre{ std::random_device{}() };

//--------
int main()
//--------
{
	save("메인.cpp");

	std::vector<int> v(45);
	std::iota(v.begin(), v.end(), 1);
	// 이번 주 lotto 번호를 알려주자.
	std::sample(v.begin(), v.end(), std::ostream_iterator<int>{std::cout, " "}, 5, dre);
	std::cout << std::endl;
}