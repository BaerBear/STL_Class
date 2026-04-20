//---------------------------------------------------------------------------
// 한 학기 강의를 저장하기 위한 함수
// 
// 2026. 3. 9. 월요일												김태건
//---------------------------------------------------------------------------

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <format>
#include "save.h"

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
		exit(0);
	}

	std::cout << "\"" << fname << "\"를 저장합니다." << "\n";

	/*std::string outFileName;
	std::cout << "파일 이름: ";
	std::getline(std::cin, outFileName);*/
	std::ofstream out{ "2026년 1학기 STL 4월 20일.txt", std::ios::app};

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
