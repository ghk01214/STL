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
	std::ofstream out{ "기말.dat", std::ios::binary };

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

	std::cout << "10만명의 선수 정보를 파일에 기록하였다." << std::endl;
}

void vector()
{
	std::vector<Player> v;

	makeData();

	// [문제 1] "기말.dat" 파일에 기록된 선수 정보를 컨테이너로 읽어 와라.
	// 제일 마지막 선수(10만번째 선수)의 정보를 show()로 출력하라. 
	// 화면에 출력된 선수 정보를 답지에 적어라.
	std::ifstream in{ "기말.dat", std::ios::binary };
	Player* temp{ new Player };

	v.reserve(100000);

	while (in.read((char*)temp, sizeof(Player)))
	{
		v.emplace_back(temp->getYear(), temp->getMonth(), temp->getName());
	}

	v.rbegin()->show();

	system("pause");
	system("cls");

	// [문제 2] 컨테이너에 저장한 선수 정보를 정렬하라.
	// 정렬 순서는 연도 오름차순이다. 연도가 같은 경우에는 이름도 오름차순으로 정렬되어야 한다.
	// 정렬된 컨테이너의 제일 마지막 선수 정보를 답지에 적어라.

	std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
		{
			return a < b;
		});

	v.rbegin()->show();

	system("pause");
	system("cls");

	// [문제 3] 위 문제의 정렬 순서가 유지되도록 다음 플레이어 p를 컨테이너에 추가하라.
	// p 다음에 있는 선수의 정보를 답지에 적어라.

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

	// [문제 4] 각 연도별 플레이어의 수를 출력하라.
	// 1950년 - 몇 명
	// 1951년 - 몇 명
	// 
	// 중간은 생략함
	// 
	// 2010년 - 몇 명
	// 와 같이 출력되도록 할 것.
	// 
	// 출력되는 내용중 2010년 플레이어의 수는 답안지에 적아라.
	// (선형 알고리즘으로 하나씩 세는 답은 감점)

	auto start{ v.begin() };

	for (int year = 1950; year <= 2010; ++year)
	{
		auto [lowBound, upBound] {std::equal_range(start, v.end(), Player{ year }, [](const Player& a, const Player& b)
			{
				return a.getYear() < b.getYear();
			})};

		std::cout << year << ": " << upBound - lowBound << "명" << std::endl;

		start = upBound;
	}
}

void set()
{
	std::vector<Player> v;

	makeData();

	// [문제 1] "기말.dat" 파일에 기록된 선수 정보를 컨테이너로 읽어 와라.
	// 제일 마지막 선수(10만번째 선수)의 정보를 show()로 출력하라. 
	// 화면에 출력된 선수 정보를 답지에 적어라.
	std::ifstream in{ "기말.dat", std::ios::binary };
	Player* temp = new Player;

	v.reserve(100000);

	while (in.read((char*)temp, sizeof(Player)))
	{
		v.emplace_back(temp->getYear(), temp->getMonth(), temp->getName());
	}

	v.crbegin()->show();

	system("pause");
	system("cls");

	// [문제 2] 컨테이너에 저장한 선수 정보를 정렬하라.
	// 정렬 순서는 연도 오름차순이다. 연도가 같은 경우에는 이름도 오름차순으로 정렬되어야 한다.
	// 정렬된 컨테이너의 제일 마지막 선수 정보를 답지에 적어라.

	std::multiset<Player> s(v.begin(), v.end());

	s.crbegin()->show();

	system("pause");
	system("cls");

	// [문제 3] 위 문제의 정렬 순서가 유지되도록 다음 플레이어 p를 컨테이너에 추가하라.
	// p 다음에 있는 선수의 정보를 답지에 적어라.

	Player p{ 1999, 1, "test" };

	s.emplace(p.getYear(), p.getMonth(), p.getName());
	(++s.find(p))->show();

	system("pause");
	system("cls");

	// [문제 4] 각 연도별 플레이어의 수를 출력하라.
	// 1950년 - 몇 명
	// 1951년 - 몇 명
	// 
	// 중간은 생략함
	// 
	// 2010년 - 몇 명
	// 와 같이 출력되도록 할 것.
	// 
	// 출력되는 내용중 2010년 플레이어의 수는 답안지에 적아라.
	// (선형 알고리즘으로 하나씩 세는 답은 감점)

	auto start{ s.begin() };
	int total{};

	for (int year = 1950; year <= 2010; ++year)
	{
		auto [lowBound, upBound] {std::equal_range(start, s.end(), year, [](const Player& a, const Player& b)
			{
				return a.getYear() < b.getYear();
			})};

		std::cout << year << " - " << std::distance(lowBound, upBound) << "명" << std::endl;

		start = upBound;
		total += std::distance(lowBound, upBound);
	}

	std::cout << total << std::endl;
}