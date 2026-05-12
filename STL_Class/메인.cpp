//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			5월 12일			(10주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// STL 컨테이너 - Containers are objects that store other objects.
// Sequence Container
// - array<T, N>	 - 유일하게 컴파일 타임에 size 결정 - STACK, DATA
// - vector<T>		 - 캐시 히트율이 높아 고속 데이터 처리에 유리. (array도 동일하지만 크기가 고정)
// - list<T>		 - 상수시간에 데이터를 추가/삭제 하기 위한 컨테이너. "아무 곳에서나 상수시간"에 작동한다. O(1)
// - deque<T>		 - vector와 list의 장점을 갖는 컨테이너
//					   MSVC에서는 왜 deque를 쓰나?
//					   하위 호환성 및 ABI.
// 
// - forward_list<T> - 네가 아무리 잘 코딩해도 나보다 효율적인 코드 못만든다. (한 줄 정리)
//					   It is intended that forward_list have zero space or 
//					   time overhead relative to a hand-written C-style singly
//					   linked list. - 너가 C로 만든 단일연결 리스트에 비해서 공간이나 시간이 하나도 낭비되지 않는다.
//				why? - Features that would conflict with that goal have been omitted.
//					   시간이나 공간을 들이는 기능은 제공하지 않는다. 왜? -> 메모리 잡아먹잖아. 
//					   ex) size() -> 크기를 관리하는 변수가 있어야함. 근데 그냥 너가 계산할 수 있잖아 ㅎㅎ
//					   하지만 너가 하려는 동작은 다 할걸?
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	// [문제]


}