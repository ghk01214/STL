//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 3월 25일 목요일 (4주 2일)
// 
// Containers: objects that store other objects
// 자료구조: 다른 객체를 저장하는 객체
// 
// Sequence Containers
// - array
// - vector
// - deque
// - forward_list
// - list
// 
// 관찰 class에 이동기능 코딩 - sort 함수로 확인
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include "pch.h"
#include "save.h"
#include "String.h"

// [실습] main이 실행될 수 있게 Array를 프로그램하라

template<typename T, int N>
class Array
{
private:
	T data[N]{ 0 };
public:
	Array() {}
public:
	size_t size() const { return N; }

	T* begin() { return data; }
	T* end() { return data + N; }
public:
	T operator[](int idx) const { return data[idx]; }
	T& operator[](int idx) { return data[idx]; }
};

int main()
{
	Array<String, 10> a;

	for (int i = 0; i < a.size(); ++i)
	{
		a[i] = i * i;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << std::endl;
	}

	std::cout << "\n반복자로 출력" << std::endl;
	
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	Save("main.cpp");
}