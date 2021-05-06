//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 06일 목요일 (10주2일)
// 
// Sequence Container - vector, deque, list...
// Associative Container - set / map			{ key, value }
// Unordered Associative Container - unordered_map
// 
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <set>
#include <iterator>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [문제] "main.cpp"의 단어를 읽어 오름차순으로 정렬한 후 출력하라.
// set으로 해결하라

int main()
{
	std::ifstream in{ "main.cpp" };
	std::multiset<std::string> s;			// multiset = 중복된 key 값을 허용

	std::copy(std::istream_iterator<std::string>{in}, {}, std::inserter(s, s.cbegin()));
	std::cout << std::endl;

	for (const std::string& str : s)
	{
		std::cout << str << std::endl;
	}

	//Save("main.cpp");
}