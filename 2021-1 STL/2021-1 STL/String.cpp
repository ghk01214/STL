#include "String.h"

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<int> uid{ 'a', 'z' };
std::uniform_int_distribution<int> uid2{ 1, 200 };

String::String() : cnt{ uid2(dre) }, alphabet{ new char[cnt] }
{
#ifdef ����
	std::cout << "String() - ctor" << std::endl;
#endif

	for (int i = 0; i < cnt; ++i)
	{
		alphabet[i] = uid(dre);
	}
}

String::String(int num) : cnt{ num }, alphabet{ new char[num] }
{
#ifdef ����
	std::cout << "String(int)" << std::endl;
#endif

	for (int i = 0; i < num; ++i)
	{
		alphabet[i] = uid(dre);
	}
}

String::String(const String& other) : cnt{ other.cnt }, alphabet{ new char[cnt] }
{
	memcpy(alphabet, other.alphabet, cnt);
}

String::~String()
{
#ifdef ����
	std::cout << "~String() - p:" << (void*)alphabet << std::endl;
#endif

	delete[] alphabet;
}

std::ostream& operator<<(std::ostream& os, const String s)
{
	for (int i = 0; i < s.cnt; ++i)
		os << s.alphabet[i];

	return os;
}

String& String::operator=(const String& other)
{
	//std::cout << "�Ҵ� ";

	// �� �ڽſ� �Ҵ�Ǵ� ���� ����
	if (this != &other)
	{
		delete[] alphabet;

		cnt = other.cnt;
		alphabet = new char[cnt];
		memcpy(alphabet, other.alphabet, cnt);
	}

	return *this;
}
