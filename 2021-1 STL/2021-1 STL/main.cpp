//������������������������������������������������������������
// 5�� 27�� ����� (13�� 2��)
// 
// �˰��� �Լ� ���캸��
// �˰��� ��� ����(anagram)
// range, view
// 
// �⸻��� - 6�� 10�� �����
//������������������������������������������������������������

#include <vector>
#include <numeric>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [����] "�ܾ��.txt"�� ���Ϳ� �����϶�
// �ܾ �� �� ������ ����϶�
// vector<string>�� ��ƶ�

int main()
{
	std::ifstream in{ "�ܾ��.txt" };
	std::vector<String> v{ std::istream_iterator<String>{in}, {} };

	Save("main.cpp");

	while (true)
	{

	}
}