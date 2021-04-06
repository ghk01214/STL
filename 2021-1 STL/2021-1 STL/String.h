//-----------------------------------------------------------------------------
// String.h - STL ���� ������ �����ϱ� ���� ���� �ڿ��� Ȯ���ϴ� Ŭ����
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <random>
#include <string>
#include "pch.h"

#define ����			// �� �ּ��� Ǯ�� special member�� ������ �� �� �ִ�.

class String
{
private:
	size_t num;							// Ȯ���� �ڿ��� ��
	char* p;							// Ȯ���� �ڿ��� ��ġ

	friend std::ostream& operator<<(std::ostream&, const String&);
public:
	String();
	String(size_t n);
	String(const char* str);
	~String();
public:
	String(const String& other);					// ���������
	String& operator=(const String& other);			// �����Ҵ翬����
	
	String(String&& other) noexcept;							// �̵�������
	String& operator=(String&& other)noexcept;				// �̵��Ҵ翬����
public:
	size_t size() const { return num; }

	// Ȯ���� �ڿ��� std::stringó�� �̿��� �� �ְ� ����
	std::string GetString() const;
};