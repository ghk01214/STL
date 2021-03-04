//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
//x86 Release 모드에서 코딩
//
// 3월 9일 월요일 (2주 1일)
//
// Reference - 한 지역에서 다른 지역의 객체에 access하는데 사용
//
// 많은 수의 데이터 다루기 - int에서 시작
// 다음 시간 - sort() 설명 다시 - 삼수의 역할/비교횟수 등을 살펴보자
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include "pch.h"
#include "save.h"

// [문제] int 10개를 저장할 공간을 마련한다
// int를 임의의 값(random engine과 분포)으로 만들자
// 화면에 int 값을 출력하자
// 값을 내림차순으로 정렬하라
// 정렬 결과를 출력하라

// default_random_engine의 크기가 5kb이므로 stack에 넣기에는 부적절하다.
// 따라서 default_random_engine을 전역변수화한다.
std::random_device rd;
std::default_random_engine gen(rd());

int main()
{
	int num[20];

	std::uniform_int_distribution<int> dis(0, 1000);

	for (int& i : num)
	{
		i = dis(gen);
	}

	// 데이터를 내림차순으로 정렬
	std::cout << "정렬합니다" << std::endl;
	//std::sort(자료의 시작점(숫자), 자료의 종착점(숫자), 정렬 방법(함수))
	std::sort(std::begin(num), std::end(num), [](int a, int b)
		{
			return a > b;
		});

	for (int i : num)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	Save("main.cpp");
}