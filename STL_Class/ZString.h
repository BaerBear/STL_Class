//-------------------------------------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026. 4. 13
//-------------------------------------------------------------------------------
#pragma once
#include <iostream>

class ZString {
public:
	ZString();
	~ZString();

	ZString(const char* s);

	// 복사
	

	// 이동

	friend std::ostream& operator<<(std::ostream& os, const ZString& zs);

private:
	static size_t gid;				// 고유번호를 부여하기 위한 값
	size_t id;						// 객체 고유번호 - 생성 시 유일한 값
	size_t len{};					// 관리하는 글자 개수
	std::unique_ptr<char[]> p{};	// 글자가 저장된 free-store 메모리
};