//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 06일 목요일 (10주2일)
// 
// Container - 제네릭 클래스, String([char][char][char]...), begin(), end()
// Iterator  - String_iterator, String_reverse_iterator
// Algorithm - 제네릭 함수
// 
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <string>
#include <list>
#include "pch.h"
#include "save.h"
#include "String.h"

// [문제] 반복자 간의 거리를 계산하는 distance를 작성하라.

template<class Iter>
ptrdiff_t my_distance(Iter begin, Iter end)
{
	// random_access_iterator
	// 작동 안 함
	if (std::random_access_iterator_tag<Iter>)
		return end - begin;

	ptrdiff_t distance{};

	for (; begin != end; ++begin)
	{
		++distance;
	}

	return distance;
}

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5 };
	std::cout << my_distance(v.cbegin(), v.cend()) << std::endl;

	std::list<int> l{ 1, 2, 3, 4, 5 };
	std::cout << my_distance(l.cbegin(), l.cend()) << std::endl;

	//Save("main.cpp");
}