//������������������������������������������������������������
// 5�� 20�� ����� (12�� 2��)
// 
// �˰��� �Լ� ���캸��
// �˰��� ��� ����(anagram)
// range, view
// 
// �⸻��� - 6�� 10�� �����
//������������������������������������������������������������

#include <vector>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [����] v�� sort�� ����Ͽ� Ȧ¦���� �и��϶�.

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::sort(v.begin(), v.end(), [](int n)
		{
			
		});


	Save("main.cpp");
}