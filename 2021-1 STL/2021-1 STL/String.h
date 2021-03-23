#pragma once
#include "pch.h"
#include <random>

class String
{
private:
	int cnt;
	char* alphabet;
	friend std::ostream& operator<<(std::ostream& os, const String s);
public:
	String();
	String(int num);
	String(const String& other);
	~String() { delete[] alphabet; }
public:
	String& operator=(const String& other);
	size_t size() const { return cnt; }
	void AscendingSort() { std::sort(alphabet, alphabet + cnt); }
};