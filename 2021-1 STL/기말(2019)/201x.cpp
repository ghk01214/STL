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
	std::string fileName{ "�߰�����.dat"s };
	std::ifstream in{ fileName };

	if (!in)
	{
		std::cout << fileName << " ������ �� �� �����ϴ�." << std::endl;
		exit(0);
	}

	size_t fileSize{ std::filesystem::file_size(fileName) };
	std::cout << fileName << "�� ũ�� : " << fileSize << " ����Ʈ" << std::endl;

	// [���� 1] ��µ� ���� ũ�⸦ ���� ����� ��ü�� ���� �� �� �ִ��� "��/�ƴϿ�"�� ���ϰ�
	// �׷��� ���� ������ �����϶�
	// A : ������ ũ�⸦ �� �� ����.
	// �÷��̾� ���� string�� ũ�Ⱑ �����̹Ƿ� ��Ȯ�� ũ�⸦ �� �� ����.

	// [���� 2] ������ �о� ��ü�� �����̳ʿ� �����϶�.
	// �����̳ʿ� ����� ��ü�� ���� ����ϰ� �������� �����.

	std::vector<Player> v{ std::istream_iterator<Player>{in}, {} };

	/* �Ǵٸ� ���� �о���̴� ��
	std::vector<Player> v;
	Player temp{};
	
	v.reserve(100000);

	while (in >> temp)
	{
		v.emplace_back(temp.getName(), temp.getId());
	}*/

	std::cout << "��ü ��ü �� : " << v.size() << std::endl;

	system("pause");
	system("cls");

	// [���� 3] �����̳ʿ� ����� ��� ��ü�� name ù ���ڸ� �빮�ڷ� �����϶�.
	// �����̳ʿ� name�� "Stlcontainer"s�� ��ü�� �ִ��� ã�ƶ�.
	// ã�Ҵٸ� �� ��° ��ü���� �⤩���ϰ� ������ ���ٰ� ����϶�.
	// �������� ã�� ����� �����.
	// (����) �˰����� ����� ��(loop�� ����Ͽ� ã���� ���� ����.)

	std::for_each(v.begin(), v.end(), [](Player& p)
		{
			p.MakeCapital();
		});

	auto pos{ std::find_if(v.cbegin(), v.cend(), [](const Player& p)
		{
			return p.getName() == "Stlcontainer"s;
		}) };

	if (pos == v.end())
		std::cout << "�̸��� \"Stlcontainer\"�� ��ü�� �����ϴ�." << std::endl;
	else
		std::cout << "�̸��� \"Stlcontainer\"�� ��ü�� " << pos - v.cbegin() << "�� ° ��ü�Դϴ�." << std::endl;

	system("pause");
	system("cls");

	// [���� 4] id�� �Է��ϸ� ���� id�� ���� ��ü�� ��� ����ϴ� �ڵ带 ���ǿ� �°� �ۼ��϶�.
	// - id�� ���� ��ü�� �� ������ ����Ͽ��� �Ѵ�.
	// - id�� ���� ��� ��ü�� id�� name�� ȭ�� ����Ͽ��� �Ѵ�.
	// - id�� ���� ��ü���� name�� ���̸� �������� �� �� ������������ ���ĵǾ� �־�� �Ѵ�.
	// - �� �ڵ�� �ݺ� ����Ǿ�� �Ѵ�.
	// (����) ���ȭ�� ���� ���캸��

	std::cout << "id�� �˻��մϴ�." << std::endl;

	while (true)
	{
		int id;

		std::cout << "ã������ id�� �Է��ϼ��� : ";
		std::cin >> id;

		if (id < 1 or id > 3000)
		{
			std::cout << "��ȿ�� id�� [1, 3000]�Դϴ�." << std::endl << std::endl;
			continue;
		}

		// Ǯ�̹� 1
		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			});

		auto [start, end] {std::equal_range(v.begin(), v.end(), id, [](const Player& a, const Player& b)
			{
				return a.getId() < b.getId();
			})};

		std::multiset<Player> ms{ start, end };

		std::cout << "id�� " << id << "�� ��ü �� : " << end - start << std::endl;

		for (const Player& p : ms)
		{
			std::cout << p.getId() << ", " << p.getName() << std::endl;
		}

		// Ǯ�̹� 2
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

		//std::cout << "id�� " << id << "�� ��ü �� : " << cnt << std::endl;

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