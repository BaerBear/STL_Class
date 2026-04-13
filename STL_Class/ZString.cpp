//-------------------------------------------------------------------------------
// STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026. 4. 13
//-------------------------------------------------------------------------------
#include <print>
#include <string>
#include "ZString.h"

size_t ZString::gid{};		// 외부에서 초기화 해줘야 함
bool 관찰{ false };

ZString::ZString()
	: id{ ++gid }
{
	if (관찰) {
		// 글자 수가 10개 이상이라도 10개까지만 출력
		int num = 10;
		if (len < 10) {
			num = len;
		}

		std::string 글자{};
		for (int i = 0; i < num; ++i) {
			글자 += p[i];
		}

		std::println("[{:7}] {:8} - 객체:{:#016X}, 글자:{:#016X}, 개수:{:<6}  ",
			id, "생성", (long long)this, (long long)p.get(), len, 글자);
	}
};

ZString::~ZString()
{
	if (관찰) {
		// 글자 수가 10개 이상이라도 10개까지만 출력
		int num = 10;
		if (len < 10) {
			num = len;
		}

		std::string 글자{};
		for (int i = 0; i < num; ++i) {
			글자 += p[i];
		}

		std::println("[{:7}] {:8} - 객체:{:#016X}, 글자:{:#016X}, 개수:{:<6}  ",
			id, "소멸", (long long)this, (long long)p.get(), len, 글자);
	}
};

ZString::ZString(const char* s)
	: id{ ++gid }
{
	len = strlen(s);						// 글자 수 세서 len에 저장
	p = std::make_unique<char[]>(len);		// 글자 수 만큼 unique_ptr로 char 배열을 관리
	memcpy(p.get(), s, len);				// s에서 len 글자만큼 p로 복사. 제일 밑바닥에 있는 메모리 카피 함수. 초고속 카피 가능

	// << -> 고급출력. 인자가 char*일 때 p.get()주소로부터 시작해서 null문자를 만날 때 까지 문자열로 출력한다.
	// 그래서 주소를 보고싶으면 (void*)로 캐스팅해서 출력해야 한다.
}

std::ostream& operator<<(std::ostream& os, const ZString& zs)
{
	for (size_t i = 0; i < zs.len; ++i) {
		os << *(zs.p.get() + i);
	}
	return os;
}
