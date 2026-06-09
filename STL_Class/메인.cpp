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
// - 정렬 관련 알고리즘 - 복잡도 순서대로
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in) {
		std::cout << "파일 오류" << '\n';
		return 20260609;
	}
	std::vector<ZString> v{ std::istream_iterator<ZString>{in}, {} };
	std::cout << "모두 " << v.size() << "개의 단어를 읽었다." << std::endl;

	std::sort(v.begin(), v.end());
	auto newEnd = std::unique(v.begin(), v.end());
	v.erase(newEnd, v.end());
	std::cout << "중복을 제거한 단어 개수 - " << v.size() << std::endl;

	std::shuffle(v.begin(), v.end(), dre);

	// [문제] 길이가 홀수인 것과 짝수인 것으로 분리하라.
	// 앞에는 홀수 뒤에는 짝수
	// 홀수 앞에 짝수가 있으면 안된다.
	// 홀수와 짝수가 각각 몇 개인지 출력하라.
	auto p = std::partition(v.begin(), v.end(), [](const ZString& a) {
		return *a.begin() == 'a';	// a로 시작하는 단어가 앞에 오게 분리할 수도 있다.
									// 문제를 낸다면 단어에 p가 들어가는 단어와 아닌것으로 나눠라. 같은 문제들
		});

	std::cout << "길이가 홀수인 단어 - " << std::distance(v.begin(), p) << "개" << std::endl;
	for (auto i = v.begin(); i != p; ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "길이가 짝수인 단어 - " << std::distance(p, v.end()) << "개" << std::endl;
	for (auto i = p; i != v.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}