//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 23일			(3주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// 많은 수의 자료를 다루기 - FILE I/O - binary I/O - class 객체
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <random>
#include <print>
#include <string>
#include <array>
#include "save.h"

std::default_random_engine dre;

std::uniform_int_distribution uid{ 0,9999 }; // 토큰 2개
// 자료형식					  객체 이름.
// 템플릿 클래스인데 <int>를 생략할 수 있음. 특별한 경우. 원래는 적는게 원칙임

std::uniform_int_distribution uidNameLen{ 10,30 };

std::uniform_int_distribution<int> uidChar{ 'a', 'z' }; 
// 하지만 얘는 char임. 그렇기 때문에 int로 바꿔서 해도 된다고 꼭 명시해줘야됨

class Dog {
public:
	/*Dog() : id{ uid(dre) } { 여기에서 초기화 하면 왜 안되는 지 꼭 찾아보기
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i) {
			name += uidChar(dre);
		}
	}*/
	Dog() {
		id = uid(dre);
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i) {
			name += uidChar(dre);
		}
	}
private:
	std::string name;		// [10, 30] 사이의 소문자로 구성된 이름
	size_t id;				// [0, 9999]

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		std::print(os, "[{:4}] - {}", dog.id, dog.name);
		return os;
	}
};

//--------
int main()
//--------
{
	std::array<Dog, 1000> Dogs; // STACK에 생성

	std::ofstream out{ "Dog천마리", std::ios::binary };
	out.write((char*)Dogs.data(), Dogs.size() * sizeof(Dog));
	
	
	save("메인.cpp");
}
