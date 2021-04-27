#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <iterator>
#include <string_view>

using namespace std::literals;

class Player
{
public:
	Player() = default;
	// emplace_back�� ����ϱ� ���� ������ ������
	Player(std::string s, int n) : name{ s }, id{ n } {}
public:
	void InputData(std::string& s, int n) { name = s; id = n; }
public:
	std::string_view ReturnName() const { return name; }
	int ReturnId()const { return id; }
public:
	void MakeCapital() { name[0] = std::toupper(name[0]); }
public:
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
	friend std::istream& operator>>(std::istream& is, Player& p);
	bool operator==(const std::string& s);
private:
	std::string name;
	int id;
};

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << p.id << ", " << p.name;

	return os;
}

std::istream& operator>>(std::istream& is, Player& p)
{
	is >> p.name >> p.id;

	return is;
}

bool Player::operator==(const std::string& s)
{
	return false;
}

// [���� 1] ��µ� ���� ũ�⸦ ���� ����� ��ü�� ���� �� �� �ִ��� "��/�ƴϿ�"�� ���ϰ� �� ������ �����Ͻÿ�.
// �ش� : name�� ���̰� �����̹Ƿ� ��Ȯ�� ������ �� ���� ����.

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
	v.reserve(12345);

	while (in >> *player.get())
	{
		v.push_back(*player);
	}

	//std::string s;
	//int n;

	//while (in >> s >> n)
	//{
	//	// emplace�� ����ҷ��� �ݵ�� Ŭ���� �����ڸ� ��������� �Ѵ�.
	//	//v.emplace_back(*player);
	//	v.emplace_back(s, n);
	//}

	//std::vector<Player> vPlayer{ std::istream_iterator<Player>{in}, {} };
	//v = vPlayer;

	std::cout << "���� ��ü �� : " << v.size() << std::endl;

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
			return p.ReturnName() == "Stlcontainer"sv;
		}) };

	//auto pos{ std::find(v.cbegin(), v.cend(), "Stlcontainer"sv) };

	if (pos == v.cend())
	{
		std::cout << "�̸��� Stlcontainer�� ��ü�� �������� �ʽ��ϴ�." << std::endl;
	}
	else
	{
		std::cout << "�̸��� Stlcontainer�� ��ü�� " << std::distance(v.cbegin(), pos) + 1 << "��° ��ü�Դϴ�" << std::endl;
	}

	std::cout << std::endl;

	system("pause");
	system("cls");
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
			std::cout << "��ȿ�� id�� [1, 3000] �Դϴ�." << std::endl << std::endl;
			continue;
		}

		std::vector<Player> vTemp;
		auto start{ v.begin() };
		//int playerNum{};

		//while (true)
		//{
		//	start = std::find_if(start, v.end(), [id](const Player& p)
		//		{
		//			return p.ReturnId() == id;
		//		});

		//	if (start >= v.end())
		//	{
		//		break;
		//	}

		//	vTemp.push_back(v[std::distance(v.begin(), start)]);
		//	++playerNum;
		//	++start;
		//}

		int playerNum{ std::count_if(v.cbegin(), v.cend(), [id, &vTemp](const Player& p)
			{
				if (p.ReturnId() == id)
				{
					vTemp.push_back(p);

					return true;
				}

				return false;
			}) };

		std::sort(vTemp.begin(), vTemp.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnName().length() < b.ReturnName().length();
			});

		std::cout << "id�� " << id << "�� ��ü�� �� - " << playerNum << std::endl;

		for (const Player& p : vTemp)
		{
			std::cout << p << std::endl;
		}

		std::cout << std::endl;
	}
}