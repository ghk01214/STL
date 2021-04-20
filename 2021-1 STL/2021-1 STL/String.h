//-----------------------------------------------------------------------------
// String.h - STL ���� ������ �����ϱ� ���� ���� �ڿ��� Ȯ���ϴ� Ŭ����
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <random>
#include <string>
#include "pch.h"

//#define ����			// �� �ּ��� Ǯ�� special member�� ������ �� �� �ִ�.

// 2021. 4. 20
// String�� �ܺο� �����ϴ� �ݺ���
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
	String(const String& other);							// ���������
	String& operator=(const String& other);					// �����Ҵ翬����
	
	String(String&& other) noexcept;						// �̵�������
	String& operator=(String&& other)noexcept;				// �̵��Ҵ翬����
public:
	// 2021. 4. 20
	iterator begin() { return iterator{ p }; }
	iterator end() { return iterator{ p + num }; }
public:
	size_t size() const { return num; }

	// Ȯ���� �ڿ��� std::stringó�� �̿��� �� �ְ� ����
	std::string GetString() const;
private:
	size_t num;												// Ȯ���� �ڿ��� ��
	char* p;												// Ȯ���� �ڿ��� ��ġ
private:
	friend std::ostream& operator<<(std::ostream&, const String&);
};