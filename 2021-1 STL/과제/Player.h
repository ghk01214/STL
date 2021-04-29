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
	std::string		sName;					// �̸�
	int				iScore;					// ����
	int				iId;					// ���̵�
	size_t			sNum;					// Ȯ���� �޸� ����Ʈ ��
	char* p;						// Ȯ���� �޸��� ���۹���
};

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << "�̸� : " << p.sName << "\t, ���̵� : " << p.iId << "\t, ���� : " << p.iScore << "\t, �ڿ� �� : " << p.sNum;

	return os;
}