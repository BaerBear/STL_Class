//----------------------------------------------------------------------------------------
// 2026년 1학기 STL 월56화78					5월 26일                          (12주 1일)
//----------------------------------------------------------------------------------------
// STL 반복자 - Iterators are a generalization of pointers that allow 
// a C++ program to work with different data structures in a uniform manner.
// 기말고사 시험 6월 22일 (초어려움) 15주 2일
//----------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include "save.h"
#include "Zstring.h"
using namespace std;
extern bool 관찰;		// 관찰하려면 true

// 반복자의 핵심내용 : uniform manner

template<class 반복자>
void f(반복자 iter)
{
	cout << typeid(iterator_traits<반복자>::iterator_category).name() << endl;
}

 template<class 반복자, class Type>
반복자 my_find(반복자 begin, 반복자 end,  Type c)
{
	while (begin != end) {

		if ((*begin == c) == true) {
			return begin;
		}
		++begin;
	}
	return end;
}

// 컨테이너가 바뀌어도 my_find_if는 바뀌지 않는다. - uniform manner
template<class 반복자, class Predicate>
// Predicate는 bool을 반환하는 함수 객체
반복자 my_find_if(반복자 begin, 반복자 end, Predicate pred)
{
	while (begin != end) {
		if (pred(*begin)) {	// Predicate에 begin이 가리키는 값을 넘겨줘서 true와 false를 반환받는다.
			return begin;
		}
		++begin;
	}
	return begin;	//end를 주지 않고 begin을 주는 이유는 begin을 하나씩 증가시키면서 끝까지 가기 때문에
}

template<class 반복자, class 출력반복자>
void my_copy(반복자 begin, 반복자 end, 출력반복자 o)
{
	while (begin != end) {
		*o = *begin;
		++begin;
		++o;
	}
}

//-----------
int main()
{
//-----------
	save("main.cpp");

	Zstring zs{ "sphinx of black quartz 3 judge my 6 vow" };
	
	// 코드 설명은 다음주에
	my_copy(zs.begin(), zs.end(), ostream_iterator<Zstring::value_type>{cout, " ### "});
}
