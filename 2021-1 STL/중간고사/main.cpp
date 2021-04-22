#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

using namespace std::literals::string_literals;

class Player
{
public:
	void InputInfo(std::string& s, int n) { name = s; id = n; }
public:
	std::string ReturnName() const { return name; }
	int ReturnId()const { return id; }
public:
	void MakeCapital() { name[0] = std::toupper(name[0]); }
public:
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
private:
	std::string name;
	int id;
};

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << p.id << ", " << p.name;

	return os;
}


void Q2(std::vector<Player>& v, std::ifstream& in);
void Q3(std::vector<Player>& v);
void Q4(std::vector<Player>& v);

int main()
{
	std::string fileName{ "�߰�����.dat"s };
	std::ifstream in{ fileName, std::ios::app };
	std::vector<Player> vPlayer;

	if (!in)
	{
		std::cout << fileName << "������ �� �� �����ϴ�" << std::endl;
		exit(0);
	}

	// ���� ũ�� = 518142 ����Ʈ
	size_t fileSize = std::filesystem::file_size(fileName);
	std::cout << fileName << "�� ũ�� - " << fileSize << " ����Ʈ" << std::endl << std::endl;

	system("pause");
	system("cls");

	Q2(vPlayer, in);
	Q3(vPlayer);
	Q4(vPlayer);
}

void Q2(std::vector<Player>& v, std::ifstream& in)
{
	std::unique_ptr<Player> player{ new Player };
	std::string name;
	int id;

	while (in)
	{
		in >> name;
		in >> id;

		player.get()->InputInfo(name, id);
		v.emplace_back(*player);
	}

	v.pop_back();

	std::cout << *v.crbegin() << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Q3(std::vector<Player>& v)
{
	std::for_each(v.begin(), v.end(), [](Player& p)
		{
			p.MakeCapital();
		});

	auto pos{ std::find_if(v.cbegin(), v.cend(), [](const Player& p)
		{
			return p.ReturnName() == "Stlcontainer"s;
		}) };

	if (pos == v.cend())
	{
		std::cout << "�̸��� Stlcontainer�� ��ü�� �������� �ʽ��ϴ�." << std::endl;
	}
	else
	{
		std::cout << "�̸��� Stlcontainer�� ��ü�� " << std::distance(v.cbegin(), pos) + 1 << "��° ��ü�Դϴ�" << std::endl;
	}

	//for (auto i{ v.cbegin() }; i != v.cbegin() + 10; ++i)
	//{
	//	std::cout << *i << std::endl;
	//}
}

void Q4(std::vector<Player>& v)
{
	std::cout << "id�� �˻��մϴ�" << std::endl;

	while (true)
	{
		int id;

		std::cout << "ã������ id�� �Է��ϼ��� : ";
		std::cin >> id;

		if (id < 1 or 3000 < id)
		{
			std::cout << "��ȿ�� id�� [1, 3000] �Դϴ�." << std::endl;
			continue;
		}

		std::vector<Player> vTemp;
		auto start{ v.begin() };
		int playerNum{};

		while (start < v.end())
		{
			start = std::find_if(start, v.end(), [id](const Player& p)
				{
					return p.ReturnId() == id;
				});

			vTemp.emplace_back(v[std::distance(v.begin(), start)]);
			++playerNum;
			++start;
		}

		
	}
}