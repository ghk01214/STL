#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include "Player.h"

enum Num
{
	count = 1000000
};

int main()
{
	std::ifstream in{ "2021 STL ���� ����", std::ios::binary };
	std::ofstream out{ "����Ʈ ���� 500", std::ios::binary };
	std::vector<std::pair<int, Player>> vPlayer;
	vPlayer.reserve(count);

	for (int i{ 0 }; i < count; ++i)
	{
		Player* pTemp{ new Player };
		in.read((char*)pTemp, sizeof(Player));

		vPlayer.emplace_back(std::make_pair(i + 1, *pTemp));

		char c[5000]{};
		in.read((char*)c, pTemp->ReturnSize() * sizeof(char));

		delete pTemp;
	}

	// 1�� ���� - �̸�: xiywmrralbh, ���̵�: 1000000, ����: 37392053, �ڿ���: 117
	std::cout << "1��" << std::endl;
	std::cout << vPlayer.at(count - 1).first << "�� ��ü" << vPlayer.at(count - 1).second << std::endl << std::endl;

	// 2�� ���� - ���� = 2.99922e+13, �� ��� = 2.99922e+07
	double sum{};

	for (auto i{ vPlayer.begin() }; i != vPlayer.end(); ++i)
	{
		sum += i->second.ReturnScore();

		// 3�� ���� - 

		if (i->second.ReturnSize() == 500)
		{
			i->second.Write(out);
		}
	}

	std::cout << "2��" << std::endl;
	std::cout << "�� �� = " << sum << ", �� ��հ� = " << double(sum / count) << std::endl;
}