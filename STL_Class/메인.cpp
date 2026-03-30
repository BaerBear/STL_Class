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
#include <fstream>
#include <algorithm>
#include "save.h"

// [문제] "메인.cpp"의 소문자를 모두 대문자로 바꾼 "메인대문자.cpp"를 만들어라.
// transform(뭐를, 뭐로, 어떻게);
// transform(메인.cpp를, 메인대문자.cpp로, 소문자를 대문자로)

char 소투대(char c) 
{
	return c = std::toupper(c);
}

//--------
int main()
//--------
{
	std::ifstream in{ "메인.cpp" };
	if (not in) {
		std::cout << "메인.cpp - 열 수 없습니다." << '\n';
		return 20260330;
	}

	std::ofstream out{ "메인대문자.cpp" };
	
	/*char c;			loop를 직접 안짜도 된다. 알고리즘이 해준다.
	while (in.get(c)) {
		out.put(std::toupper(c));
	}*/

	// transform(메인.cpp를, 메인대문자.cpp로, 소문자를 대문자로)
	// transform(메인시작, 메인끝, 메인대문자시작으로, 함수의 시작번지)
	std::transform(std::istreambuf_iterator<char>{in}, {},	// 2번째 인자의 정식 표기는 std::istreambuf_iterator<char>{} -> 끝을 나타내는 iterator 
		std::ostreambuf_iterator<char>{out},				
		소투대);

	save("메인.cpp");
}
