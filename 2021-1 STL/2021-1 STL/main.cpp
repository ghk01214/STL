//������������������������������������������������������������
// 3�� 18�� ����� (3�� 2��)
//
// ȣ�� ������ Ÿ�� - callable type
// 
// ������ ����� ������ class(�ڿ��� Ȯ���ϴ�) ����� �α�
//������������������������������������������������������������

#include "pch.h"
#include "save.h"
#include <thread>

// ��Ű��
// ���� ��ư: ����, ������ ��ư: �����̵�
// 
// ������ ���� ��ư�� ����
// ���α׷� ������ ��� �Ǿ���?

void jump()
{
	std::cout << "����" << std::endl;
}

void slide()
{
	std::cout << "�����̵�" << std::endl;
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

	// 10���� 1���� ����� ����

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