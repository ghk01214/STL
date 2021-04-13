//������������������������������������������������������������
// 4�� 15�� ȭ���� (7�� 2��)
// 
// 1. sequence container
//	���Ҹ� ����.�߰��ϴ� ������ O(1)
//    - list
//    - forward_list
// 
// �߰���� - 4�� 22�� ����� (8�� 2��)
//������������������������������������������������������������

#include <list>
#include "pch.h"
#include "save.h"
#include "String.h"

// ��ü�� �ݺ��ڷ� ��ȸ�ϸ� �������

int main()
{
	std::list<String> c{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	c.sort([](const String& a, const String& b)
		{
			return a.size() < b.size();
		});

	for (const String& s : c)
	{
		std::cout << s << std::endl;
	}

	//Save("main.cpp");
}