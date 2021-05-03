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
void PrintData(std::vector<Player>& v, int id);

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

	__int64 i64Sum{};

	std::for_each(v.cbegin(), v.cend(), [&i64Sum](const Player& p)
		{
			i64Sum += p.ReturnScore();
		});

	std::cout << "n��� Player�� ���� ��հ� : " << i64Sum / v.size() << std::endl << std::endl;

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

	int cnt{ std::count_if(v.cbegin(), v.cend(), [&out](const Player& p)
		{
			if (p.ReturnSize() == 500)
			{
				out.write((char*)&p, sizeof(Player));

				return true;
			}

			return false;
		}) };

	std::cout << cnt << "�� ���� ����" << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question4(std::vector<Player>& v)
{
	while (true)
	{
		int id;
		std::string sId;

		std::cout << "\n4. ���̵� ���� �Է��ϸ� ������ ���� ������ �� ���� ȭ�� ����϶�." << std::endl;
		std::cout << "\nPlayer ID �Է�(0 = ����) : ";
		std::cin >> sId;

		try
		{
			id = std::stoi(sId);
		}
		catch (...)
		{
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << std::endl << std::endl;
			std::cin.ignore();

			system("pause");
			system("cls");

			continue;
		}

		if (id == 0)
		{
			std::cout << "���α׷��� �����մϴ�." << std::endl;

			break;
		}
		else if (!(1 <= id && id <= 1000000))
		{
			std::cout << "�Է��� Id�� �����ϴ�." << std::endl << std::endl;
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
		PrintData(v, id);

		std::cout << "�������������������������������������������������������������������������� �̸� ������������������������������������������������������������������������������" << std::endl;
		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnName() < b.ReturnName();
			});
		PrintData(v, id);

		std::cout << "�������������������������������������������������������������������������� ���� ������������������������������������������������������������������������������" << std::endl;
		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnScore() < b.ReturnScore();
			});
		PrintData(v, id);

		system("pause");
		system("cls");
	}
}

void PrintData(std::vector<Player>& v, int id)
{
	auto pos{ std::find_if(v.cbegin(), v.cend(), [id](const Player& p)
		{
			return p.ReturnId() == id;
		}) };

	if (pos == v.cbegin())
	{
		std::cout << *pos << std::endl;
		std::cout << *(pos + 1) << std::endl;
	}
	else if (pos == v.cend() - 1)
	{
		std::cout << *(pos - 1) << std::endl;
		std::cout << *pos << std::endl;
	}
	else
	{
		std::cout << *(pos - 1) << std::endl;
		std::cout << *pos << std::endl;
		std::cout << *(pos + 1) << std::endl;
	}

	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl << std::endl;
}