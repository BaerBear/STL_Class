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
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true

// vector는 bool을 제외하면 contiguous하게 저장된다.
// 시작번지 + offset을 계산해서 element에 접근할 수 있다.
// element를 가르키는 포인터를 함수의 인자로도 쓸 수 있다. (배열의 원소를 필요로하는 곳에	vector의 원소를 포인터로 전달할 수 있다.)
// 필요에 따라서 메모리가 늘어난다. 그래서 컴파일 타임에 공간이 정해지는 array보다 공간이 더 필요하다.
// dynamic하게 메모리가 확장(expanded)된다. 미리 확보한 메모리가 다 차면 확장된다.
// 재할당은 비용이 굉장히 많이 들어가는 동작이기 때문에 reserve()를 활용해서 미리 공간을 확보해주면 좋다.
// Random access -> constant O(1)
// 끝에있는 원소에 추가하거나 지우거나 -> amorized constant 0(1)
// 중간에 추가하거나 지우거나 -> linear O(n)
// 그러니까 벡터는 위에 두개만 써서 사용하는거야.
// 핵심 함수는 push_back과 emplace_back
//

//--------
int main()
//--------
{
	save("메인.cpp");

	std::vector<int> v{ 1,2,3,4,5 }; // -> free-store에 저장됨. 다이나믹하게 관리되기 때문

	std::cout << "v의 메모리 크기 - " << sizeof(v) << std::endl;	   // v의 메모리 크기 - 24
	std::cout << "v의 주소 - " << addressof(v) << std::endl;		   // v의 주소 - 000000FA738FF910
	std::cout << "v의 타입 - " << typeid(v).name() << std::endl;	   // v의 타입 - class std::vector<int,class std::allocator<int>>
	std::cout << "v가 저장할 수 있는 최대 int 개수 - " << v.max_size() << std::endl; // 4611686018427387903 
}