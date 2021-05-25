//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 25일 화요일 (13주 1일)
// 
// 알고리즘 함수 살펴보기
// 알고리즘 사용 예제(anagram)
// range, view
// 
// 기말고사 - 6월 10일 목요일
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <numeric>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [문제] 홀짝으로 분리

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	std::stable_partition(v.begin(), v.end(), [](int n)
		{
			return n & 1;
		});

	for (int n : v)
	{
		std::cout << n << " ";
	}

	std::cout << std::endl;

	Save("main.cpp");
}