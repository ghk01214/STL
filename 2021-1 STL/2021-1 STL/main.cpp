//������������������������������������������������������������
// 3�� 18�� ����� (3�� 2��)
//
// 
// 
// ������ ����� ������ class(�ڿ��� Ȯ���ϴ�) ����� �α�
//������������������������������������������������������������

#include "pch.h"
#include "save.h"
#include <random>

// [����] int num�� ���ڷ� �޾� �޸𸮸� num ����Ʈ �Ҵ�޾�
// ������ ���ĺ� �ҹ��ڷ� ä��� Ŭ���� String�� �����϶�
//
// ���� main()�� �ǵ���� ����ǰ� ����

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> uid('a', 'z');

class String
{
private:
	int cnt;
	char* alphabet;

	friend std::ostream& operator<<(std::ostream& os, const String s);
public:
	String(int num) : cnt{ num }, alphabet{ new char[num] }
	{
		//std::unique_ptr<char[]> alphabet{ new char[num] };

		for (int i = 0; i < num; ++i)
		{
			alphabet[i] = uid(dre);
		}
	}
	~String() { delete[] alphabet; }

	size_t size()
	{

	}
};

std::ostream& operator<<(std::ostream& os, const String s)
{
	for (int i = 0; i < s.cnt; ++i)
		os << i + 1 << ". " << s.alphabet[i] << std::endl;

	return os;
}

int main()
{
	String s[10]{ 20, 21, 3, 14, 12, 7, 5, 8, 32, 2 };

	// ���� ������������ �����϶�
	std::sort(std::begin(s), std::end(s), [](const String& a, const String& b)
		{
			return a.size() < b.size();
		});
	
	for (String& s : s)
		std::cout << s << std::endl;

	//Save("main.txt");
}