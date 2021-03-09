//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 3월 9일 화요일 (2주 1일)
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
#include <numeric>

// [문제] int 100개를 400 바이트 공간에 기록하자
// int num[100개 값을 1부터 100으로 채우고
// 파일 "int 100개.txt"에 기록하라
// 파일 크기는 400 바이트가 되어야 한다

int main()
{
	int num[100]{};
	
	//숫자를 1부터 차례대로 채운다
	std::iota(std::begin(num), std::end(num), 1);

	std::ofstream out("int 100개.txt", std::ios::binary);

	out.write((char*)num, 100 * sizeof(int));

	Save("main.cpp");
}