//������������������������������������������������������������
// 5�� 01�� ȭ���� (14�� 1��)
// 
// �˰��� �Լ� ���캸��
// �˰��� ��� ����(anagram)
// range, view
// 
// �⸻��� - 6�� 10�� �����
//������������������������������������������������������������

#include <vector>
#include <map>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [����] �� ������ ��� �ֳʱ׷� ���� ����϶�

struct ps : public std::pair<std::string, std::string>
{
	ps() = default;
	ps(std::string s) : pair<std::string, std::string>(s, s) { std::sort(first.begin(), first.end()); }
};

int main()
{
	std::ifstream in{ "�ܾ��.txt" };
	std::vector<ps> v{ std::istream_iterator<std::string>{in}, {} };
	
	std::sort(v.begin(), v.end(), [](const ps& a, const ps& b)
		{
			return a.first < b.first;
		});

	// ���̰� �� ������� �ܾ� 10���� ����϶�.

	std::cout << "Anagram�� ã�� ���α׷��̴�." << std::endl;
	std::cout << "�� " << v.size() << "���� ���ĵ� �ܾ �ִ�." << std::endl << std::endl;

	Save("main.cpp");

	while (true)
	{
		auto pos{ std::adjacent_find(v.begin(), v.end()) };

		
	}
}