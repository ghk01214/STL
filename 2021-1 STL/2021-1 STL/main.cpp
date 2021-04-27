//������������������������������������������������������������
// 4�� 27�� ȭ���� (9�� 1��)
// 
// container, algorithm, �׸��� �� ���� �����ϴ� iterator
// 
// �ݺ��� : å 31 ~ 41, 123 ~ 136, Design Pattern �� iterator pattern
//  �ݺ��ڴ� �����͸� �߻�ȭ�� ���̴�.
//  �ݺ���ó�� �ൿ�ϴ� ���� �ݺ����̴�.
//  �ݺ��ڴ� container�� �����ϴ� �������̽��̴�.
//������������������������������������������������������������

#include <vector>
#include <iterator>
#include "pch.h"
#include "save.h"
#include "String.h"

// [����] String�� �ݺ��ڸ� �����Ѵ�.
// sort() �� �������� ����ǵ��� �ݺ��ڿ��� �ʿ��� �Լ����� �����ε��϶�

template<typename iter>
void showIteratorCategory(const iter&)
{
	std::cout << typeid(std::iterator_traits<iter>::iterator_category).name() << std::endl;
}

int main()
{
	String s{ "1357924680" };

	for (auto i{ s.rbegin() }; i != s.rend(); ++i)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl;

	//Save("main.cpp");
}