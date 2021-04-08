//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 8일 목요일 (6주 2일)
// 
// vector<int>에서 짝수만 삭제한다
// ㄴ remove가 지우는건 진짜가 아니다.
// ㄴ 실제 지우는 건 자료구조가 해야 한다.
// 
// 중간고사 - 4월 22일 목요일 (8주 2일)
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <deque>
#include "pch.h"
#include "save.h"
#include "String.h"

// [문제] v에서 홀수를 제거하라

int main()
{
	std::deque<String> d;

	d.emplace(d.end(), "back");
	d.emplace(d.end(), "front");

	for (const String& s : d)
	{
		std::cout << s << std::endl;
	}

	d.emplace(d.end(), "middle");

	for (const String& s : d)
	{
		std::cout << s << std::endl;
	}

	//Save("main.cpp");
}