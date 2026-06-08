//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 8일			(13주 2일)
// 6/22 기말시험(15/2) - 제일 마지막 시험
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL Unordered Associative Container - 0(1)에 데이터에 access 하려고 만든 컨테이너
// - unordered_set / unordered_multiset 
// - unordered_map / unordered_multimap
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <unordered_set>
#include <print>
#include <numeric>
#include <fstream>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

template<>
struct std::hash<ZString> {
	size_t operator()(const ZString& zs) const {
		return std::hash<std::string>{}(std::string(zs.begin(), zs.end()));
	}
};

//--------
int main()
//--------
{
	save("메인.cpp");
	// 1, 2, 3, 4 -> 4, 7, 6, 1

	std::ifstream in{ "메인.cpp" };
	if (not in) {
		std::cout << "파일 오류" << std::endl;
		return 20260608;
	}

	std::unordered_multiset<ZString> ums{ std::istream_iterator<ZString>{in}, {} };

	for (int i = 0; i < ums.bucket_count(); ++i) {
		// 왼편(버킷)은 벡터, 오른편(원소)는 리스트.
		// 보니까 8개로 시작해서 8배씩 늘어나는듯?
		std::print("[{:>03}]", i);
		for (auto j = ums.begin(i); j != ums.end(i); ++j) {
			std::cout << " --> " << *j;
		}
		std::cout << std::endl;
	}

	//while (true) {
	//	/*std::cout << "추가할 int? ";
	//	int num;
	//	std::cin >> num;
	//	std::cout << std::endl;

	//	ums.insert(num);*/

	//	
	//}

}