//--------------------------------------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78			3월 30일			(4주 2일)
//--------------------------------------------------------------------------------------------------------------------
// 컴파일 환경 - RELEASE / X64
// VS 버전 - 17.14.27 (FEBRUARY 2026)
// 프로젝트 설정 - C++언어표준 - /STD:C++LATEST
//				- C/C++언어 - SDL검사 - 아니요
//---------------------------------------------------------------------------------------------------------------------
// CALLABLE TYPES -> 실습 -> STL
//----------------------------------------------------------------------------------------------------------------------
#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.H"

// [문제] "메인.CPP"의 소문자를 모두 대문자로 바꾼 "메인대문자.CPP"를 만들어라.
// TRANSFORM(뭐를, 뭐로, 어떻게);
// TRANSFORM(메인.CPP를, 메인대문자.CPP로, 소문자를 대문자로)

CHAR 소투대(CHAR C) 
{
	RETURN C = STD::TOUPPER(C);
}

//--------
INT MAIN()
//--------
{
	STD::IFSTREAM IN{ "메인.CPP" };
	IF (NOT IN) {
		STD::COUT << "메인.CPP - 열 수 없습니다." << '\N';
		RETURN 20260330;
	}

	STD::OFSTREAM OUT{ "메인대문자.CPP" };
	
	/*CHAR C;			LOOP를 직접 안짜도 된다. 알고리즘이 해준다.
	WHILE (IN.GET(C)) {
		OUT.PUT(STD::TOUPPER(C));
	}*/

	// TRANSFORM(메인.CPP를, 메인대문자.CPP로, 소문자를 대문자로)
	// TRANSFORM(메인시작, 메인끝, 메인대문자시작으로, 함수의 시작번지)
	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {},	// 2번째 인자의 정식 표기는 STD::ISTREAMBUF_ITERATOR<CHAR>{} -> 끝을 나타내는 ITERATOR 
		STD::OSTREAMBUF_ITERATOR<CHAR>{OUT},				
		소투대);

	SAVE("메인.CPP");
}
