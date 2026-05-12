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
// - forward_list<T> - 네가 아무리 잘 코딩해도 나보다 효율적인 코드 못만든다.
// 
// Callable Types
// 이 네가지가 function<T>로 돌아가는 타입이다.
// - function pointer(function)	- 
// - lambda						-
// - function object			-
// - member function pointer	-
// 
// AI는 이 두가지 까지 있다고 알려주지만 교수님은 위 4가지만 설명하고 싶어하심
// - Pointer to member data
// - std::function
// 
// T[N], array<T, N>, vector<T>, string, ZString - contiguos memory
// -> 포장할(wrap) 수 없을까? (= 공통되게 나타낼 수 없을까?) 여기서 포장하는 포장지가 span<T>이다.
// span<T> - light-weight object. (경량 객체) 
// contiguous memory는 시작 번지와 개수만 있다면 나타낼 수 있다는 점을 이용. 포인터와 개수만 가짐.
// 무거운 객체를 포장지(span<T>)로 가볍게 만들어서 사용하자.
// 
// 하지만 string은 정보 전달이 필수적임. 그래서 string만을 위한 경량 객체는 따로 있는데 이것이
// -> string_view
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <ranges>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

//--------
int main()
//--------
{
	save("메인.cpp");

	ZString zs{ "The quick brown fox jumps over the lazy dog" };

	std::sort(zs.data(), zs.data() + zs.size());

	// [문제] 거꾸로 출력하세요.
	// ZString은 최신기능 (views)를 사용하지 못함 ㅠㅠ 그래서 울고만 있을거야?
	// span이라는 포장지를 씌우면 최신기능 사용할 수 있게 변신시킬 수 있어!!!!
	std::span<char> s{ zs.data(), zs.size() };	// 위에 적어둔 대로 포인터와 개수만 알려주면 된다.
	
	
	for (char c : s | std::views::reverse) {
		std::cout << c << "-";
	}
	
	std::cout << std::endl;
}