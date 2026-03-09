//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 3일			(1주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - Release / x64
// VS 버전 - 17.14.27 (February 2026)
// 프로젝트 설정 - C++언어표준 - /std:c++latest
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// 한 학기 강의를 자동 저장하는 save 함수를 만든다.
//----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>

// using namespace std; -> 대규모 프로젝트 관리를 위해 쓰지않음

void save(const std::string& fname); // string은 좀 무거움. string_view는 나중에 다룰 것. 

// 사용하지 말아야 할 자료형 -> 대체할 수 있다 -> zero-overhead (대체한다고 해서 불이익이 없다는 뜻)
// 1. char* -> std::string
// char* -> 문자열을 처리하기 위한 특별한 자료형. 왜 쓰지말아야 하냐
// 이런 자료형이 할 수 있는게 아무것도 없음
// 2. T*	-> snart pointer 를 사용할 것
// 3. T[]	-> std::array 를 사용할 것
// ex) int num [100];
// num[100]에 접근하려다가 범위가 넘어가버리기 십상이다. (버퍼 오버플로우)
//

int main() 
{
	std::cout << "2026년 3월 9일" << '\n';

	save("메인.cpp"); // 메인.cpp를 저장하는 함수를 만들거다.
					 // 빨간줄 난 save의 식별자?? -> save라는 이름의 함수가 없어서. 다른 함수와 식별이 되어야하니까. 
					 // 선언(declare) 해줘야함. 얼마든지 해도 상관없음.

//	return 0; -> 이건 C++ 표준이 아님. 이렇게 쓰는 책 있으면 집어 던지셈.
}

// 여기 설명부터 월요일에 다시
// fname부터
// naming convention - 이름 짓는 규칙
// fileName - snake style
// file_name - nata style

void save(const std::string& fname)
{
	std::ifstream in{ fname }; // #include <fstream>. RAII -> fname의 생성과	소멸이 자동으로 관리된다.
	// in은 새로운 인스턴스. in은 ifstream 클래스의 객체. in은 파일을 읽어오는 객체. fname은 파일 이름.
	// in.close -> 쓰면 바보. in이 소멸될 때 자동으로 close가 된다.

	if (not in) { // ! 쓰면 읽기 힘드니까 not으로 바꾸는 습관 들이기
		std::cout << fname << " - 열 수 없습니다." << '\n';
		// return; -> 이것은 함수를 호출한 곳으로 돌아감.
		exit(20260309);
	}

	std::cout << "\"" << fname << "\"를 저장합니다." << "\n";

	std::ofstream out{ "2026년 1학기 STL 월56화78.txt", std::ios::app};
	
	// 시간정보 얻기
	using namespace std::chrono_literals; // 9h -> 9시간. 9s -> 9초. 9ms -> 9밀리초. 9us -> 9마이크로초. 9ns -> 9나노초.
	
	// time epoch(시간의 기원)로 부터 1초마다 증가한 tick 수. 1970년 1월 1일 0시 0분 0초
	// std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	auto now = std::chrono::system_clock::now() + 9h; 
	// 데이터 타입 deduction. auto는 컴파일러가 알아서 데이터 타입을 추론하게 하는 키워드. 

	out << '\n' << '\n';
	out << "==================================================" << '\n';
	out << "저장한 시간 - "
		<< std::format("{:%Y년 %m월 %d일 %H시 %M분 %S초}", now) << '\n';
	out << "==================================================" << '\n';
	out << '\n';

	// out은 파일을 쓰는 새로운 인스턴스. 두번째 인자에 따라 파일이 새로 만들어질 수도 있고, 기존 파일에 이어서 쓸 수도 있다.
	// std::ios::app -> append mode. 기존 파일이 있으면 그 뒤에 이어서 쓴다. 기존 파일이 없으면 새로 만든다.

	// std::copy(어디에서, 어디까지, 어디로);
	// iterator -> STL의 핵심
	// std::istream_iterator<char>{in}	  -> in에서 char를 읽어오는 iterator. in이 끝날 때까지 읽는다.
	// std::istreambuf_iterator<char>{in} -> in에서 char를 읽어오는 iterator. 버퍼 단위로 읽는다. 더 빠르다.
	std::copy(std::istreambuf_iterator<char>{in}, {},
		std::ostream_iterator<char>{out});
}
