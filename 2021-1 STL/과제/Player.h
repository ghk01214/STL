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
	std::string		sName;					// �̸�
	int				iScore;					// ����
	int				iId;					// ���̵�
	size_t			sNum;					// Ȯ���� �޸� ����Ʈ ��
	char*			p;						// Ȯ���� �޸��� ���۹���
};