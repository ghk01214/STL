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
		os << "�̸� : " << p.name << ", " << std::setw(2) << "���̵� : " << p.id << ", " << std::setw(2) << "���� : " << p.score << ", " << std::setw(2) << "�ڿ� �� : " << p.num;

		return os;
	}
private:
	std::string	 name;	 // �̸�
	int			 score;	 // ����
	int			 id;	 // ���̴�
	size_t		 num;	 // Ȯ���� �޸� ����Ʈ ��
	char*		 p;		 // Ȯ���� �޸��� ���۹���
};

int main()
{
	std::ifstream in{ "2021 STL ���� ����", std::ios::binary };
	std::vector<Player> v;
	Player* temp{ new Player };

	if (!in)
	{
		std::cout << "������ �� �� �����ϴ�" << std::endl;
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

	std::cout << "��� Player�� ���� ��հ� : " << total / v.size() << std::endl;

	system("pause");
	system("cls");

	std::ofstream out{ "����Ʈ ���� 500.dat", std::ios::binary };

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

	std::cout << "\"����Ʈ ���� 500.dat\" ���� ���� �Ϸ�" << std::endl;

	system("pause");
	system("cls");

	while (true)
	{
		int id;

		std::cout << "Player ID �Է� : ";
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