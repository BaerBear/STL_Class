//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			6월 2일			(13주 1일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL Associative Container
// - set / multiset - key-value, key == value
// - map / multimap - key-value, key값을 정렬기준으로 하여 0(log N) value를 찾는다.
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <set>
#include <vector>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

template<class 원본, class 복사본>
void my_copy(원본 beg, 원본 end, 복사본 out) 
{
	while (beg != end) {
		*out++ = *beg++; // 컨테이너에 관계없이 항상 실행되는 코드
	}
}

//--------
int main()
//--------
{
	save("메인.cpp");
	
	std::set<int> s{ 1, 2, 3, 4, 5, 1, 1, 1, 1, 1 };

	std::vector<int> v;
	// v 의 24byte -> size 0, capacity 0, pointer(현재 nullptr).
	// nullptr에 set의 정보를 카피해오려고 하니까 터지는거임.
	// 미리 5개의 공간을 만들어주면 절대 죽을 일이 없다.
	v.reserve(s.size());

	my_copy(s.begin(), s.end(), std::back_inserter(v)); 
	// back_inserter는 v라는 데이터에 push_back으로 집어넣을 수 있게 해주는 놈임
	// 행동은 함수로 하지만 함수 안에서는 무슨 일이 일어나는 지는 모름. 이건 코딩하는 사람 마음이거든
	// 반복자처럼 행동하면서 가면은 썼지만 속에서는 딴짓하는 놈 
	// -> 반복자 어댑터. revese_iterator, inserter_iterator, stream_iterator, move_iterator

	for (int num : v) 
		std::cout << num << " ";
	std::cout << std::endl;
}