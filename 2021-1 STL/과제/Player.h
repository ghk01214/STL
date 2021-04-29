#pragma once
#include <iostream>
#include <fstream>

class Player
{
//public:
//	Player();
//	Player(std::string name, int score, int id, size_t num);
//	~Player();
//public:
//	Player(const Player& other);
//	Player& operator=(const Player& other);
//
//	Player(Player&& other) noexcept;
//	Player& operator=(Player&& other) noexcept;
public:
	std::string ReturnName() const { return sName; }
	int ReturnScore() const { return iScore; }
	int ReturnId() const { return iId; }
	size_t ReturnSize() const { return sNum; }
public:
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
private:
	std::string		sName;					// 이름
	int				iScore;					// 점수
	int				iId;					// 아이디
	size_t			sNum;					// 확보한 메모리 바이트 수
	char*			p;						// 확보한 메모리의 시작번지
};