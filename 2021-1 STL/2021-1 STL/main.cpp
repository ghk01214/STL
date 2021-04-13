//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 15일 화요일 (7주 2일)
// 
// 1. sequence container
//	원소를 삭제.추가하는 동작이 O(1)
//    - list
//    - forward_list
// 
// 중간고사 - 4월 22일 목요일 (8주 2일)
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <list>
#include "pch.h"
#include "save.h"
#include "String.h"

// 전체를 반복자로 순회하며 출력하자

int main()
{
	std::list<String> c{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	c.sort([](const String& a, const String& b)
		{
			return a.size() < b.size();
		});

	for (const String& s : c)
	{
		std::cout << s << std::endl;
	}

	//Save("main.cpp");
}