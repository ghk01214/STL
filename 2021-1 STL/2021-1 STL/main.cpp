//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 29일 목요일 (9주 2일)
// 
// Container - 제네릭 클래스, String([char][char][char]...), begin(), end()
// Iterator  - String_iterator, String_reverse_iterator
// Algorithm - 제네릭 함수
// 
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <algorithm>
#include "pch.h"
#include "save.h"
#include "String.h"

// [문제] 이 메인이 문제없이 실행되도록 하라.

template<class RandIter, typename T>
RandIter my_find(RandIter begin, const RandIter& end, const T& val)
{
	for (; begin != end; ++begin)
	{
		if (*begin == val)
		{
			break;
		}
	}

	return begin;
}

int main()
{
	std::vector<String> v{ "123", "456", "abc" };

	auto p{ std::find(v.begin(), v.end(), String{ "abc" }) };

	std::cout << *p << std::endl;
	// 출력 결과 : abc

	Save("main.cpp");
	Save("String.h");
}