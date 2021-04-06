//-----------------------------------------------------------------------------
// String.h - STL 내부 동작을 관찰하기 위해 만든 자원을 확보하는 클래스
//
// 2021. 3. 30									Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <random>
#include <string>
#include "pch.h"

#define 관찰			// 이 주석을 풀면 special member의 동작을 알 수 있다.

class String
{
private:
	size_t num;							// 확보한 자원의 수
	char* p;							// 확보한 자원의 위치

	friend std::ostream& operator<<(std::ostream&, const String&);
public:
	String();
	String(size_t n);
	String(const char* str);
	~String();
public:
	String(const String& other);					// 복사생성자
	String& operator=(const String& other);			// 복사할당연산자
	
	String(String&& other) noexcept;							// 이동생성자
	String& operator=(String&& other)noexcept;				// 이동할당연산자
public:
	size_t size() const { return num; }

	// 확보한 자원을 std::string처럼 이용할 수 있게 하자
	std::string GetString() const;
};