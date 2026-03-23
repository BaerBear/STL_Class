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
#include <array>
#include <string>
#include "save.h"

class Dog {
private:
	std::string name;		// [10, 30] 사이의 소문자로 구성된 이름
	size_t id;				// [0, 9999]

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		std::print(os, "[{:4}] - {}", dog.id, dog.name);
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Dog& dog) { // 이렇게 코딩해두면 바이너리 모드여도 고수준으로 읽어오는것도 가능함.
		is.read((char*)&dog, sizeof(Dog));
		return is;
	}
};

// [문제] 파일 "Dog천마리"에는 class Dog 객체 1000개가 저장되어있다.
// 파일은 binary mode 이고 각 객체는 메모리 크기 그대로 stream의 write 함수로 기록하였다.
// 모든 객체를 한번의 write 함수를 사용하여 기록하였다.
// Dog의 멤버는 위의 코드와 같다.
// 메모리에 모두 읽어 와라.
// 메모리에 읽은 모든 Dog를 화면에 출력하라.

//--------
int main()
//--------
{
	std::ifstream in{ "Dog천마리", std::ios::binary };
	if (not in) {
		std::cout << "Dog 없음" << std::endl;
		return 20260323;
	}

	std::array<Dog, 1000> dogs;
	
	in.read((char*)dogs.data(), sizeof(Dog) * dogs.size()); // 안돌아가는 이유는 메모리임. 찾아보자

	for (const Dog& dog : dogs) {
		std::cout << dog << std::endl;
	}

	save("메인.cpp");
}
