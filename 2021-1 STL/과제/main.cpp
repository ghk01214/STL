#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Player.h"

void Initialize(std::vector<Player>& v);
void Question1(std::vector<Player>& v);
void Question2(std::vector<Player>& v);
void Question3(std::vector<Player>& v);
void Question4(std::vector<Player>& v);
void PrintInfo(std::vector<Player>& v, int id);

int main()
{
	std::vector<Player> vPlayer;
	vPlayer.reserve(1000000);

	Initialize(vPlayer);

	Question1(vPlayer);
	Question2(vPlayer);
	Question3(vPlayer);
	Question4(vPlayer);
}

void Initialize(std::vector<Player>& v)
{
	std::ifstream in{ "2021 STL ���� ����", std::ios::binary };
	std::unique_ptr<Player> ptr{ new Player };

	if (!in)
	{
		std::cout << "\"2021 STL ���� ����\" ���� ����!" << std::endl;
		exit(true);
	}

	while (in.read((char*)ptr.get(), sizeof(Player)))
	{
		char c[5000];
		in.read((char*)c, ptr.get()->ReturnSize());

		v.push_back(*ptr);
	}
}

void Question1(std::vector<Player>& v)
{
	std::cout << "\n1. ������ �о� ���� ������ ��ü�� ������ ������ ���� �������� ����϶�." << std::endl;
	std::cout << *v.rbegin() << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question2(std::vector<Player>& v)
{
	std::cout << "\n2. ��� Player�� ���� ��հ��� ����Ͽ� ����϶�." << std::endl;

	long long llSum{};

	std::for_each(v.cbegin(), v.cend(), [&llSum](const Player& p)
		{
			llSum += p.ReturnScore();
		});

	std::cout << "n��� Player�� ���� ��հ� : " << llSum / v.size() << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question3(std::vector<Player>& v)
{
	std::cout << "\n3. Ȯ���� �޸� ����Ʈ ���� 500�� Player ��ü�� ��� ã�� �̸��� \"����Ʈ ���� 500\"�� ���Ͽ� �����϶�." << std::endl;
	std::ofstream out{ "����Ʈ ���� 500", std::ios::binary };

	if (!out)
	{
		std::cout << "\"����Ʈ ���� 500\" ���� ���� ����!" << std::endl;
		exit(true);
	}

	for (auto i{ v.cbegin() }; i != v.cend(); ++i)
	{
		if ((*i).ReturnSize() == 500)
		{
			out.write((char*)&v[std::distance(v.cbegin(), i)], sizeof(Player));
		}
	}

	std::cout << "���� ����" << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question4(std::vector<Player>& v)
{
	while (true)
	{
		int id{};

		std::cout << "\n4. ���̵� ���� �Է��ϸ� ������ ���� ������ �� ���� ȭ�� ����϶�." << std::endl;
		std::cout << "\nPlayer ID �Է�(0 = ����) : ";
		std::cin >> id;

		if (id == 0)
		{
			break;
		}
		else if (!(1 <= id && id <= 1000000))
		{
			std::cout << "�Է��� Id�� �����ϴ�." << std::endl;
			std::cin.ignore();

			system("pause");
			system("cls");

			continue;
		}
		std::cout << "\n�������������������������������������������������������������������������� Id ����������������������������������������������������������������������������������" << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnId() < b.ReturnId();
			});
		PrintInfo(v, id);

		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl << std::endl;


		std::cout << "�������������������������������������������������������������������������� �̸� ������������������������������������������������������������������������������" << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnName() < b.ReturnName();
			});
		PrintInfo(v, id);

		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl << std::endl;


		std::cout << "�������������������������������������������������������������������������� ���� ������������������������������������������������������������������������������" << std::endl;
		
		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnScore() < b.ReturnScore();
			});
		PrintInfo(v, id);

		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl << std::endl;

		system("pause");
		system("cls");
	}
}

void PrintInfo(std::vector<Player>& v, int id)
{
	auto dis{ std::find_if(v.cbegin(), v.cend(), [id](const Player& p)
		{
			return p.ReturnId() == id;
		}) };

	auto pos{ std::distance(v.cbegin(), dis) };

	if (pos == 0)
	{
		std::cout << v.at(pos) << std::endl;
		std::cout << v.at(pos + 1) << std::endl;
	}
	else if (pos == v.size() - 1)
	{
		std::cout << v.at(pos - 1) << std::endl;
		std::cout << v.at(pos) << std::endl;
	}
	else
	{
		std::cout << v.at(pos - 1) << std::endl;
		std::cout << v.at(pos) << std::endl;
		std::cout << v.at(pos + 1) << std::endl;
	}
}