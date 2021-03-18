//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 3월 18일 목요일 (3주 2일)
//
// 호출 가능한 타입 - callable type
// 
// 앞으로 사용할 관찰용 class(자원을 확보하는) 만들어 두기
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include "pch.h"
#include "save.h"
#include <thread>

// 쿠키런
// 왼쪽 버튼: 점프, 오른쪽 버튼: 슬라이드
// 
// 설정에 가서 버튼을 변경
// 프로그램 구현은 어떻게 되었나?

void jump()
{
	std::cout << "점프" << std::endl;
}

void slide()
{
	std::cout << "슬라이드" << std::endl;
}

void (*left_function)(void) = jump;
void (*right_function)(void) = slide;

void left()
{
	left_function();
}

void right()
{
	right_function();
}

int main()
{
	Save("main.cpp");

	using namespace std::literals::chrono_literals;

	// 10번에 1번은 기능을 변경

	int cnt{};

	while (true)
	{
		left();
		std::this_thread::sleep_for(500ms);

		++cnt;

		if (cnt % 10 == 0)
		{
			left_function = slide;
		}
	}
}