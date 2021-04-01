//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 1일 목요일 (5주 2일)
// 
// vector = sequence containers that encapsulates dynamic size arrays
// 벡터 = 동적 크기의 배열을 포장한 sequence containers
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include "pch.h"
#include "save.h"
#include "String.h"

// [문제] "main.cpp"를 읽어 vector에 저장한 후
// 거꾸로 화면에 출력하라.

int main()
{
	std::vector<char> v;
	char c{};

	std::ifstream in("main.cpp");

	while ((c = in.get()) != EOF)
	{
		v.push_back(c);
	}

	for (auto i{ v.rbegin() }; i != v.rend(); ++i)
	{
		std::cout << *i;
	}

	//std::copy(v.rbegin(), v.rend(), std::ostream_iterator<char>(std::cout));

	Save("main.cpp");
}