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
	std::ifstream in{ "2021 STL 과제 파일", std::ios::binary };
	std::ofstream out{ "바이트 수가 500", std::ios::binary };
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

	// 1번 문제 - 이름: xiywmrralbh, 아이디: 1000000, 점수: 37392053, 자원수: 117
	std::cout << "1번" << std::endl;
	std::cout << vPlayer.at(count - 1).first << "번 객체" << vPlayer.at(count - 1).second << std::endl << std::endl;

	// 2번 문제 - 총합 = 2.99922e+13, 총 평균 = 2.99922e+07
	double sum{};

	for (auto i{ vPlayer.begin() }; i != vPlayer.end(); ++i)
	{
		sum += i->second.ReturnScore();

		// 3번 문제 - 

		if (i->second.ReturnSize() == 500)
		{
			i->second.Write(out);
		}
	}

	std::cout << "2번" << std::endl;
	std::cout << "총 합 = " << sum << ", 총 평균값 = " << double(sum / count) << std::endl;
}