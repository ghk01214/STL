//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 5월 18일 화요일 (12주 1일)
// 
// 대표 container의 찾기 실력 검증
// 1. vector		- O(n)
// 2. set			- O(log n)
// 3. unordered_set	- O(1)
// 
// 기말고사 - 6월 10일 목요일
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include <vector>
#include <set>
#include <unordered_set>
#include <array>
#include <chrono>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [문제] 찾을 대상 전체를 container에 저장한다.
// 그 중에서 특정 원소를 찾아	본다. (존재하는 객체와 같은 객체를 준비한다)
// 각 container 별로 걸리는 시간을 측정한다.
// 결과를 고찰한다.

const int num{ 10000 };		// 생성한 데이터 개수
const int fnum{ 10000 };		// 탐색할 개수

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> sel{ 1, 10000 };

template<>
struct std::hash<String>
{
	size_t operator()(const String& s) const
	{
		// s의 멤버는 int, string(char*)
		return std::hash<int>()(s.size());
	}
};

void Initialize(std::vector<String>& v, std::array<String, fnum>& arr);
void Vector(std::vector<String> v, std::array<String, fnum> arr);
void Set(std::vector<String> v, std::array<String, fnum> arr);
void UnorderedSet(std::vector<String> v, std::array<String, fnum> arr);

int main()
{
	std::vector<String> v;
	std::array<String, fnum> arr;

	Initialize(v, arr);
	Vector(v, arr);
	Set(v, arr);
	UnorderedSet(v, arr);

	//// [문제] set에서 같은 원소란 무엇인가?
	//std::cout << "set에서 같다는 것의 의미?" << std::endl;
	//std::cout << "동등(ejquivalence)하다는 의미(<)를 사용하기 때문이다." << std::endl;
	//std::cout << "상등(equality)은 ==로 같은것을 판단할 때를 의미한다." << std::endl;
	//// set은 a < b가 false를 return하고 b < a가 false를 return할 때 a == b라고 판단한다.

	//std::set<String> s{ 5, 1, 3 };

	//for (const String& s : s)
	//{
	//	std::cout << s << std::endl;
	//}

	//String x{ 3 };

	//std::cout << "3글자이지만 내용은 다르다 - " << x << std::endl;

	//if (s.find(x) == s.end())
	//	std::cout << "없음" << std::endl;
	//else
	//	std::cout << "있음" << std::endl;

	Save("main.cpp");
}

void Initialize(std::vector<String>& v, std::array<String, fnum>& arr)
{
	// vector에 String을 저장
	// 길이가 1부터 num까지의 길이를 가지는 String을 저장

	v.reserve(num);

	std::cout << "data 생성 시작" << std::endl;

	for (int i{ 0 }; i < num; ++i)
	{
		v.emplace_back(i + 1);
	}

	std::cout << "data 생성 종료" << std::endl;

	// 찾을 객체를 array에 저장한다
	for (int i{ 0 }; i < fnum; ++i)
	{
		arr[i] = v[sel(dre)];
	}

	// 10%는 존재하니 않는 자료로 만든다
	for (int i{ 0 }; i < fnum * 0.1; ++i)
	{
		arr[i] = std::move(String(sel(dre)));
	}
}

void Vector(std::vector<String> v, std::array<String, fnum> arr)
{
	// vector의 찾기 실력을 검증

	int cnt{ 0 };

	std::cout << std::endl;

	// 시간 시작
	auto start{ std::chrono::high_resolution_clock::now() };

	for (int j{ 0 }; j < 10; ++j)
	{
		for (int i{ 0 }; i < fnum; ++i)
		{
			if (std::find(v.begin(), v.end(), arr[i]) != v.end())
				++cnt;
		}
	}

	std::cout << "결과시간(밀리초) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;

	std::cout << "찾은 개수 - " << cnt << std::endl;
}

void Set(std::vector<String> v, std::array<String, fnum> arr)
{
	// set의 찾기 실력을 검증

	std::set<String> s{ v.begin(), v.end() };
	int cnt{ 0 };

	std::cout << std::endl;

	// 시간 시작
	auto start{ std::chrono::high_resolution_clock::now() };

	for (int j{ 0 }; j < 10; ++j)
	{
		for (int i{ 0 }; i < fnum; ++i)
		{
			if (s.find(arr[i]) != s.end())
				++cnt;
		}
	}

	std::cout << "결과시간(밀리초) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;

	std::cout << "찾은 개수 - " << cnt << std::endl;
}

void UnorderedSet(std::vector<String> v, std::array<String, fnum> arr)
{
	// unordered_set의 찾기 실력을 검증

	std::unordered_set<String> us{ v.begin(), v.end() };
	int cnt{ 0 };

	std::cout << std::endl;

	// 시간 시작
	auto start{ std::chrono::high_resolution_clock::now() };

	for (int j{ 0 }; j < 10; ++j)
	{
		for (int i{ 0 }; i < fnum; ++i)
		{
			if (us.find(arr[i]) != us.end())
				++cnt;
		}
	}

	std::cout << "결과시간(밀리초) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;

	std::cout << "찾은 개수 - " << cnt << std::endl;
}