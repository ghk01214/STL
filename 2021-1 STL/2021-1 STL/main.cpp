//������������������������������������������������������������
// 3�� 25�� ����� (4�� 2��)
//
// ������ ����� ������ class(�ڿ��� Ȯ���ϴ�) ����� �α�
//������������������������������������������������������������

#include "pch.h"
#include "save.h"
#include "String.h"
#include <vector>
#include <string>
#include <iterator>
#include <fstream>

// [����] ����ڰ� �Է��ϴ� �ܾ ������ ��
// ������������ �����Ͽ� ����϶�

int main()
{
	std::ifstream in{ "main.cpp" };
	//						  { ������,										  ������ }
	std::vector<std::string> v{ std::istream_iterator<std::string>{in}, {} };

	std::sort(v.begin(), v.end());

	//		 (������,	 ������,	  ȭ��(ȭ���� ���ƴٴϴ� ������)		)
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\t"));

	Save("main.cpp");
}