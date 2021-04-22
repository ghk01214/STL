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
	std::ifstream in{ "2021 STL 과제 파일", std::ios::binary };
	std::unique_ptr<Player> ptr{ new Player };

	if (!in)
	{
		std::cout << "\"2021 STL 과제 파일\" 열기 실패!" << std::endl;
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
	std::cout << "\n1. 파일을 읽어 제일 마지막 객체의 정보를 다음과 같은 형식으로 출력하라." << std::endl;
	std::cout << *v.rbegin() << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question2(std::vector<Player>& v)
{
	std::cout << "\n2. 모든 Player의 점수 평균값을 계산하여 출력하라." << std::endl;

	long long llSum{};

	// 전체 점수 합
	for (const Player& p : v)
	{
		llSum += p.ReturnScore();
	}

	// 전체 점수 평균
	std::cout << "n모든 Player의 점수 평균값 : " << llSum / v.size() << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question3(std::vector<Player>& v)
{
	std::cout << "\n3. 확보한 메모리 바이트 수가 500인 Player 객체를 모두 찾아 이름이 \"바이트 수가 500\"인 파일에 복사하라." << std::endl;
	std::ofstream out{ "바이트 수가 500", std::ios::binary };

	if (!out)
	{
		std::cout << "\"바이트 수가 500\" 파일 생성 실패!" << std::endl;
		exit(true);
	}

	// 바이트수가 500인 원소의 위치를 구해서 파일로 저장
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

	std::cout << "복사 성공" << std::endl << std::endl;

	system("pause");
	system("cls");
}

void Question4(std::vector<Player>& v)
{
	int id{ -1 };

	while (true)
	{
		std::cout << "\n4. 아이디 값을 입력하면 다음과 같은 사항을 한 번에 화면 출력하라." << std::endl;
		std::cout << "\nPlayer ID 입력(0 = 종료) : ";
		std::cin >> id;

		if (id == 0)
		{
			break;
		}

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnId() < b.ReturnId();
			});

		std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Id 오름차순━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
		PrintInfo(v, id);
		std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnName() < b.ReturnName();
			});

		std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 이름 오름차순━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
		PrintInfo(v, id);
		std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl << std::endl;

		std::sort(v.begin(), v.end(), [](const Player& a, const Player& b)
			{
				return a.ReturnScore() < b.ReturnScore();
			});

		std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 점수 오름차순━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
		PrintInfo(v, id);
		std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl << std::endl;

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
		std::cout << "입력한 Id가 없습니다." << std::endl;
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