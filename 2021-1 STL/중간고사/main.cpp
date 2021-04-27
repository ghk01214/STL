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
	// emplace_back을 사용하기 위해 생성한 생성자
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

// [문제 1] 출력된 파일 크기를 보고 저장된 객체의 수를 알 수 있는지 "예/아니오"로 답하고 그 이유를 설명하시오.
// 해답 : name의 길이가 가변이므로 정확한 갯수를 알 수가 없다.

void Q2(std::vector<Player>& v, std::ifstream& in);
void Q3(std::vector<Player>& v);
void Q4(std::vector<Player>& v);

int main()
{
	std::string fileName{ "중간시험.dat"s };
	std::ifstream in{ fileName, std::ios::app };
	std::vector<Player> vPlayer;

	if (!in)
	{
		std::cout << fileName << "파일을 열 수 없습니다" << std::endl;
		exit(0);
	}

	// 파일 크기 = 518142 바이트
	size_t fileSize = std::filesystem::file_size(fileName);
	std::cout << fileName << "의 크기 - " << fileSize << " 바이트" << std::endl << std::endl;

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
	//	// emplace를 사용할려면 반드시 클래스 생성자를 생성해줘야 한다.
	//	//v.emplace_back(*player);
	//	v.emplace_back(s, n);
	//}

	//std::vector<Player> vPlayer{ std::istream_iterator<Player>{in}, {} };
	//v = vPlayer;

	std::cout << "읽은 객체 수 : " << v.size() << std::endl;

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
		std::cout << "이름이 Stlcontainer인 객체가 존재하지 않습니다." << std::endl;
	}
	else
	{
		std::cout << "이름이 Stlcontainer인 객체는 " << std::distance(v.cbegin(), pos) + 1 << "번째 객체입니다" << std::endl;
	}

	std::cout << std::endl;

	system("pause");
	system("cls");
}

void Q4(std::vector<Player>& v)
{
	std::cout << "id를 검색합니다" << std::endl;

	while (true)
	{
		int id;

		std::cout << "찾으려는 id를 입력하세요 : ";
		std::cin >> id;

		if (id < 1 or 3000 < id)
		{
			std::cout << "유효한 id는 [1, 3000] 입니다." << std::endl << std::endl;
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

		std::cout << "id가 " << id << "인 객체의 수 - " << playerNum << std::endl;

		for (const Player& p : vTemp)
		{
			std::cout << p << std::endl;
		}

		std::cout << std::endl;
	}
}