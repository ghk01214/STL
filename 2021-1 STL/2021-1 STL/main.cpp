//������������������������������������������������������������
//x86 Release ��忡�� �ڵ�
//
// 3�� 9�� ������ (2�� 1��)
//
// Reference - �� �������� �ٸ� ������ ��ü�� access�ϴµ� ���
//
// ���� ���� ������ �ٷ�� - int���� ����
// ���� �ð� - sort() ���� �ٽ� - ����� ����/��Ƚ�� ���� ���캸��
//������������������������������������������������������������

#include "pch.h"
#include "save.h"

// [����] int 10���� ������ ������ �����Ѵ�
// int�� ������ ��(random engine�� ����)���� ������
// ȭ�鿡 int ���� �������
// ���� ������������ �����϶�
// ���� ����� ����϶�

// default_random_engine�� ũ�Ⱑ 5kb�̹Ƿ� stack�� �ֱ⿡�� �������ϴ�.
// ���� default_random_engine�� ��������ȭ�Ѵ�.
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

	// �����͸� ������������ ����
	std::cout << "�����մϴ�" << std::endl;
	//std::sort(�ڷ��� ������(����), �ڷ��� ������(����), ���� ���(�Լ�))
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