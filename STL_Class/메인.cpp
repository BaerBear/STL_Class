//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 10일			(2주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// 다음 시간 멤버 설명부터 다시
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

template <class T, int N>
class myArray {
public:
	size_t size() const {
		return N;
	}

	int& operator[] (int idx) {
		return a[idx];
	}

	T* begin() {
		return &a[0];
	}

	T* end() {
		return &a[N];
	}

private:
	T a[N];

};

//--------
int main()
//--------
{
	myArray<int, 1000> a;
	std::cout << "a가 사용하는 메모리 - " << sizeof a << std::endl;	// 메모리 손해 x. 똑같이 4000바이트
	// 표준 자료구조. a. 찍어보면? 여러 함수를 제공

	// 여기는 초기화가 아니라 할당하는 작업임.
	// 이것도 슈가임.
	/*for (int& num : a) {
		num = uid(dre);
	}*/
	for (int i = 0; i < a.size(); ++i) {
		a[i] = uid(dre);
	}

	for (int num : a) {
		std::print("{:8}", num);
	}

	// [문제] 가장 작은 값과 큰 값을 찾아 화면에 출력하라.
	// syntatic sugar 인 structured binding을 사용하면 pair를 이렇게 쓸 수 있다.
	// std::pair<int*, int*> res = std::minmax_element(std::begin(a), std::end(a));
	auto [minPos, maxPos] = std::minmax_element(a.begin(), a.end());
	std::cout << "\n가장 작은 값: " << *minPos << " / 가장 큰 값: " << *maxPos << std::endl;

	save("메인.cpp");
}
