//������������������������������������������������������������
// 4�� 29�� ����� (9�� 2��)
// 
// Container - ���׸� Ŭ����, String([char][char][char]...), begin(), end()
// Iterator  - String_iterator, String_reverse_iterator
// Algorithm - ���׸� �Լ�
// 
//������������������������������������������������������������

#include <vector>
#include <algorithm>
#include "pch.h"
#include "save.h"
#include "String.h"

// [����] �� ������ �������� ����ǵ��� �϶�.

template<class RandIter, typename T>
RandIter my_find(RandIter begin, const RandIter& end, const T& val)
{
	for (; begin != end; ++begin)
	{
		if (*begin == val)
		{
			break;
		}
	}

	return begin;
}

int main()
{
	std::vector<String> v{ "123", "456", "abc" };

	auto p{ std::find(v.begin(), v.end(), String{ "abc" }) };

	std::cout << *p << std::endl;
	// ��� ��� : abc

	Save("main.cpp");
	Save("String.h");
}