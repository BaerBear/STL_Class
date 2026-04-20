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
	save("메인.cpp");

	std::array<ZString, 5> a{ "1", "22", "333", "4444", "55555" };
	std::array<int, 5> b{ 1, 2, 3, 4, 5 };

	// element access - at, operator[], front, back, data. 다섯가지 멤버함수 살펴보기

	// at() -> 필요성은 예제를 통해 알아보겠다.
	// 경계를 검사하고 싶다면 이 함수를 사용하면 된다.
	// C++은 속도를 최우선으로 하는 언어이다.
	// 시간걸리는 at()을 다른 함수로 제공하는 이유이다.
	// at()은 예외를 던진다.

	// operator[] - syntatic sugar. 경계 밖 access 시도를 막지 않아 UB를 발생시킬 수 있다.
    // at은 access에 대한 경계 검사를 진행하여 UB를 원천적으로 막아준다.
    // 대신 시간을 먹는다.

	while (true) {
		std::cout << "찾을 원소는?";
		int num;
		std::cin >> num;

		try {
			std::cout << b.at(num) << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;			// 표준 예외를 출력한다.
		}
	}
}