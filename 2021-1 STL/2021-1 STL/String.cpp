#include "String.h"

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<int> uidAlpha{ 'a', 'z' };

String::String() : num{}, p{}
{
#ifdef ����
	std::cout << "������() (this: " << this << ") - ����: " << num << ", ��ġ: " << (void*)p << std::endl;
#endif
}

String::String(size_t n) : num{ n }, p{ new char[num] }
{
#ifdef ����
	std::cout << "������(int) (this: " << this << ") - ����: "<< num << ", ��ġ: " << (void*)p << std::endl;
#endif

	for (int i = 0; i < num; ++i)
		p[i] = uidAlpha(dre);
}

String::String(const char* str) : num{ strlen(str) }, p{ new char[num] }
{
	memcpy(p, str, num);

#ifdef ����
	std::cout << "������(const char*) (this: " << this << ") - ����: " << num << ", ��ġ: " << (void*)p << std::endl;
#endif
}

String::~String()
{
#ifdef ����
	std::cout << "�Ҹ��� (this: " << this << ") - ����: " << num << ", ��ġ: " << (void*)p << std::endl;
#endif

	delete[] p;
}

// ���������
String::String(const String& other) : num{ other.num }, p{ new char[num] }
{
	memcpy(p, other.p, num);

#ifdef ����
	std::cout << "��������� (this: " << this << ") - ����: " << num << ", ��ġ: " << (void*)p << std::endl;
#endif
}

// �����Ҵ翬����
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] p;

		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);
	}

#ifdef ����
	std::cout << "�����Ҵ翬���� (this: " << this << ") - ����: " << num << ", ��ġ: " << (void*)p << std::endl;
#endif

	return *this;
}

// �̵�������
String::String(String&& other) noexcept : num{ other.num }
{
	p = other.p;
	other.p = nullptr;
	other.num = 0;

#ifdef ����
	std::cout << "�̵������� (this: " << this << ") - ����: " << num << ", ��ġ: " << (void*)p << std::endl;
#endif
}

// �̵��Ҵ翬����
String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		delete[] p;

		num = other.num;
		p = other.p;

		other.num = 0;
		other.p = nullptr;
	}

#ifdef ����
	std::cout << "�̵��Ҵ翬���� (this: " << this << ") - ����: " << num << ", ��ġ: " << (void*)p << std::endl;
#endif

	return *this;
}

std::string String::get() const
{
	return std::string(p, p + num);
}

void String::set(const std::string& s)
{
	num = s.length();
	p = new char[num];

	for (int i{ 0 }; i < num; ++i)
		p[i] = s[i];
}


std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i{ 0 }; i < s.num; ++i)
		os << s.p[i];

	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	std::string str;
	
	is >> str;
	s.set(str);

	return is;
}
