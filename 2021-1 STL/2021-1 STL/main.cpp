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

// [����] "main.cpp"�� �о� vector�� ������ ��
// �Ųٷ� ȭ�鿡 ����϶�.

int main()
{
	std::vector<char> v;
	char c{};

	std::ifstream in("main.cpp");

	while ((c = in.get()) != EOF)
	{
		v.push_back(c);
	}

	for (auto i{ v.rbegin() }; i != v.rend(); ++i)
	{
		std::cout << *i;
	}

	//std::copy(v.rbegin(), v.rend(), std::ostream_iterator<char>(std::cout));

	Save("main.cpp");
}