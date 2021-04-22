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

	while (in)
	{
		in.read((char*)ptr.get(), sizeof(Player));

		char c[5000];
		in.read((char*)c, ptr.get()->ReturnSize());

		v.emplace_back(*ptr);
	}

	v.pop_back();
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

	// ��ü ���� ��
	for (const Player& p : v)
	{
		llSum += p.ReturnScore();
	}

	// ��ü ���� ���
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

	// ����Ʈ���� 500�� ������ ��ġ�� ���ؼ� ���Ϸ� ����
	auto start{ v.begin() };

	while (start < v.end())
	{
		start = std::find_if(start, v.end(), [](const Player& p)
			{
				return p.ReturnSize() == 500;
			});

		out.write((char*)&v[std::distance(v.begin(), start)], sizeof(Player));
		++start;
	}

	std::cout << "���� ����" << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question4(std::vector<Player>& v)
{
	int id{ -1 };

	while (true)
	{
		std::cout << "\n4. ���̵� ���� �Է��ϸ� ������ ���� ������ �� ���� ȭ�� ����϶�." << std::endl;
		std::cout << "\nPlayer ID �Է�(0 = ����) : ";
		std::cin >> id;

		if (id == 0)
		{
			break;
		}

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnId() < b.ReturnId();
			});

		std::cout << "\n�������������������������������������������������������������������������� Id ����������������������������������������������������������������������������������" << std::endl;
		PrintInfo(v, id);
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnName() < b.ReturnName();
			});

		std::cout << "�������������������������������������������������������������������������� �̸� ������������������������������������������������������������������������������" << std::endl;
		PrintInfo(v, id);
		std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������������������������������" << std::endl << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnScore() < b.ReturnScore();
			});

		std::cout << "�������������������������������������������������������������������������� ���� ������������������������������������������������������������������������������" << std::endl;
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

	if (pos >= v.size() || pos < 0)
	{
		std::cout << "�Է��� Id�� �����ϴ�." << std::endl;
	}
	else
	{
		if (pos == 0)
		{
			std::cout << v.at(pos) << std::endl;
			std::cout << v.at(pos + 1) << std::endl;
		}
		else if (pos == v.size() - 1 )
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
}