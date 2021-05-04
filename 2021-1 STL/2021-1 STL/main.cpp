//������������������������������������������������������������
// 5�� 06�� ����� (10��2��)
// 
// Container - ���׸� Ŭ����, String([char][char][char]...), begin(), end()
// Iterator  - String_iterator, String_reverse_iterator
// Algorithm - ���׸� �Լ�
// 
//������������������������������������������������������������

#include <vector>
#include <string>
#include <list>
#include "pch.h"
#include "save.h"
#include "String.h"

// [����] �ݺ��� ���� �Ÿ��� ����ϴ� distance�� �ۼ��϶�.

template<class Iter>
ptrdiff_t my_distance(Iter begin, Iter end)
{
	// random_access_iterator
	// �۵� �� ��
	if (std::random_access_iterator_tag<Iter>)
		return end - begin;

	ptrdiff_t distance{};

	for (; begin != end; ++begin)
	{
		++distance;
	}

	return distance;
}

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5 };
	std::cout << my_distance(v.cbegin(), v.cend()) << std::endl;

	std::list<int> l{ 1, 2, 3, 4, 5 };
	std::cout << my_distance(l.cbegin(), l.cend()) << std::endl;

	//Save("main.cpp");
}