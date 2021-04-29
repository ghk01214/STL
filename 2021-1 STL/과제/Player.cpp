#include "Player.h"

//#define 관찰

//Player::Player() : sName{}, iScore{}, iId{}, sNum{}, p{}
//{
//#ifdef 초기화
//	std::cout << "생성자() (this: " << this << ") - 갯수: " << sNum << ", 위치: " << (void*)p << std::endl;
//#endif
//}
//
//Player::Player(std::string name, int score, int id, size_t num) : sName{ name }, iScore{ score }, iId{ id }, sNum{ num }
//{
//#ifdef 관찰
//	std::cout << "생성자() (this: " << this << ") - 갯수: " << sNum << ", 위치: " << (void*)p << std::endl;
//#endif
//}
//
//Player::~Player()
//{
//#ifdef 소멸
//	std::cout << "소멸자 (this: " << this << ") - 갯수: " << sNum << ", 위치: " << (void*)p << std::endl;
//#endif
//
//	delete[] p;
//}
//
//// 복사생성자
//Player::Player(const Player& other) : sName{ other.sName }, iScore{ other.iScore }, iId{ other.iId }, sNum{ other.sNum }
//{
//	memcpy(p, other.p, sNum);
//
//#ifdef 관찰
//	std::cout << "복사생성자 (this: " << this << ") - 갯수: " << sNum << ", 위치: " << (void*)p << std::endl;
//#endif
//}
//
//// 복사할당연산자
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
//#ifdef 관찰
//	std::cout << "복사할당연산자 (this: " << this << ") - 갯수: " << sNum << ", 위치: " << (void*)p << std::endl;
//#endif
//
//	return *this;
//}
//
//// 이동생성자
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
//#ifdef 관찰
//	std::cout << "이동생성자 (this: " << this << ") - 갯수: " << sNum << ", 위치: " << (void*)p << std::endl;
//#endif
//}
//
//// 이동할당연산자
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
//#ifdef 관찰
//	std::cout << "이동할당연산자 (this: " << this << ") - 갯수: " << sNum << ", 위치: " << (void*)p << std::endl;
//#endif
//
//	return *this;
//}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << "이름 : " << p.sName << "\t, 아이디 : " << p.iId << "\t, 점수 : " << p.iScore << "\t, 자원 수 : " << p.sNum;

	return os;
}