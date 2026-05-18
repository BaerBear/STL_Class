//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			5월 18일			(11주 1일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL 반복자 - Iterators are a generalization of pointers that allow 
//		a C++ program to work with different data structures in a uniform manner.
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

// 반복자란 무엇인가? 
// - 서로 다른 자료구조가 있더라도 동일한 방식으로 사용할 수 있도록 포인터를 일반화 해놓은 것
// 이걸 사용하는 이유는?
// 반복자의 종류를 구분한 이유

template<class 반복자>
void f(반복자 iter)
{
	// 클래스 타입으로 부터 여분(iterator traits)의 정보를 알 수 있다.
	// iterator_category, value_type, difference_type, pointer, reference
	// 표준 반복자가 제공하고 있는 5가지 traits.
	
	std::cout << typeid(반복자::iterator_category).name() << std::endl;
}

//--------
int main()
//--------
{
	save("메인.cpp");

	// 반복자의 종류를 구분하기

	f(std::ostream_iterator<int>{std::cout});
}