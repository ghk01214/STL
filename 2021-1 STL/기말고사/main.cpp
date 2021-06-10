#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Test
{
public:
	Test() = default;
	Test(std::string str, int n) : name{ str }, id{ n } {}
	Test(int c) : name{ (char)c } {}
	void write(std::ostream& os) { os.write((char*)this, sizeof(Test)); }
	void show() const { std::cout << name << ", " << id << std::endl; }
public:
	std::string name;
	int id;
};

int main()
{
	std::string file1{ "시험1.dat" };
	std::string file2{ "시험2.dat" };

	std::ifstream in1{ file1, std::ios::binary };
	std::ifstream in2{ file2, std::ios::binary };

	if (!in1 or !in2)
	{
		std::cout << "파일을 열 수 없습니다." << std::endl;

		return 0;
	}

	// [문제 1]
	std::vector<Test> v1;
	std::vector<Test> v2;
	std::unique_ptr<Test> temp{ new Test };

	v1.reserve(210710);
	v2.reserve(210714);

	while (in1.read((char*)temp.get(), sizeof(Test)))
	{
		v1.emplace_back(temp->name, temp->id);
	}

	while (in2.read((char*)temp.get(), sizeof(Test)))
	{
		v2.emplace_back(temp->name, temp->id);
	}

	v1[10000].show();
	v2[10000].show();

	std::cout << v1.size() << ", " << v2.size() << std::endl;

	system("pause");
	system("cls");

	// [문제 2]
	// 112개
	std::vector<Test> v3;

	std::sort(v1.begin(), v1.end(), [](const Test& t1, const Test& t2)
		{
			return t1.name < t2.name;
		});

	std::sort(v2.begin(), v2.end(), [](const Test& t1, const Test& t2)
		{
			return t1.name < t2.name;
		});

	auto beg{ v1.begin() };

	for (auto iter = v2.begin(); iter != v2.end(); ++iter)
	{
		auto [st, en] {std::equal_range(beg, v1.end(), *iter, [](const Test& t1, const Test& t2)
			{
				return t1.name < t2.name;
			})};

		if (st + 1 == en)
			v3.emplace_back(st->name, st->id);

		beg = en;
	}

	std::cout << v3.size() << std::endl;

	// [문제 3]

	// [문제 4]
	// 8284개
	std::sort(v1.begin(), v1.end(), [](const Test& t1, const Test& t2)
		{
			return t1.name < t2.name;
		});

	auto begin{ v1.begin() };

	for (int i = 'a'; i <= 'z'; ++i)
	{
		auto [start, end] {std::equal_range(begin, v1.end(), i, [](const Test& t1, const Test& t2)
			{
				return t1.name[0] < t2.name[0];
			})};

		std::cout << (char)i << "로 시작하는 이름의 개수 - " << end - start << std::endl;

		begin = end;
	}
}