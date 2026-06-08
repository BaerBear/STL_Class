//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 8일			(13주 2일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// 컨테이너 찾기 성능 비교
// 1. vector
// 2. multiset
// 3. unordered_multiset
// 
// 1000만개에서 10만개 찾기
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <random>
#include <algorithm>
#include <chrono>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

const size_t NUM{ 10'000'000 };
const size_t FNUM{ 10'000 };

std::array<int, NUM> num;
std::array<int, FNUM> fnum;

std::default_random_engine dre{};
std::uniform_int_distribution uid{ 1, 20'000'000 };

//--------
int main()
//--------
{
	save("메인.cpp");
	for (int& num : num) {
		num = uid(dre);
	}

	for (int& num : fnum) {
		num = uid(dre);
	}

	{	// vector에서 찾기
		std::cout << std::endl;
		std::vector<int> v{ num.begin(), num.end() };

		std::cout << "vector에서 찾는 중";
		size_t cnt{};

		auto start = std::chrono::high_resolution_clock::now();
		for (int num : fnum) {
			if (std::find(v.begin(), v.end(), num) != v.end())
				++cnt;
		}
		auto stop = std::chrono::high_resolution_clock::now();

		std::cout << std::endl;
		std::cout << FNUM << "중에서 " << cnt << "개 찾음" << std::endl;
		std::cout << "걸린시간 - " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start) << std::endl;
	}


	{	// 정렬된 vector에서 찾기
		std::cout << std::endl;
		std::vector<int> v{ num.begin(), num.end() };
		
		std::cout << "벡터를 정렬하는 중";
		std::sort(v.begin(), v.end());
		std::cout << std::endl;

		std::cout << "정렬된 vector에서 찾는 중";
		size_t cnt{};

		auto start = std::chrono::high_resolution_clock::now();
		for (int num : fnum) {
			if (std::binary_search(v.begin(), v.end(), num))
				++cnt;
		}
		auto stop = std::chrono::high_resolution_clock::now();

		std::cout << std::endl;
		std::cout << FNUM << "중에서 " << cnt << "개 찾음" << std::endl;
		std::cout << "걸린시간 - " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start) << std::endl;
	}

	{	// multiset에서 찾기
		std::cout << std::endl;
		std::multiset<int> s{ num.begin(), num.end() };

		std::cout << "set에서 찾는 중";
		size_t cnt{};

		auto start = std::chrono::high_resolution_clock::now();
		for (int num : fnum) {
			if (s.contains(num))
				++cnt;
		}
		auto stop = std::chrono::high_resolution_clock::now();

		std::cout << std::endl;
		std::cout << FNUM << "중에서 " << cnt << "개 찾음" << std::endl;
		std::cout << "걸린시간 - " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start) << std::endl;
	}

	{	// unordered_multiset에서 찾기
		std::cout << std::endl;
		std::unordered_multiset<int> us{ num.begin(), num.end() };

		std::cout << "unordered_set에서 찾는 중";
		size_t cnt{};

		auto start = std::chrono::high_resolution_clock::now();
		for (int num : fnum) {
			if (us.contains(num))
				++cnt;
		}
		auto stop = std::chrono::high_resolution_clock::now();

		std::cout << std::endl;
		std::cout << FNUM << "중에서 " << cnt << "개 찾음" << std::endl;
		std::cout << "걸린시간 - " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start) << std::endl;
	}
}