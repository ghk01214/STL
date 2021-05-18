//������������������������������������������������������������
// 5�� 18�� ȭ���� (12�� 1��)
// 
// ��ǥ container�� ã�� �Ƿ� ����
// 1. vector		- O(n)
// 2. set			- O(log n)
// 3. unordered_set	- O(1)
// 
// �⸻��� - 6�� 10�� �����
//������������������������������������������������������������

#include <vector>
#include <set>
#include <unordered_set>
#include <array>
#include <chrono>
#include "pch.h"		// iostream, algorithm
#include "save.h"		// string_view, filesystem, fstream
#include "String.h"		// random, string

// [����] ã�� ��� ��ü�� container�� �����Ѵ�.
// �� �߿��� Ư�� ���Ҹ� ã��	����. (�����ϴ� ��ü�� ���� ��ü�� �غ��Ѵ�)
// �� container ���� �ɸ��� �ð��� �����Ѵ�.
// ����� �����Ѵ�.

const int num{ 10000 };		// ������ ������ ����
const int fnum{ 10000 };		// Ž���� ����

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> sel{ 1, 10000 };

template<>
struct std::hash<String>
{
	size_t operator()(const String& s) const
	{
		// s�� ����� int, string(char*)
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

	//// [����] set���� ���� ���Ҷ� �����ΰ�?
	//std::cout << "set���� ���ٴ� ���� �ǹ�?" << std::endl;
	//std::cout << "����(ejquivalence)�ϴٴ� �ǹ�(<)�� ����ϱ� �����̴�." << std::endl;
	//std::cout << "���(equality)�� ==�� �������� �Ǵ��� ���� �ǹ��Ѵ�." << std::endl;
	//// set�� a < b�� false�� return�ϰ� b < a�� false�� return�� �� a == b��� �Ǵ��Ѵ�.

	//std::set<String> s{ 5, 1, 3 };

	//for (const String& s : s)
	//{
	//	std::cout << s << std::endl;
	//}

	//String x{ 3 };

	//std::cout << "3���������� ������ �ٸ��� - " << x << std::endl;

	//if (s.find(x) == s.end())
	//	std::cout << "����" << std::endl;
	//else
	//	std::cout << "����" << std::endl;

	Save("main.cpp");
}

void Initialize(std::vector<String>& v, std::array<String, fnum>& arr)
{
	// vector�� String�� ����
	// ���̰� 1���� num������ ���̸� ������ String�� ����

	v.reserve(num);

	std::cout << "data ���� ����" << std::endl;

	for (int i{ 0 }; i < num; ++i)
	{
		v.emplace_back(i + 1);
	}

	std::cout << "data ���� ����" << std::endl;

	// ã�� ��ü�� array�� �����Ѵ�
	for (int i{ 0 }; i < fnum; ++i)
	{
		arr[i] = v[sel(dre)];
	}

	// 10%�� �����ϴ� �ʴ� �ڷ�� �����
	for (int i{ 0 }; i < fnum * 0.1; ++i)
	{
		arr[i] = std::move(String(sel(dre)));
	}
}

void Vector(std::vector<String> v, std::array<String, fnum> arr)
{
	// vector�� ã�� �Ƿ��� ����

	int cnt{ 0 };

	std::cout << std::endl;

	// �ð� ����
	auto start{ std::chrono::high_resolution_clock::now() };

	for (int j{ 0 }; j < 10; ++j)
	{
		for (int i{ 0 }; i < fnum; ++i)
		{
			if (std::find(v.begin(), v.end(), arr[i]) != v.end())
				++cnt;
		}
	}

	std::cout << "����ð�(�и���) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;

	std::cout << "ã�� ���� - " << cnt << std::endl;
}

void Set(std::vector<String> v, std::array<String, fnum> arr)
{
	// set�� ã�� �Ƿ��� ����

	std::set<String> s{ v.begin(), v.end() };
	int cnt{ 0 };

	std::cout << std::endl;

	// �ð� ����
	auto start{ std::chrono::high_resolution_clock::now() };

	for (int j{ 0 }; j < 10; ++j)
	{
		for (int i{ 0 }; i < fnum; ++i)
		{
			if (s.find(arr[i]) != s.end())
				++cnt;
		}
	}

	std::cout << "����ð�(�и���) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;

	std::cout << "ã�� ���� - " << cnt << std::endl;
}

void UnorderedSet(std::vector<String> v, std::array<String, fnum> arr)
{
	// unordered_set�� ã�� �Ƿ��� ����

	std::unordered_set<String> us{ v.begin(), v.end() };
	int cnt{ 0 };

	std::cout << std::endl;

	// �ð� ����
	auto start{ std::chrono::high_resolution_clock::now() };

	for (int j{ 0 }; j < 10; ++j)
	{
		for (int i{ 0 }; i < fnum; ++i)
		{
			if (us.find(arr[i]) != us.end())
				++cnt;
		}
	}

	std::cout << "����ð�(�и���) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << std::endl;

	std::cout << "ã�� ���� - " << cnt << std::endl;
}