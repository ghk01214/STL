//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 15일 목요일 (7주 2일)
// 
// 1. sequence container
//	원소를 삭제/추가하는 동작이 O(1)
//    - list
//    - forward_list
// 
// 중간고사 - 4월 22일 목요일 (8주 2일)
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <list>
#include <iterator>
#include "pch.h"
#include "save.h"
#include "String.h"

// [도전 문제] "main.cpp" 파일에 있는 단어를 뒤집어 출력하라.
// ex) gnisu scapseman ;dts

int main()
{
	std::list<int> l1{ 3, 7, 5, 1, 9, 7, 7, 7, 7, 7, 7 };
	
	// unique 함수는 연속된 인근의 원소들만 지운다.
	l1.unique();

	for (int a : l1)
	{
		std::cout << a << " ";
	}

	std::cout << std::endl;

	Save("main.cpp");
}