//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 3월 25일 목요일 (4주 2일)
//
// 앞으로 사용할 관찰용 class(자원을 확보하는) 만들어 두기
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include "pch.h"
#include "save.h"
#include "String.h"
#include <vector>
#include <string>
#include <iterator>
#include <fstream>

// [문제] 사용자가 입력하는 단어를 저장한 후
// 오름차순으로 정렬하여 출력하라

int main()
{
	std::ifstream in{ "main.cpp" };
	//						  { 시작점,										  종단점 }
	std::vector<std::string> v{ std::istream_iterator<std::string>{in}, {} };

	std::sort(v.begin(), v.end());

	//		 (시작점,	 종단점,	  화면(화면을 돌아다니는 포인터)		)
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\t"));

	Save("main.cpp");
}