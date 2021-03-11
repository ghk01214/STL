//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 3월 11일 목요일 (2주 2일)
// 
// 많은 수의 데이터 다루기 - int에서 시작
// 갯수를 늘리며 자료가 저장되는 방식과 공간을 이해한다.
// 많은 수의 자료를 저장하는 방식을 알아본다
// 
// sort() 설명 다시 - 삼수의 역할/비교횟수 등을 살펴보자
// 객체를 많이 만들어 반복
// 
// 알고리즘 시간재기
// 스마트 포인터
// 
// 앞으로 사용할 class 만들어 두기
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include "pch.h"
#include "save.h"
#include <thread>
#include <chrono>

// [문제] 

int main()
{
	using namespace std::chrono_literals;

	// 스톱워치 시작
	//std::chrono::steady_clock::timepoint begin = std::chrono::steady_clock::now();
	auto begin = std::chrono::steady_clock::now();
	std::this_thread::sleep_for(333ms);

	// 스톱워치 끝

	std::cout << "경과 시간(밀리초) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << std::endl;
	//Save("main.cpp");
}