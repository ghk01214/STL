//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 20일 목요일 (12주 2일)
// 
// 알고리즘 함수 살펴보기
// 알고리즘 사용 예제(anagram)
// range, view
// 
// 기말고사 - 6월 10일 목요일
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [문제] v를 sort를 사용하여 홀짝으로 분리하라.

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::sort(v.begin(), v.end(), [](int n)
		{
			
		});


	Save("main.cpp");
}