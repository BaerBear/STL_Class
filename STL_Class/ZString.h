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
	size_t len{};
	std::unique_ptr<char[]> p{};
};