//������������������������������������������������������������
// 4�� 1�� ����� (5�� 2��)
// 
// vector = sequence containers that encapsulates dynamic size arrays
// ���� = ���� ũ���� �迭�� ������ sequence containers
//������������������������������������������������������������

#include <vector>
#include "pch.h"
#include "save.h"
#include "String.h"

// [����] vector��? - ����(�����Ͻÿ��� ũ�⸦ �� �� ����) �迭

int main()
{
	std::vector<int> v{ 1, 2, 3 };

	std::cout << "���� ���� : " << v.size() << std::endl;

	v.push_back(4);

	std::cout << "���� ���� : " << v.size() << std::endl;

	Save("main.cpp");
}