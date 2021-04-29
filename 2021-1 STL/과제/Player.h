#pragma once
#include <fstream>

class Player
{
public:
	Player() {}
	Player(std::string name, int score, int id, size_t num) : sName{ name }, iScore{ score }, iId{ id }, sNum{ num } {}
	~Player() {}
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
	char* p;						// 확보한 메모리의 시작번지
};

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << "이름 : " << p.sName << "\t, 아이디 : " << p.iId << "\t, 점수 : " << p.iScore << "\t, 자원 수 : " << p.sNum;

	return os;
}