#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

class Player
{
public:
	Player() = default;
	Player(std::string n, int s, int i, size_t size) : name{ n }, score{ s }, id{ i }, num{ size } {}
	Player(size_t size) : num{ size } {}
public:
	std::string getName() const { return name; }
	int getScore() const { return score; }
	int getId() const { return id; }
	size_t getSize() const { return num; }
public:
	friend std::ostream& operator<<(std::ostream& os, const Player& p)
	{
		os << "이름 : " << p.name << ", " << std::setw(2) << "아이디 : " << p.id << ", " << std::setw(2) << "점수 : " << p.score << ", " << std::setw(2) << "자원 수 : " << p.num;

		return os;
	}
private:
	std::string	 name;	 // 이름
	int			 score;	 // 점수
	int			 id;	 // 아이다
	size_t		 num;	 // 확보한 메모리 바이트 수
	char*		 p;		 // 확보한 메모리의 시작번지
};

int main()
{
	std::ifstream in{ "2021 STL 과제 파일", std::ios::binary };
	std::vector<Player> v;
	Player* temp{ new Player };

	if (!in)
	{
		std::cout << "파일을 열 수 없습니다" << std::endl;
		exit(0);
	}

	v.reserve(100000);

	while (in.read((char*)temp, sizeof(Player)))
	{
		char p[5000];
		in.read((char*)p, temp->getSize());

		v.push_back(*temp);
	}

	std::cout << *v.crbegin() << std::endl;

	system("pause");
	system("cls");

	__int64 total{};

	std::for_each(v.cbegin(), v.cend(), [&total](const Player& p)
		{
			total += p.getScore();
		});

	std::cout << "모든 Player의 점수 평균값 : " << total / v.size() << std::endl;

	system("pause");
	system("cls");

	std::ofstream out{ "바이트 수가 500.dat", std::ios::binary };

	//for (const Player& p : v)
	//{
	//	if (p.getSize() == 500)
	//		out.write((const char*)&p, sizeof(Player));
	//}

	std::for_each(v.begin(), v.end(), [&out](Player& p)
		{
			if (p.getSize() == 500)
				out.write((const char*)&p, sizeof(Player));
		});

	std::cout << "\"바이트 수가 500.dat\" 파일 생성 완료" << std::endl;

	system("pause");
	system("cls");

	while (true)
	{
		int id;

		std::cout << "Player ID 입력 : ";
		std::cin >> id;

		auto pos{ std::find_if(v.cbegin(), v.cend(), [id](const Player& p)
			{
				return id == p.getId();
			}) };

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			});

		auto [start, end] {std::equal_range(v.cbegin(), v.cend(), *pos, [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			})};

		if (start == end)
		{
			std::cout << *(start - 1) << std::endl;
			std::cout << *start << std::endl;
			std::cout << *(start + 1) << std::endl;
		}
		else
		{
			for (; start != end; ++start)
			{
				std::cout << *start << std::endl;
			}
		}

		std::cout << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.getName() < b.getName();
			});

		auto [start2, end2] {std::equal_range(v.cbegin(), v.cend(), *pos, [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			})};

		if (start2 == end2)
		{
			std::cout << *(start2 - 1) << std::endl;
			std::cout << *start2 << std::endl;
			std::cout << *(start2 + 1) << std::endl;
		}
		else
		{
			for (; start2 != end2; ++start2)
			{
				std::cout << *start2 << std::endl;
			}
		}

		std::cout << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.getScore() < b.getScore();
			});

		auto [start3, end3] {std::equal_range(v.cbegin(), v.cend(), *pos, [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			})};

		if (start3 == end3)
		{
			std::cout << *(start3 - 1) << std::endl;
			std::cout << *start3 << std::endl;
			std::cout << *(start3 + 1) << std::endl;
		}
		else
		{
			for (; start3 != end3; ++start3)
			{
				std::cout << *start3 << std::endl;
			}
		}

		std::cout << std::endl;
	}
}