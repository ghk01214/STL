#include "Player.h"

//#define ����

//Player::Player() : sName{}, iScore{}, iId{}, sNum{}, p{}
//{
//#ifdef �ʱ�ȭ
//	std::cout << "������() (this: " << this << ") - ����: " << sNum << ", ��ġ: " << (void*)p << std::endl;
//#endif
//}
//
//Player::Player(std::string name, int score, int id, size_t num) : sName{ name }, iScore{ score }, iId{ id }, sNum{ num }
//{
//#ifdef ����
//	std::cout << "������() (this: " << this << ") - ����: " << sNum << ", ��ġ: " << (void*)p << std::endl;
//#endif
//}
//
//Player::~Player()
//{
//#ifdef �Ҹ�
//	std::cout << "�Ҹ��� (this: " << this << ") - ����: " << sNum << ", ��ġ: " << (void*)p << std::endl;
//#endif
//
//	delete[] p;
//}
//
//// ���������
//Player::Player(const Player& other) : sName{ other.sName }, iScore{ other.iScore }, iId{ other.iId }, sNum{ other.sNum }
//{
//	memcpy(p, other.p, sNum);
//
//#ifdef ����
//	std::cout << "��������� (this: " << this << ") - ����: " << sNum << ", ��ġ: " << (void*)p << std::endl;
//#endif
//}
//
//// �����Ҵ翬����
//Player& Player::operator=(const Player& other)
//{
//	if (this != &other)
//	{
//		delete[] p;
//
//		sName = other.sName;
//		iScore = other.iScore;
//		iId = other.iId;
//		sNum = other.sNum;
//		p = new char[sNum];
//
//		memcpy(p, other.p, sNum);
//	}
//
//#ifdef ����
//	std::cout << "�����Ҵ翬���� (this: " << this << ") - ����: " << sNum << ", ��ġ: " << (void*)p << std::endl;
//#endif
//
//	return *this;
//}
//
//// �̵�������
//Player::Player(Player&& other) noexcept : sName{ other.sName }, iScore{ other.iScore }, iId{ other.iId }, sNum{ other.sNum }
//{
//	p = other.p;
//	other.p = nullptr;
//
//	other.sName.clear();
//	other.iScore = 0;
//	other.iId = 0;
//	other.sNum = 0;
//
//#ifdef ����
//	std::cout << "�̵������� (this: " << this << ") - ����: " << sNum << ", ��ġ: " << (void*)p << std::endl;
//#endif
//}
//
//// �̵��Ҵ翬����
//Player& Player::operator=(Player&& other) noexcept
//{
//	if (this != &other)
//	{
//		delete[] p;
//
//		sName = other.sName;
//		iScore = other.iScore;
//		iId = other.iId;
//		sNum = other.sNum;
//
//		other.sName.clear();
//		other.iScore = 0;
//		other.iId = 0;
//		other.sNum = 0;
//		other.p = nullptr;
//	}
//
//#ifdef ����
//	std::cout << "�̵��Ҵ翬���� (this: " << this << ") - ����: " << sNum << ", ��ġ: " << (void*)p << std::endl;
//#endif
//
//	return *this;
//}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << "�̸� : " << p.sName << "\t, ���̵� : " << p.iId << "\t, ���� : " << p.iScore << "\t, �ڿ� �� : " << p.sNum;

	return os;
}