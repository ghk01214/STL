//������������������������������������������������������������
// 4�� 8�� ����� (6�� 2��)
// 
// vector<int>���� ¦���� �����Ѵ�
// vector<int> �߰��� ���Ҹ� �߰��� ����
//������������������������������������������������������������

#include <algorithm>
#include <vector>
#include "pch.h"
#include "save.h"
#include "String.h"

int main()
{
	std::vector<String> v{ 20, 10, 30 };

	// v�� ���� ������������ �����Ͻÿ�

	std::cout << std::endl;
	std::cout << "===============���� ��===============" << std::endl;
	std::cout << std::endl;

	std::sort(v.begin(), v.end(), [](const String& a, const String& b)
		{
			return a.size() < b.size();
		});

	std::cout << std::endl;
	std::cout << "===============���� ��===============" << std::endl;
	std::cout << std::endl;

	//Save("main.cpp");
}