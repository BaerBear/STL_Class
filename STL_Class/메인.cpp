//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			4월 6일			(5주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// 예제
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <random>
#include <string>
#include <print>
#include <array>
#include <ranges>
#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 999'9999 };
std::uniform_int_distribution uidNameLen{ 1, 150 };
std::uniform_int_distribution<> uidChar{ '!', '~' };

class Dog {
public:
	Dog() {
		id = uid(dre);
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i) {
			name += uidChar(dre);
		}
	};
	bool operator() (Dog a, Dog b) const {
		return a.name < b.name;
	}
private:
	std::string name;		// [1, 150]
	int id;					// [0, 999'9999]

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		print(os, "[{:7}] - {}", dog.id, dog.name);
		return os;
	}
};

// 기말쯤에 a~z까지 모두 들어간 Dog가 있니?? 몇개나 있니?? 나올수도

// [문제] Dog 객체 10만개를 메모리에 저장하라.
// std::sort를 사용하여 id 기준 오름차순으로 정렬하라.
// 필요하다면 Dog에 interfacce 멤버를 추가하라.
// 앞에서부터 1000개의 내용을 출력하라.

std::array <Dog, 100'000> dogs;

std::array<int, 1'000> a;
// 전역에 변수 선언 -> 자동으로 기본 생성자로 인해 0으로 초기화된다.

//--------
int main()
//--------
{
	/*std::sort(dogs.begin(), dogs.end(), Dog{});

	for( Dog d : dogs | std::views::take(1000) ) {
		std::cout << d << '\n';
	}*/

	std::array<int, 1'000> a; // 지역에 선언 -> 초기화되지 않은 상태로 존재.
	// 클래스는 다름. 클래스는 생성자를 호출하는 게 보장된다.

	for (int num : a) {
		std::cout << num << std::endl;
	}

	save("메인.cpp");
}
