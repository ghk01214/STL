//-----------------------------------------------------------------------------
// String.h - STL 내부 동작을 관찰하기 위해 만든 자원을 확보하는 클래스
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <random>
#include <string>
#include "pch.h"

//#define 관찰			// 이 주석을 풀면 special member의 동작을 알 수 있다.

// 2021. 4. 20
// String이 외부에 제공하는 반복자
class String_iterator
{
public:
	String_iterator() = default;
	String_iterator(char* p) : p{ p } {}
public:
	String_iterator operator+(int n) const { return String_iterator{ p + n }; }
	String_iterator operator-(int n) const { return String_iterator{ p - n }; }
	int operator-(const String_iterator& right) const { return p - right.p; }
public:
	String_iterator& operator++() { ++p; return *this; }
	String_iterator& operator--() { --p; return *this; }
public:
	char& operator*() { return *p; }
	char& operator*() const{ return *p; }
public:
	bool operator==(const String_iterator& right) const { return p == right.p; }
	bool operator!=(const String_iterator& right) const { return p != right.p; }
public:
	bool operator<(const String_iterator& right) { return p < right.p; }
private:
	char* p{ nullptr };
};

// 2021. 4. 27
// 역방향 반복자 추가
class String_reverse_iterator
{
public:
	String_reverse_iterator(char* p) : p{ p } {}
public:
	String_reverse_iterator& operator++() { --p; return *this; }
public:
	bool operator!=(const String_reverse_iterator& right) const { return right.p != p; }
public:
	char& operator*() { return *(p - 1); }
private:
	char* p{ nullptr };
};

template<>
struct std::iterator_traits<String_iterator>
{
	using iterator_concept = std::contiguous_iterator_tag;
	using iterator_category = std::random_access_iterator_tag;
	using ptrdiff_type = std::ptrdiff_t;
	using pointer = char*;
	using reference = char&;
	using value_type = char;
};

class String
{
private:
	// 2021. 4. 20
	using iterator = String_iterator;
	using value_type = char;
	// 2021. 4. 27
	using reverse_iterator = String_reverse_iterator;
public:
	String();
	String(size_t n);
	String(const char* str);
	~String();
public:
	String(const String& other);							// 복사생성자
	String& operator=(const String& other);					// 복사할당연산자

	String(String&& other) noexcept;						// 이동생성자
	String& operator=(String&& other)noexcept;				// 이동할당연산자
public:
	// 2021. 4. 20
	iterator begin() { return iterator{ p }; }
	iterator end() { return iterator{ p + num }; }
public:
	// 2021 4. 27
	iterator cbegin() const { return iterator{ p }; }
	iterator cend() const { return iterator{ p + num }; }
public:
	// 2021. 4. 27
	reverse_iterator rbegin() { return reverse_iterator{ p + num }; }
	reverse_iterator rend() { return reverse_iterator{ p }; }
public:
	size_t size() const { return num; }

	// 확보한 자원을 std::string처럼 이용할 수 있게 하자
	std::string get() const;
	void set(const std::string& s);
public:
	bool operator==(const String& right)
	{
		if (num != right.num)
		{
			return false;
		}
		
		for (int i{ 0 }; i < num; ++i)
		{
			if (p[i] != right.p[i])
			{
				return false;
			}
		}

		return true;
	}
private:
	size_t num;												// 확보한 자원의 수
	char* p;												// 확보한 자원의 위치
private:
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	// 2021. 5. 4
	friend std::istream& operator>>(std::istream& is, String& s);
};