//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 20일			(7주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
// 중간고사 - 4월 21일 (8주 1일)
//---------------------------------------------------------------------------------------------------------------------
// 컨테이너는 다른 객체를 저장하는 객체다. ( 컨테이너 == 오브젝트. 컨테이너는 오브젝트다. )
// 컨테이너도 객체니까 다른 컨테이너를 저장할 수 있다.
// homogeneous data type -> 같은 데이터 타입만 담을 수 있다.
// heterogeneous data type -> 컨테이너는 여러개의 다른 데이터 타입을 한 번에 담지는 않는다.
// 
// STL 컨테이너 - Containers are objects that store other objects.
// object란? class로 만든 객체 (instancing) -> 메모리를 차지하고 있는 실체. 메모리에 없으면 오브젝트라고 부르지 않는다.
// class로 객체를 만드는 행위 -> instancing / object는 클래스로 만들어진 instance
// 
// 다형성 - polymorphic.
// 컨테이너는 homogeneous data type만 담을 수 있다.
// 다형성을 구현하기 위해서는 부모 자식 클래스 내에 virtual을 이용한 함수를 작성하게 될것.
// 이를 한번에 담아서 다형성을 구동하게 하기 위해서는
// 부모 클래스의 포인터를 컨테이너에 담아 사용한다.
// 
// STL 자료구조 - 컨테이너. 공부 순서
// 1. sequence container - array, vector, deque, forward_list (single-linked), list (double-linked)
// 내가 원하는 위치에 가서 원하는 값으로 맘대로 바꿔도 아무 문제 없는 컨테이너다. (내 멋대로 메모리 엑세스 가능)
//  
// 이후에 iterator 반복자 학습하고 넘어간다.	
//
// 2. associative container
// 빠르게 찾으라고 기껏 정렬해뒀더니 내 멋대로 바꿔버리면 정렬이 깨지니까 
// 내가 원하는 위치에 가서 원하는 값으로 맘대로 바꿀 수 없는 컨테이너다. ( 내 멋대로 메모리 엑세스 불가능 )
//
// 3. unordered associative container
// 
// 이후 algorithm
// 
// lexicographically compares - 사전식으로 비교한다는 뜻. 사전에서 단어들이 정렬되는 방식으로 비교한다는 뜻.
// 
// operator<=> - 삼방향 비교 연산자. ZString에서 제공하도록 코딩할 예정
// 
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <array>
#include "save.h"
#include "ZString.h"

extern bool 관찰;			// 관찰하려면 true


//--------
int main()
//--------
{
	std::array<ZString, 5> a{ "1", "22", "333", "4444", "55555" };
	
	// iterator로 a를 순회
	// std::array<ZString,5>::iterator i = a.begin();
	auto i = a.begin(); // 동일한 코드임. 클래스 이터레이터를 반환한다.
	for (auto i = a.begin(); i != a.end(); ++i) 	// i++ 쓰지마라. 왜 그런지는 스스로 공부해봐라
		std::cout << *i << '\n';					// i != a.end() -> 모든 자료형에서 쓰고싶다면 이렇게 써라. 
													// i < a.end()는 contiguos한 자료형에서만 잘 돌아간다.
	
	// element access - at, operator[], front, back, data. 다섯가지 멤버함수 살펴보기
	관찰 = true;
	// 전부 동일한 결과
	a.begin()->show();
	a[0].show();
	a.front().show();
	a.data()->show(); 
	관찰 = false;

	save("메인.cpp");
}