//������������������������������������������������������������
// 4�� 20�� ȭ���� (8�� 1��)
// 
// �ݺ��� : å 31 ~ 41, 123 ~ 136, Design Pattern �� iterator pattern
//  �ݺ��ڴ� �����͸� �߻�ȭ�� ���̴�.
//  �ݺ���ó�� �ൿ�ϴ� ���� �ݺ����̴�.
//  �ݺ��ڴ� container�� �����ϴ� �������̽��̴�.
// 
// �߰���� - 4�� 22�� ����� (8�� 2��)
//������������������������������������������������������������

#include <vector>
#include <iterator>
#include <list>
#include <forward_list>
#include <string>
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

	std::sort(s.begin(), s.end());

	//Save("main.cpp");
}