//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 10일			(2주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <print>		// C++23
#include <algorithm>
//#include <utility>	// pair 사용
#include <array>		// C++11
#include "save.h"

std::default_random_engine dre{};
std::uniform_int_distribution uid{ 0, 9999 };

//--------
int main()
//--------
{
	// [문제] 랜덤값을 갖는 int 1000개를 만들어라.
	// int[1000] 이런 자료구조는 앞으로는 쓰지 말 것. (int a[1000])
	// new int[1000] 말고는 쓸 곳이 없다.
	// 얘는 본인의 크기도 모르고 아무것도 모른다
	// 대체할 수 있는 더 좋은 것이 있기 때문. 
	// 대체할 수 있다는 것 - 메모리 덜 쓴다, 시간이 덜걸린다.
	// 얘는 시간/공간의 zero-overhead.
	// array<T, N>
	// int a[1000]           // 자료형은 int[N]인데, 이름 위치가 비정상.

	std::array<int, 1000> a;

	// 여기는 초기화가 아니라 할당하는 작업임.
	for (int& num : a) {
		num = uid(dre);
	}

	for (int num : a) {
		std::print("{:8}", num);
	}

	// [문제] 가장 작은 값과 큰 값을 찾아 화면에 출력하라.
	// syntatic sugar 인 structured binding을 사용하면 pair를 이렇게 쓸 수 있다.
	// std::pair<int*, int*> res = std::minmax_element(std::begin(a), std::end(a));
	auto [minPos, maxPos] = std::minmax_element(std::begin(a), std::end(a));
	std::cout << "\n가장 작은 값: " << *minPos << " / 가장 큰 값: " << *maxPos << std::endl;

	save("메인.cpp");
}
