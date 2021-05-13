//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 13일 목요일 (11주 2일)
// 
// Sequence Container - vector, deque, list...
// Associative Container - set / map			{ key, value }
// Unordered Associative Container - unordered_map - 찾기 O(1)
// 
// map : pair<key, value>
//		연관배열로 사용한다. (통계처리에 유용)
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <unordered_set>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [문제] unordered_set의 메모리를 화면에 출력한다.
// 4부터 원소를 추가하여 메모리를 관찰하라.

int main()
{
	std::unordered_set<int> us{ 1, 2, 3 };
	
	for (int j{ 4 };; ++j)
	{
		if (j > 300)
		{
			std::cout << "key : ";
			char c;
			std::cin >> c;
		}

		us.insert(j);

		for (int i{ 0 }; i < us.bucket_count(); ++i)
		{
			std::cout << "[" << i << "]";

			// i번째 버킷의 원소 출력
			for (auto p{ us.begin(i) }; p != us.end(i); ++p)
			{
				std::cout << " → " << *p;
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	Save("main.cpp");
}