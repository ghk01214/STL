//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 8일 목요일 (6주 2일)
// 
// vector<int>에서 짝수만 삭제한다
// vector<int> 중간에 원소를 추가해 본다
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <algorithm>
#include <vector>
#include "pch.h"
#include "save.h"
#include "String.h"

int main()
{
	std::vector<String> v{ 20, 10, 30 };

	// v를 길이 오름차순으로 정렬하시오

	std::cout << std::endl;
	std::cout << "===============정렬 전===============" << std::endl;
	std::cout << std::endl;

	std::sort(v.begin(), v.end(), [](const String& a, const String& b)
		{
			return a.size() < b.size();
		});

	std::cout << std::endl;
	std::cout << "===============정렬 후===============" << std::endl;
	std::cout << std::endl;

	//Save("main.cpp");
}