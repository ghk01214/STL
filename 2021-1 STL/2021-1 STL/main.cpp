//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 01일 화요일 (14주 1일)
// 
// 알고리즘 함수 살펴보기
// 알고리즘 사용 예제(anagram)
// range, view
// 
// 기말고사 - 6월 10일 목요일
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <map>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [문제] 이 사전의 모든 애너그램 쌍을 출력하라

struct ps : public std::pair<std::string, std::string>
{
	ps() = default;
	ps(std::string s) : pair<std::string, std::string>(s, s) { std::sort(first.begin(), first.end()); }
};

int main()
{
	std::ifstream in{ "단어들.txt" };
	std::vector<ps> v{ std::istream_iterator<std::string>{in}, {} };
	
	std::sort(v.begin(), v.end(), [](const ps& a, const ps& b)
		{
			return a.first < b.first;
		});

	// 길이가 긴 순서대로 단어 10개를 출력하라.

	std::cout << "Anagram을 찾는 프로그램이다." << std::endl;
	std::cout << "총 " << v.size() << "개의 정렬된 단어가 있다." << std::endl << std::endl;

	Save("main.cpp");

	while (true)
	{
		auto pos{ std::adjacent_find(v.begin(), v.end()) };

		
	}
}