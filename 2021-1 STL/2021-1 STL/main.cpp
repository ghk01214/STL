//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 27일 목요일 (13주 2일)
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

// [문제] "단어들.txt"를 벡터에 저장하라
// 단어개 총 몇 개인지 출력하라
// vector<string>에 담아라

int main()
{
	std::ifstream in{ "단어들.txt" };
	std::vector<String> v{ std::istream_iterator<String>{in}, {} };

	Save("main.cpp");

	while (true)
	{

	}
}