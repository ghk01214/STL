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
	String_iterator(char* p) : p{ p } {}
public:
	//int operator+(const String_iterator& right) const { return right.p + p; }
	int operator-(const String_iterator& right) const { return right.p - p; }
public:
	String_iterator& operator++() { ++p; return *this; }
	String_iterator& operator--() { --p; return *this; }
public:
	bool operator==(const String_iterator& right) const { return right.p == p; }
	bool operator!=(const String_iterator& right) const { return right.p != p; }
public:
	bool operator<(const String_iterator& right) { return p < right.p; }
private:
	char* p{ nullptr };
};

class String
{
	using iterator = String_iterator;
	using value_type = char;
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
	size_t size() const { return num; }

	// 확보한 자원을 std::string처럼 이용할 수 있게 하자
	std::string GetString() const;
private:
	size_t num;												// 확보한 자원의 수
	char* p;												// 확보한 자원의 위치
private:
	friend std::ostream& operator<<(std::ostream&, const String&);
};