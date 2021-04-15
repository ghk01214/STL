//������������������������������������������������������������
// 4�� 15�� ����� (7�� 2��)
// 
// 1. sequence container
//	���Ҹ� ����/�߰��ϴ� ������ O(1)
//    - list
//    - forward_list
// 
// �߰���� - 4�� 22�� ����� (8�� 2��)
//������������������������������������������������������������

#include <list>
#include <iterator>
#include "pch.h"
#include "save.h"
#include "String.h"

// [���� ����] "main.cpp" ���Ͽ� �ִ� �ܾ ������ ����϶�.
// ex) gnisu scapseman ;dts

int main()
{
	std::list<int> l1{ 3, 7, 5, 1, 9, 7, 7, 7, 7, 7, 7 };
	
	// unique �Լ��� ���ӵ� �α��� ���ҵ鸸 �����.
	l1.unique();

	for (int a : l1)
	{
		std::cout << a << " ";
	}

	std::cout << std::endl;

	Save("main.cpp");
}