//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 30일			(4주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// callable types -> 실습 -> STL
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <print>
#include <array>
#include <ranges>
#include "save.h"

// [문제] 랜덤값을 갖는 int 1000만개를 메모리에 저장하라.
// qsort를 이용하여 오름차순 정렬하라.
// 정렬결과를 앞에서부터 1000개만 화면에 출력하라.

std::default_random_engine dre;
std::uniform_int_distribution<int> uid{ 0, 999'9999 };

std::array<int, 1000'1000> arr;

int 오름차순(const void* a, const void* b)
{
	return *(const int*)a - *(const int*)b;
	// 1보다 크면 바꿈. 0이거나 -1보다 작으면 안바꿈.
}

//--------
int main()
//--------
{
	save("메인.cpp");

	for (int& num : arr) {
		num = uid(dre);
	}

	// 시간측정 시작

	std::qsort(arr.data(), arr.size(), sizeof(std::array<int, 1000'0000>::value_type), 오름차순);
	// qsort는 람다함수를 이해하지 못하는 함수다. 직전에 람다함수로 정렬 안되던 이유가 이거인듯.
	// 옛날 C언어에서 쓰던 함수라 그렇다. STL에서는 람다함수도 이해하는 함수가 있지만 우선 qsort를 써보자
	// 그렇기 때문에 qsort는 전통적으로 비교 함수를 따로 만들어서 넘겨준다.

	// 시간측정 끝

	std::cout << "정렬 후 출력" << std::endl;
	for (int& num : arr | std::views::take(1000)) {		// | 용어: vertical bar. filter 같은 역할. C++20 기능.
		std::print("{:8}", num);
	}

	/*for (int i = 0; i < 1000; ++i) { 이렇게 쓰지 말자!
		std::print("{:8}", arr[i]);
	}*/
	std::cout << std::endl;
}
