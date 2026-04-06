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

private:
	std::string name;		// [1, 150]
	int id;					// [0, 999'9999]

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		print(os, "[{:7}] - {}", dog.id, dog.name);
		return os;
	}
};

//--------
int main()
//--------
{
	for (int i = 0; i < 10; ++i) {
		std::cout << Dog{} << '\n';
	}

	save("메인.cpp");
}
