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

// [질문] vector란? - 동적(컴파일시에는 크기를 알 수 없는) 배열

int main()
{
	std::vector<int> v{ 1, 2, 3 };

	std::cout << "원소 개수 : " << v.size() << std::endl;

	v.push_back(4);

	std::cout << "원소 개수 : " << v.size() << std::endl;

	Save("main.cpp");
}