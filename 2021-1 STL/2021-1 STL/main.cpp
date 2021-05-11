//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 11일 화요일 (11주 1일)
// 
// Sequence Container - vector, deque, list...
// Associative Container - set / map			{ key, value }
// Unordered Associative Container - unordered_map
// 
// map : pair<key, value>
//		연관배열로 사용한다. (통계처리에 유용)
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <map>			// key/value pair이고 key = const
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [문제] 그룹 이름을 입력하면 멤버를 알려주는 map을 만든다.
// 그룹 이름을 입력하면 멤버를 출력한다.
// (그룹 이름이 없으면 멤버를 입력 받아 등록할 수도 있다.)

int main()
{
	std::map<std::string, std::vector<std::string>> m;

	m.insert(std::pair<std::string, std::vector<std::string>>("aaa", { "1", "2", "3" }));
	m.insert(std::make_pair(std::string("펄 시스터즈"), std::vector<std::string>{ "배인순", "배인숙" }));
	m["게임"] = { "쿠키런", "철권7" };
	m["코요태"] = { "김종민", "빽가", "신지" };

	std::string groupName;

	while (true)
	{
		std::cout << "그룹 이름 입력 : ";
		std::cin >> groupName;

		auto p = m.find(groupName);
		int end = std::stoi(groupName);

		if (!end)
			break;

		if (p == m.end())
		{
			std::cout << groupName << "은 없는 그룹." << std::endl;
			
			continue;
		}

		std::cout << "그룹 " << p->first << "의 멤버 : ";

		for (const std::string& s : p->second)
		{
			std::cout << s << " ";
		}

		std::cout << std::endl << std::endl;
	}

	Save("main.cpp");
}