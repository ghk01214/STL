//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 27일 화요일 (9주 1일)
// 
// container, algorithm, 그리고 이 둘을 연결하는 iterator
// 
// 반복자 : 책 31 ~ 41, 123 ~ 136, Design Pattern 중 iterator pattern
//  반복자는 포인터를 추상화한 것이다.
//  반복자처럼 행동하는 것은 반복자이다.
//  반복자는 container가 제공하는 인터페이스이다.
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <iterator>
#include "pch.h"
#include "save.h"
#include "String.h"

// [문제] String이 반복자를 리턴한다.
// sort() 가 문제없이 실행되도록 반복자에게 필요한 함수들을 오버로딩하라

template<typename iter>
void showIteratorCategory(const iter&)
{
	std::cout << typeid(std::iterator_traits<iter>::iterator_category).name() << std::endl;
}

int main()
{
	String s{ "1357924680" };

	for (auto i{ s.rbegin() }; i != s.rend(); ++i)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl;

	//Save("main.cpp");
}