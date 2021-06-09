#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <iomanip>
#include <set>
#include <algorithm>

class Player
{
public:
	Player() = default;
	Player(int y, int m, std::string s) : year{ y }, month{ m }, name{ s } {}
	Player(int y) : year{ y } {}
	~Player() {}
public:
	int getYear() const { return year; }
	int getMonth() const { return month; }
	std::string getName() const { return name; }
	void show() const { std::cout << year << ", " << std::setw(2) << month << ", " << name << std::endl; }

	bool operator<(const Player& other) const
	{
		if (year == other.year)
			return name < other.name;

		return year < other.year;
	}

private:
	int year;
	int month;
	std::string name;
};

void makeData();
void vector();
void set();

int main()
{
	vector();
	//set();
}

void makeData()
{
	std::ofstream out{ "�⸻.dat", std::ios::binary };

	std::default_random_engine dre;
	std::uniform_int_distribution<int> year{ 1950, 2010 };
	std::uniform_int_distribution<int> month{ 1, 12 };
	std::uniform_int_distribution<int> name{ 'a', 'z' };
	std::uniform_int_distribution<int> len{ 3, 15 };

	for (int i = 0; i < 100000; ++i)
	{
		std::string s{};

		for (int j = 0; j < len(dre); ++j)
		{
			s += name(dre);
		}

		*s.begin() = std::toupper(*s.begin());

		Player p{ year(dre), month(dre), s };

		out.write((const char*)&p, sizeof(Player));
	}

	std::cout << "10������ ���� ������ ���Ͽ� ����Ͽ���." << std::endl;
}

void vector()
{
	std::vector<Player> v;

	makeData();

	// [���� 1] "�⸻.dat" ���Ͽ� ��ϵ� ���� ������ �����̳ʷ� �о� �Ͷ�.
	// ���� ������ ����(10����° ����)�� ������ show()�� ����϶�. 
	// ȭ�鿡 ��µ� ���� ������ ������ �����.
	std::ifstream in{ "�⸻.dat", std::ios::binary };
	Player* temp{ new Player };

	v.reserve(100000);

	while (in.read((char*)temp, sizeof(Player)))
	{
		v.emplace_back(temp->getYear(), temp->getMonth(), temp->getName());
	}

	v.rbegin()->show();

	system("pause");
	system("cls");

	// [���� 2] �����̳ʿ� ������ ���� ������ �����϶�.
	// ���� ������ ���� ���������̴�. ������ ���� ��쿡�� �̸��� ������������ ���ĵǾ�� �Ѵ�.
	// ���ĵ� �����̳��� ���� ������ ���� ������ ������ �����.

	std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
		{
			return a < b;
		});

	v.rbegin()->show();

	system("pause");
	system("cls");

	// [���� 3] �� ������ ���� ������ �����ǵ��� ���� �÷��̾� p�� �����̳ʿ� �߰��϶�.
	// p ������ �ִ� ������ ������ ������ �����.

	Player p{ 1999, 1, "test" };

	auto pos{ std::lower_bound(v.begin(), v.end(), Player{ p }, [](const Player& a, const Player& b)
		{
			return a < b;
		}) };

	v.emplace(pos, p.getYear(), p.getMonth(), p.getName());

	pos = std::upper_bound(v.begin(), v.end(), Player{ p }, [](const Player& a, const Player& b)
		{
			return a < b;
		});

	pos->show();

	system("pause");
	system("cls");

	// [���� 4] �� ������ �÷��̾��� ���� ����϶�.
	// 1950�� - �� ��
	// 1951�� - �� ��
	// 
	// �߰��� ������
	// 
	// 2010�� - �� ��
	// �� ���� ��µǵ��� �� ��.
	// 
	// ��µǴ� ������ 2010�� �÷��̾��� ���� ������� ���ƶ�.
	// (���� �˰������� �ϳ��� ���� ���� ����)

	auto start{ v.begin() };

	for (int year = 1950; year <= 2010; ++year)
	{
		auto [lowBound, upBound] {std::equal_range(start, v.end(), Player{ year }, [](const Player& a, const Player& b)
			{
				return a.getYear() < b.getYear();
			})};

		std::cout << year << ": " << upBound - lowBound << "��" << std::endl;

		start = upBound;
	}
}

void set()
{
	std::vector<Player> v;

	makeData();

	// [���� 1] "�⸻.dat" ���Ͽ� ��ϵ� ���� ������ �����̳ʷ� �о� �Ͷ�.
	// ���� ������ ����(10����° ����)�� ������ show()�� ����϶�. 
	// ȭ�鿡 ��µ� ���� ������ ������ �����.
	std::ifstream in{ "�⸻.dat", std::ios::binary };
	Player* temp = new Player;

	v.reserve(100000);

	while (in.read((char*)temp, sizeof(Player)))
	{
		v.emplace_back(temp->getYear(), temp->getMonth(), temp->getName());
	}

	v.crbegin()->show();

	system("pause");
	system("cls");

	// [���� 2] �����̳ʿ� ������ ���� ������ �����϶�.
	// ���� ������ ���� ���������̴�. ������ ���� ��쿡�� �̸��� ������������ ���ĵǾ�� �Ѵ�.
	// ���ĵ� �����̳��� ���� ������ ���� ������ ������ �����.

	std::multiset<Player> s(v.begin(), v.end());

	s.crbegin()->show();

	system("pause");
	system("cls");

	// [���� 3] �� ������ ���� ������ �����ǵ��� ���� �÷��̾� p�� �����̳ʿ� �߰��϶�.
	// p ������ �ִ� ������ ������ ������ �����.

	Player p{ 1999, 1, "test" };

	s.emplace(p.getYear(), p.getMonth(), p.getName());
	(++s.find(p))->show();

	system("pause");
	system("cls");

	// [���� 4] �� ������ �÷��̾��� ���� ����϶�.
	// 1950�� - �� ��
	// 1951�� - �� ��
	// 
	// �߰��� ������
	// 
	// 2010�� - �� ��
	// �� ���� ��µǵ��� �� ��.
	// 
	// ��µǴ� ������ 2010�� �÷��̾��� ���� ������� ���ƶ�.
	// (���� �˰������� �ϳ��� ���� ���� ����)

	auto start{ s.begin() };
	int total{};

	for (int year = 1950; year <= 2010; ++year)
	{
		auto [lowBound, upBound] {std::equal_range(start, s.end(), year, [](const Player& a, const Player& b)
			{
				return a.getYear() < b.getYear();
			})};

		std::cout << year << " - " << std::distance(lowBound, upBound) << "��" << std::endl;

		start = upBound;
		total += std::distance(lowBound, upBound);
	}

	std::cout << total << std::endl;
}