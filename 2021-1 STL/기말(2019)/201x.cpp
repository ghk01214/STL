#include <iostream>
#include <random>
#include <filesystem>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std::literals::string_literals;

class Player
{
public:
	Player() = default;
	Player(std::string n, int i) : name{ n }, id{ i } {}
	Player(int i) : id{ i } {}
public:
	void MakeCapital() { name[0] = std::toupper(name[0]); }
public:
	std::string getName() const { return name; }
	int getId() const { return id; }
public:
	bool operator<(const Player& other) const { return name.length() < other.name.length(); }
	friend std::istream& operator>>(std::istream& is, Player& p)
	{
		is >> p.name >> p.id;
		return is;
	}
private:
	std::string name;
	int id;
};

int main()
{
	std::string fileName{ "중간시험.dat"s };
	std::ifstream in{ fileName };

	if (!in)
	{
		std::cout << fileName << " 파일을 열 수 없습니다." << std::endl;
		exit(0);
	}

	size_t fileSize{ std::filesystem::file_size(fileName) };
	std::cout << fileName << "의 크기 : " << fileSize << " 바이트" << std::endl;

	// [문제 1] 출력된 파일 크기를 보고 저장된 객체의 수를 알 수 있는지 "예/아니오"로 답하고
	// 그렇게 답한 이유를 설명하라
	// A : 파일의 크기를 알 수 없다.
	// 플레이어 내의 string의 크기가 가변이므로 정확한 크기를 알 수 없다.

	// [문제 2] 파일을 읽어 객체를 컨테이너에 저장하라.
	// 컨테이너에 저장된 객체의 수를 출력하고 답지에도 적어라.

	std::vector<Player> v{ std::istream_iterator<Player>{in}, {} };

	/* 또다른 파일 읽어들이는 법
	std::vector<Player> v;
	Player temp{};
	
	v.reserve(100000);

	while (in >> temp)
	{
		v.emplace_back(temp.getName(), temp.getId());
	}*/

	std::cout << "전체 객체 수 : " << v.size() << std::endl;

	system("pause");
	system("cls");

	// [문제 3] 컨테이너에 저장된 모든 객체의 name 첫 글자를 대문자로 변경하라.
	// 컨테이너에 name이 "Stlcontainer"s인 객체가 있는지 찾아라.
	// 찾았다면 몇 번째 객체인지 출ㄹ력하고 없으면 없다고 출력하라.
	// 답지에도 찾은 결과를 적어라.
	// (주의) 알고리즘을 사용할 것(loop를 사용하여 찾으면 점수 없음.)

	std::for_each(v.begin(), v.end(), [](Player& p)
		{
			p.MakeCapital();
		});

	auto pos{ std::find_if(v.cbegin(), v.cend(), [](const Player& p)
		{
			return p.getName() == "Stlcontainer"s;
		}) };

	if (pos == v.end())
		std::cout << "이름이 \"Stlcontainer\"인 객체가 없습니다." << std::endl;
	else
		std::cout << "이름이 \"Stlcontainer\"인 객체는 " << pos - v.cbegin() << "번 째 객체입니다." << std::endl;

	system("pause");
	system("cls");

	// [문제 4] id를 입력하면 같은 id를 갖는 객체를 모두 출력하는 코드를 조건에 맞게 작성하라.
	// - id가 같은 객체가 몇 개인지 출력하여야 한다.
	// - id가 같은 모든 객체의 id와 name을 화면 출력하여야 한다.
	// - id가 같은 객체들은 name의 길이를 기준으로 할 때 오름차순으로 정렬되어 있어야 한다.
	// - 이 코드는 반복 실행되어야 한다.
	// (참고) 출력화면 예를 살펴보자

	std::cout << "id를 검색합니다." << std::endl;

	while (true)
	{
		int id;

		std::cout << "찾으려는 id를 입력하세요 : ";
		std::cin >> id;

		if (id < 1 or id > 3000)
		{
			std::cout << "유효한 id는 [1, 3000]입니다." << std::endl << std::endl;
			continue;
		}

		// 풀이법 1
		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			});

		auto [start, end] {std::equal_range(v.begin(), v.end(), id, [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			})};

		std::multiset<Player> ms{ start, end };

		std::cout << "id가 " << id << "인 객체 수 : " << end - start << std::endl;

		for (const Player& p : ms)
		{
			std::cout << p.getId() << ", " << p.getName() << std::endl;
		}

		// 풀이법 2
		//std::vector<Player> v2;

		//int cnt{ (int)std::count_if(v.begin(), v.end(), [id, &v2](const Player& p)
		//	{
		//		if (p.getId() == id)
		//		{
		//			v2.emplace_back(p.getName(), p.getId());
		//			return true;
		//		}

		//		return false;
		//	}) };

		//std::cout << "id가 " << id << "인 객체 수 : " << cnt << std::endl;

		//std::sort(v2.begin(), v2.end(), [](const Player& a, const Player& b)
		//	{
		//		return a.getName().length() < b.getName().length();
		//	});

		//for (const Player& p : v2)
		//{
		//	std::cout << p.getId() << ", " << p.getName() << std::endl;
		//}

		std::cout << std::endl;
	}
}