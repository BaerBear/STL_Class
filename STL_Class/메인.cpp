//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 20일			(7주 2일)
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
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

// template< class T, class Allocator = std::allocator<T> > class vector;
// vector는 bool을 제외하면 contiguous하게 저장된다.
// 시작번지 + offset을 계산해서 element에 접근할 수 있다.
// element를 가르키는 포인터를 함수의 인자로도 쓸 수 있다. (배열의 원소를 필요로하는 곳에	vector의 원소를 포인터로 전달할 수 있다.)
// 필요에 따라서 메모리가 늘어난다. 그래서 컴파일 타임에 공간이 정해지는 array보다 공간이 더 필요하다.
// 미리 확보한 메모리가 다 차면 dynamic하게 메모리가 확장(expanded)된다. 
// 재할당은 비용이 굉장히 많이 들어가는 동작이기 때문에 reserve()를 활용해서 미리 공간을 확보해주면 좋다.
// Random access -> constant O(1)
// 
// 끝에있는 원소에 추가하거나 지우거나 -> amorized(평균) constant 0(1) == 평균내면 상수시간이다.
// 공간이 여유가 있는 경우엔 상수시간 O(1)의 시간이 걸린다.
// 하지만 공간의 여유가 없을 땐 메모리를 확보하고 데이터를 복사하는 과정이 필요하기 때문에 O(n)의 시간이 걸린다.
// 
// 중간에 추가하거나 지우거나 -> linear O(n)
// 그러니까 벡터는 위에 두개만 써서 사용하는거야.
// 핵심 함수는 push_back과 emplace_back
//

//--------
int main()
//--------
{
	save("메인.cpp");

	// [문제] 키보드에서 입력한 모든 단어를 저장하라.
	// 입력의 끝은 OS 마다 지정되어 있다. Windows는 Ctrl+Z
	// 오름차순으로 정렬하라.
	// 출력하라

	std::vector<std::string> v;
	std::string s;
	while (std::cin >> s) {
		v.push_back(s);
	}

	// 오름차순(ascending order) 정렬

	std::sort(v.begin(), v.end());

	for (const std::string& s : v) {
		std::cout << s << std::endl;
	}
}