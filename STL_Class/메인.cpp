//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 27일			(8주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
// 중간고사 - 4월 21일 (8주 1일)
//---------------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N> - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T> - dynamic (size) array - free-store에 data 관리
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <array>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	std::vector<int> v{ 1,2,3,4,5 };
	// [문제] v에서 3을 제거하라. v.size == 4, 원소 {1,2,4,5}, v.capacity == 5;

	// 원소 제거는 std::remove()를 이용하면 된다.

	std::remove(v.begin(), v.end(), 3);
	//		   (    begin,     end, val )
	// while (b != e) 동안 
	//		if (*b == val)
	//			제거
	//		else
	//			++b;
	//

	std::cout << "v.size() = " << v.size() << '\n';
	
	for (int i : v) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	
	std::cout << "v.capacity() = " << v.capacity() << '\n';

}