//������������������������������������������������������������
// 4�� 8�� ����� (6�� 2��)
// 
// vector<int>���� ¦���� �����Ѵ�
// �� remove�� ����°� ��¥�� �ƴϴ�.
// �� ���� ����� �� �ڷᱸ���� �ؾ� �Ѵ�.
// 
// �߰���� - 4�� 22�� ����� (8�� 2��)
//������������������������������������������������������������

#include <deque>
#include "pch.h"
#include "save.h"
#include "String.h"

// [����] v���� Ȧ���� �����϶�

int main()
{
	std::deque<String> d;

	d.emplace(d.end(), "back");
	d.emplace(d.end(), "front");

	for (const String& s : d)
	{
		std::cout << s << std::endl;
	}

	d.emplace(d.end(), "middle");

	for (const String& s : d)
	{
		std::cout << s << std::endl;
	}

	//Save("main.cpp");
}