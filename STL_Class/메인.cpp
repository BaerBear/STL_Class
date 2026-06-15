//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 15일			(14주 2일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// universal reference - range for 에서 range factory를 이용할 때 사용
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

template<class T>
T add(const T& a, const T& b)
{
	return a + b;
}

class Dog {
public:
	Dog() = default;
	Dog(int num) : n{ num } {};

	Dog operator+(const Dog& rhs) const {
		return n + rhs.n;
	}

private:
	int n;
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.n;
	}
};

//--------
int main()
//--------
{
	save("메인.cpp");

	// [문제] add 함수를 작성하라.
	std::cout << add(1, 2) << std::endl;
	std::cout << add<std::string>("2026년", "6월 15일") << std::endl;
	
	std::cout << add(Dog{ 1 }, Dog{ 2 }) << std::endl; // 3이라고 출력되어야.
}