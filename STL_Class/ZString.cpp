#include <print>
#include <algorithm>	// equal
#include "ZString.h"

size_t ZString::gid{};		//외부에서 초기화
bool 관찰{ false };

ZString::ZString()
	: id{ ++gid }
{
	if (관찰) {
		special("생성");
	}
}

ZString::~ZString()
{
	if (관찰) {
		special("소멸");
	}
}

ZString::ZString(const char* s)
	: id{ ++gid }
{
	len = strlen(s);
	p = std::make_unique<char[]>(len);	// free-store에 메모리 확보 작업
	memcpy(p.get(), s, len);	// 저수준 메모리 copy 작업

	if (관찰) {
		special("생성(*)");
	}

}

// 복사 생성과 복사할당연산자
ZString::ZString(const ZString& other)
	: id{ ++gid }
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);	// 저수준 메모리 copy 작업
	
	if (관찰){
		special("복사생성");
	}
}
ZString& ZString::operator=(const ZString& other)
{
	if (this == &other) {
		return *this;
	}
	len = other.len;
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);	// 저수준 메모리 copy 작업

	if (관찰) {
		special("복사할당");
	}

	return *this;
}

// 이동 생성과 이동할당연산자
// 2026. 4. 20 move에서 예를 던지지 않는다.
ZString::ZString(ZString&& other) noexcept
	: id { ++gid }
{
	len = other.len;
	p.reset(other.p.release());
	other.len = 0;				// 자기 자원이 이동된 other는 xvalue가 되고 이것을 사용하면 undefined behavior
	
	if (관찰) {
		special("이동생성");
	}
}
ZString& ZString::operator=(ZString&& other) noexcept
{
	if (this == &other) {
		return *this;
	}
	len = other.len;
	// 잘 한 건가? 내 메모리 반환했나?
	p.reset(other.p.release());
	other.len = 0;
	
	if (관찰) {
		special("이동할당");
	}
	return *this;
}


// 2026. 4. 28
bool ZString::operator==(const ZString& rhs) const
{
	// 동등성(equality)과 상등성(equivalence)의 차이
	// id, len, p가 있는데 ==> 내가 관리하는 글자가 같으면 같은거다.
	if (len != rhs.len) {
		return false;
	}

	return std::equal(p.get(), p.get() + len, rhs.p.get());	// p는 char자료형 알고리즘이 잘 처리할 수 있는 자료형.
	
	// 이런 코드 작성은 STL을 다시 공부해야한다.
	/*for (int i = 0; i < len; ++i) {
		if (p[i] != rhs.p[i]) {
			return false;
		}
	}

	return true;*/
}

// 2026. 6. 1
// set의 기본정렬 연산자 < (less 라고 읽음)
// 사전식 정렬되도록 코딩 (lexicographical order)
bool ZString::operator<(const ZString& rhs) const
{
	return std::lexicographical_compare(begin(), end(), rhs.begin(), rhs.end());
}


// 2026. 5. 12 - 반복자 인터페이스
// 2026. 5. 19 - begin이 되돌려줘야할 타입은 class여야 한다.
ZString_Iterator ZString::begin() const
{
	return p.get();
}

ZString_Iterator ZString::end() const 
{
	return p.get() + len;
}

// 2026. 5. 18 - 역방향 인터페이스
// 2026. 5. 19 - 역방향반복자는 class로 코딩해야 합니다.
ZString_Reverse_Iterator ZString::rbegin() const
{
	return p.get() + len;
}
ZString_Reverse_Iterator ZString::rend() const
{
	return p.get();
}

// 나중에 삭제할 예정
size_t ZString::getLen() const 
{
	return len;
}

// STL 컨테이너가 되려면 다음 함수정도는 제공해야 - 2026. 4. 20
size_t ZString::size() const 
{
	return len;
}

char* ZString::data() const	//2026. 5.11
{
	return p.get();	// 문자의 첫 번째 주소를 반환
}

void ZString::special(std::string 동작) const noexcept
{
	int num = 10;
	if (len < 10) {
		num = len;
	}
	std::string 글자{};
	for (int i = 0; i < num; ++i) {
		글자 += p[i];
	}
	std::println("[{:7}] {:8} - 객체:{:#014X}, 글자:{:#014X}, 개수:{:<6} 내용:{} ",
		id, 동작 , (long long)this, (long long)p.get(), len, 글자);
}

void ZString::show() const
{
	special("show");
}

std::ostream& operator<<(std::ostream& os, const ZString& zs)
{
	for (int i = 0; i < zs.len; ++i) {
		os << *(zs.p.get() + i);	// * -> 스마트 포인터에 들어있는 문자열 출력을 위해 사용
	}
	return os;
}

// 파일에서 읽어오려고 만듬 - 2026. 4. 13
std::istream& operator>>(std::istream& is, ZString& zs)
{
	// 그림 설명에서 시작

	std::string s;
	is >> s;
	zs.len = s.size();
	zs.p.reset();
	zs.p = std::make_unique<char[]>(s.size());
	memcpy(zs.p.get(), s.data(), zs.len);

	return is;
}