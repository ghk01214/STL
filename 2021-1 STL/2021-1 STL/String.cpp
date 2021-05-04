#include "String.h"

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<int> uidAlpha{ 'a', 'z' };

String::String() : num{}, p{}
{
#ifdef 관찰
	std::cout << "생성자() (this: " << this << ") - 갯수: " << num << ", 위치: " << (void*)p << std::endl;
#endif
}

String::String(size_t n) : num{ n }, p{ new char[num] }
{
#ifdef 관찰
	std::cout << "생성자(int) (this: " << this << ") - 갯수: "<< num << ", 위치: " << (void*)p << std::endl;
#endif

	for (int i = 0; i < num; ++i)
		p[i] = uidAlpha(dre);
}

String::String(const char* str) : num{ strlen(str) }, p{ new char[num] }
{
	memcpy(p, str, num);

#ifdef 관찰
	std::cout << "생성자(const char*) (this: " << this << ") - 갯수: " << num << ", 위치: " << (void*)p << std::endl;
#endif
}

String::~String()
{
#ifdef 관찰
	std::cout << "소멸자 (this: " << this << ") - 갯수: " << num << ", 위치: " << (void*)p << std::endl;
#endif

	delete[] p;
}

// 복사생성자
String::String(const String& other) : num{ other.num }, p{ new char[num] }
{
	memcpy(p, other.p, num);

#ifdef 관찰
	std::cout << "복사생성자 (this: " << this << ") - 갯수: " << num << ", 위치: " << (void*)p << std::endl;
#endif
}

// 복사할당연산자
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] p;

		num = other.num;
		p = new char[num];

		memcpy(p, other.p, num);
	}

#ifdef 관찰
	std::cout << "복사할당연산자 (this: " << this << ") - 갯수: " << num << ", 위치: " << (void*)p << std::endl;
#endif

	return *this;
}

// 이동생성자
String::String(String&& other) noexcept : num{ other.num }
{
	p = other.p;
	other.p = nullptr;
	other.num = 0;

#ifdef 관찰
	std::cout << "이동생성자 (this: " << this << ") - 갯수: " << num << ", 위치: " << (void*)p << std::endl;
#endif
}

// 이동할당연산자
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

#ifdef 관찰
	std::cout << "이동할당연산자 (this: " << this << ") - 갯수: " << num << ", 위치: " << (void*)p << std::endl;
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
