#include <iostream>
#include <iomanip>
#include "Player.h"

//Player::Player()
//{
//#ifdef 관찰
//	std::cout << "생성자() (this: " << this << ") - 갯수: " << tSize << ", 위치: " << (void*)cAddress << std::endl;
//#endif
//}
//
//Player::~Player()
//{
//#ifdef 관찰
//	std::cout << "소멸자 (this: " << this << ") - 갯수: " << tSize << ", 위치: " << (void*)cAddress << std::endl;
//#endif
//
//	delete[] cAddress;
//}
//
//// 복사생성자
//Player::Player(const Player& other) : sName{ other.sName }, iScore{ other.iScore }, iId{ other.iId }, tSize{ other.tSize }, cAddress{ new char[tSize] }
//{
//	memcpy(cAddress, other.cAddress, tSize);
//
//#ifdef 관찰
//	std::cout << "복사생성자 (this: " << this << ") - 갯수: " << tSize << ", 위치: " << (void*)cAddress << std::endl;
//#endif
//}
//
//// 복사할당연산자
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
//#ifdef 관찰
//	std::cout << "복사할당연산자 (this: " << this << ") - 갯수: " << tSize << ", 위치: " << (void*)cAddress << std::endl;
//#endif
//
//	return *this;
//}
//
//// 이동생성자
//Player::Player(Player&& other) noexcept : sName{ other.sName }, iScore{ other.iScore }, iId{ other.iId }, tSize{ other.tSize }
//{
//	cAddress = other.cAddress;
//	other.cAddress = nullptr;
//	other.tSize = 0;
//
//#ifdef 관찰
//	std::cout << "이동생성자 (this: " << this << ") - 갯수: " << tSize << ", 위치: " << (void*)cAddress << std::endl;
//#endif
//}
//
//// 이동할당연산자
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
//#ifdef 관찰
//	std::cout << "이동할당연산자 (this: " << this << ") - 갯수: " << tSize << ", 위치: " << (void*)cAddress << std::endl;
//#endif
//
//	return *this;
//}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << "이름 : " << p.sName << "\t, 아이디 : " << p.iId << "\t, 점수 : " << p.iScore << "\t, 자원수 : " << p.tSize;

	return os;
}

void Player::Write(std::ostream& os)
{
	os.write((char*)this, sizeof(Player));
	os.write((char*)cAddress, tSize);
}
