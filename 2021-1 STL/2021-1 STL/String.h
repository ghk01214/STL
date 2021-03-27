#pragma once
#include "pch.h"
#include <random>

// 밑줄에 주석을 제거하면 출력메시지 미출력
#define 관찰

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
	~String();
public:
	String& operator=(const String& other);
	size_t size() const { return cnt; }
	void AscendingSort() { std::sort(alphabet, alphabet + cnt); }
};