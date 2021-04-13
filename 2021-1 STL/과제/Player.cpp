#include <iostream>
#include "Player.h"

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
