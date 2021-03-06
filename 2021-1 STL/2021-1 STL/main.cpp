//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 6월 08일 화요일 (15주 1일)
// 
// 강의 정리
// 
// 기말고사 - 6월 10일 목요일
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <ranges>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream

int main()
{
	std::vector<int> v{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// v에서 홀수만 골라 값을 10배로 만든 후 출력하라.

	for (int n : v
		| std::views::filter([](int a) { return a & 1; })
		| std::views::transform([](int& a) { return a *= 10; })
		)
	{
		std::cout << n << std::endl;
	}

	std::cout << std::endl;

	for (int n : v)
	{
		std::cout << n << std::endl;
	}

	Save("main.cpp");
}