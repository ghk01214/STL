//������������������������������������������������������������
// 5�� 06�� ����� (10��2��)
// 
// Sequence Container - vector, deque, list...
// Associative Container - set / map			{ key, value }
// Unordered Associative Container - unordered_map
// 
//������������������������������������������������������������

#include <set>
#include <iterator>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [����] "main.cpp"�� �ܾ �о� ������������ ������ �� ����϶�.
// set���� �ذ��϶�

int main()
{
	std::ifstream in{ "main.cpp" };
	std::multiset<std::string> s;			// multiset = �ߺ��� key ���� ���

	std::copy(std::istream_iterator<std::string>{in}, {}, std::inserter(s, s.cbegin()));
	std::cout << std::endl;

	for (const std::string& str : s)
	{
		std::cout << str << std::endl;
	}

	//Save("main.cpp");
}