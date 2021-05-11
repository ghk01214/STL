//������������������������������������������������������������
// 5�� 11�� ȭ���� (11�� 1��)
// 
// Sequence Container - vector, deque, list...
// Associative Container - set / map			{ key, value }
// Unordered Associative Container - unordered_map
// 
// map : pair<key, value>
//		�����迭�� ����Ѵ�. (���ó���� ����)
//������������������������������������������������������������

#include <vector>
#include <map>			// key/value pair�̰� key = const
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [����] �׷� �̸��� �Է��ϸ� ����� �˷��ִ� map�� �����.
// �׷� �̸��� �Է��ϸ� ����� ����Ѵ�.
// (�׷� �̸��� ������ ����� �Է� �޾� ����� ���� �ִ�.)

int main()
{
	std::map<std::string, std::vector<std::string>> m;

	m.insert(std::pair<std::string, std::vector<std::string>>("aaa", { "1", "2", "3" }));
	m.insert(std::make_pair(std::string("�� �ý�����"), std::vector<std::string>{ "���μ�", "���μ�" }));
	m["����"] = { "��Ű��", "ö��7" };
	m["�ڿ���"] = { "������", "����", "����" };

	std::string groupName;

	while (true)
	{
		std::cout << "�׷� �̸� �Է� : ";
		std::cin >> groupName;

		auto p = m.find(groupName);
		int end = std::stoi(groupName);

		if (!end)
			break;

		if (p == m.end())
		{
			std::cout << groupName << "�� ���� �׷�." << std::endl;
			
			continue;
		}

		std::cout << "�׷� " << p->first << "�� ��� : ";

		for (const std::string& s : p->second)
		{
			std::cout << s << " ";
		}

		std::cout << std::endl << std::endl;
	}

	Save("main.cpp");
}