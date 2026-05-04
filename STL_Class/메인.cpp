//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			5월 4일			(9주 2일)
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
// - vector<T> - 캐시 히트율이 높아 고속 데이터 처리에 유리. (array도 동일하지만 크기가 고정)
// - list<T> - 상수시간에 데이터를 추가/삭제 하기 위한 컨테이너. "아무 곳에서나 상수시간"에 작동한다. O(1)
//		대신에 random access를 지원할 수는 없다. 미치지 않았다면 이중 연결 리스트로 구현했을거다.
//		단일 연결리스트와 비교해 본다면, 이중연결리스는 양쪽으로 이터레이션을 지원하는 대신 공간을 더 사용한다. 포인터가 2개 필요함.
//		merge, splice, remove, reverse, unique, sort 
// 
// vector vs list
// - vector
//	armortized O(1) 시간에 push_back(), pop_back()
//  contiguous memory
//  O(1) 시간에 random access 가능
//  벡터를 쓰는 이유는 ? cache hit 가능성이 훨씬 높아지기 때문에 속도 차이가 극명할 수 있다.
//	벡터가 ZString을 한개 담기위해 필요한 메모리는 24Byte
// 
// - list
//  O(1) 시간에 insert(), erase()
//  free-store에서 다음 노드를 포인팅하고 있음. 추가 삭제가 빠름
//  random access 불가능. 순차적으로 접근해야함. O(n)
//  리스트는 구조적으로 cache hit의 가능성이 현저히 낮다.
//  리스트가 ZString을 한개 담기위해 필요한 메모리는 24Byte + 노트 포인터 2개(8Byte * 2) = 40Byte
//  리스트는 포인터 크기의 메모리를 희생하면서도 벡터보다 free-store에 더 많이 저장할 수 있다.
// 
//	벡터가 free-store의 50%를 사용한다고 가정할 때, 용량이 다 찼다면 1.5배 늘린다고 했을 때 연속된 공간을 더 찾을 가능성이 없다.
//  하지만 리스트는 곳곳에 존재할 수 있기 때문에 더 많이 저장할 수 있다.
// 
//  하지만 이 둘의 장점을 합치고 싶은데 ?? -> deque.
//  블럭 단위로 메모리를 할당해서 벡터처럼 연속된 공간을 제공하면서도 리스트처럼 빠른 추가/삭제가 가능하다.
//  
// 
// 
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>
#include <ranges>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	// [문제] 파일에 있는 단어를 list<ZString>에 저장하라.
	// 단어를 사전식 오름차순으로 정렬하라.

	std::ifstream in{ "2026년 1학기 STL 5월 4일.txt" };
	if (not in) {
		std::cout << "파일을 열 수 없습니다." << '\n';
		return 20260504;
	}

	//std::list<int> v{ 1,2,3 };
	//std::ranges::sort(v.begin(), v.end()); // vector일 땐 문제가 없음. list일 땐 빨간줄이 뙇. ranges를 때면 빨간줄이 안떠서 문제인지 모른다

	std::list<ZString> words{ std::istream_iterator<ZString>{in}, {} };
	words.sort([](const ZString& a, const ZString& b) { // 포인터 위치만 바꾸면 되기 때문에 그 장점을 이용하기 위해서 멤버함수로 제공된다.
		// 다음시간에. -> 정렬시간비교
		std::lexicographical_compare(a.p.get(), a.p.get() + a.len, b.p.get(), b.p.get() + b.len); 
		// 사전식 비교. a가 b보다 사전식으로 앞에 있으면 true, 그렇지 않으면 false
		});

	//std::sort(words.begin(), words.end());		// list는 random access를 지원하지 않기 때문에 sort 알고리즘이 작동하지 않는다.
	//std::ranges::sort(words.begin(), words.end());	

	/*for (const auto& w : words | std::views::take(100)) {
		std::cout << w << '\n';
	}*/
}