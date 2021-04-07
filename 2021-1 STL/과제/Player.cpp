#include <iostream>
#include <iomanip>
#include "Player.h"

//Player::Player()
//{
//#ifdef ����
//	std::cout << "������() (this: " << this << ") - ����: " << tSize << ", ��ġ: " << (void*)cAddress << std::endl;
//#endif
//}
//
//Player::~Player()
//{
//#ifdef ����
//	std::cout << "�Ҹ��� (this: " << this << ") - ����: " << tSize << ", ��ġ: " << (void*)cAddress << std::endl;
//#endif
//
//	delete[] cAddress;
//}
//
//// ���������
//Player::Player(const Player& other) : sName{ other.sName }, iScore{ other.iScore }, iId{ other.iId }, tSize{ other.tSize }, cAddress{ new char[tSize] }
//{
//	memcpy(cAddress, other.cAddress, tSize);
//
//#ifdef ����
//	std::cout << "��������� (this: " << this << ") - ����: " << tSize << ", ��ġ: " << (void*)cAddress << std::endl;
//#endif
//}
//
//// �����Ҵ翬����
//Player& Player::operator=(const Player& other)
//{
//	if (this != &other)
//	{
//		delete[] cAddress;
//
//		tSize = other.tSize;
//		cAddress = new char[tSize];
//
//		memcpy(cAddress, other.cAddress, tSize);
//	}
//
//#ifdef ����
//	std::cout << "�����Ҵ翬���� (this: " << this << ") - ����: " << tSize << ", ��ġ: " << (void*)cAddress << std::endl;
//#endif
//
//	return *this;
//}
//
//// �̵�������
//Player::Player(Player&& other) noexcept : sName{ other.sName }, iScore{ other.iScore }, iId{ other.iId }, tSize{ other.tSize }
//{
//	cAddress = other.cAddress;
//	other.cAddress = nullptr;
//	other.tSize = 0;
//
//#ifdef ����
//	std::cout << "�̵������� (this: " << this << ") - ����: " << tSize << ", ��ġ: " << (void*)cAddress << std::endl;
//#endif
//}
//
//// �̵��Ҵ翬����
//Player& Player::operator=(Player&& other) noexcept
//{
//	if (this != &other)
//	{
//		delete[] cAddress;
//
//		tSize = other.tSize;
//		cAddress = other.cAddress;
//
//		other.tSize = 0;
//		other.cAddress = nullptr;
//	}
//
//#ifdef ����
//	std::cout << "�̵��Ҵ翬���� (this: " << this << ") - ����: " << tSize << ", ��ġ: " << (void*)cAddress << std::endl;
//#endif
//
//	return *this;
//}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << "�̸� : " << p.sName << "\t, ���̵� : " << p.iId << "\t, ���� : " << p.iScore << "\t, �ڿ��� : " << p.tSize;

	return os;
}

void Player::Write(std::ostream& os)
{
	os.write((char*)this, sizeof(Player));
	os.write((char*)cAddress, tSize);
}
