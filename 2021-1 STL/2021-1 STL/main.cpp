//������������������������������������������������������������
// 5�� 13�� ����� (11�� 2��)
// 
// Sequence Container - vector, deque, list...
// Associative Container - set / map			{ key, value }
// Unordered Associative Container - unordered_map - ã�� O(1)
// 
// map : pair<key, value>
//		�����迭�� ����Ѵ�. (���ó���� ����)
//������������������������������������������������������������

#include <unordered_set>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [����] unordered_set�� �޸𸮸� ȭ�鿡 ����Ѵ�.
// 4���� ���Ҹ� �߰��Ͽ� �޸𸮸� �����϶�.

int main()
{
	std::unordered_set<int> us{ 1, 2, 3 };
	
	for (int j{ 4 };; ++j)
	{
		if (j > 300)
		{
			std::cout << "key : ";
			char c;
			std::cin >> c;
		}

		us.insert(j);

		for (int i{ 0 }; i < us.bucket_count(); ++i)
		{
			std::cout << "[" << i << "]";

			// i��° ��Ŷ�� ���� ���
			for (auto p{ us.begin(i) }; p != us.end(i); ++p)
			{
				std::cout << " �� " << *p;
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	Save("main.cpp");
}