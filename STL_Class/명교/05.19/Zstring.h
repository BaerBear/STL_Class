//----------------------------------------------------------------------------------------
//	STL의 동작을 잘 살펴보려고 만든 std::string과 비슷한 class
// 
// 2026. 4. 13
// 시험에 나옴!!!!!!!!!
//----------------------------------------------------------------------------------------
#pragma once
#include <iostream>

// 2026. 5. 19
class Zstring_Iterator {
public:
	// 표준반복자가 되려면 다음 5가지 타입을 제공해야 한다.
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer_type = char*;
	using reference = char&;

public:
	Zstring_Iterator() = default;
	Zstring_Iterator(char* p) : p{ p } {}

	// void로 놓으면 안된다.
	Zstring_Iterator operator++() {
		return ++p;
	}

	Zstring_Iterator operator--() {
		return --p;
	}

	Zstring_Iterator operator+(difference_type n) const{
		return p + n;
	}

	char operator*() const {
		return *p;
	}

	char& operator*(){
		return *p;
	}

	// 관계연산자는 6가지가 있다.
	// 그런데 우주선 연산자 한 개만 코딩해서 6개를 자동으로 만들 수 있다 - 만세!
	bool operator != (const Zstring_Iterator& rhs) const {
		return p != rhs.p;
	}
	auto operator<=>(const Zstring_Iterator& rhs) const = default;
	difference_type operator-(const Zstring_Iterator& rhs) const {
		return p - rhs.p;
	}


private:
	char* p;
};



// 2026. 5. 19
class Zstring_Reverse_Iterator {
public:
	Zstring_Reverse_Iterator() = default;
	Zstring_Reverse_Iterator(char* p) : p{ p } {}

	void operator++() {
		--p;
	}
	char operator*() const {
		return *(p - 1);
	}

	// 관계연산자는 6가지가 있다.
	// 그런데 우주선 연산자 한 개만 코딩해서 6개를 자동으로 만들 수 있다 - 만세!
	auto operator<=>(const Zstring_Reverse_Iterator& rhs) const = default;
private:
	char* p;
};

class Zstring {
public:
	Zstring();
	~Zstring();
	
	Zstring(const char* s);

	// 복사
	Zstring(const Zstring&);
	Zstring& operator=(const Zstring&);

	// 이동 - C++11부터 지원되는 move semantics - 복사보다 빠르게 객체의 자원을 이동하는 기능
	Zstring(Zstring&&) noexcept;	// 2026. 4. 20 move에서 예외를 던지지 않는다.
	Zstring& operator=(Zstring&&) noexcept;

	// 연산자오버로딩
	// 2026. 4. 28
	bool operator==(const Zstring& rhs) const;

	// 2026. 5. 12 - 반복자 인터페이스
	// 2026. 5. 19 - begin이 되돌려줘야할 타입은 class여야 한다.
	Zstring_Iterator begin() const;
	Zstring_Iterator end() const;
	
	// 2026. 5. 18 - 역방향 인터페이스
	// 2026. 5. 19 - 역방향반복자는 반드시 class로 코딩해야 합니다.
	Zstring_Reverse_Iterator rbegin() const;	// 원소가 존재하지 않는다. end()와 같은 주소를 반환.
	Zstring_Reverse_Iterator rend() const;


	// 인터페이스
	size_t getLen() const;
	char* data() const;	//2026. 5.11
	// STL 컨테이너가 되려면 다음 함수정도는 제공해야 - 2026. 4. 20
	size_t size() const;

	void special(std::string) const noexcept;

	void show() const;

	friend std::ostream& operator<<(std::ostream& os, const Zstring& zs);

	// 파일에서 읽어오려고 만듬 - 2026. 4. 13
	friend std::istream& operator>>(std::istream& is, Zstring& zs);

private:
	static size_t gid;			// 고유번호를 부여하기 위한 값
	size_t id;					// 객체 고유번호	- 생성 시 유일한 값
	size_t len{};				// Zstring이 관리하는 글자의 개수
	std::unique_ptr<char[]> p{};	// 글자가 저장된 free-store의 메모리
};
