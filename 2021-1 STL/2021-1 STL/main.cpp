//������������������������������������������������������������
// 6�� 03�� ����� (14�� 2��)
// 
// �˰��� �Լ� ���캸��
// �˰��� ��� ����(anagram)
// range, view
// 
// �⸻��� - 6�� 10�� �����
//������������������������������������������������������������

#include <vector>
#include <ranges>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream

int main()
{
	std::vector<int> v{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	// v���� Ȧ���� ��� ���� 10��� ���� �� ����϶�.

	for (int n : v
		| std::views::filter([](int a) { return a & 1; })
		| std::views::transform([](int& a) { return a *= 10; })
		)
	{
		std::cout << n << std::endl;
	}

	std::cout << std::endl;

	for (int n : v)
	{
		std::cout << n << std::endl;
	}

	Save("main.cpp");
}