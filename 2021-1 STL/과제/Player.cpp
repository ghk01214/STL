#include <iostream>
#include "Player.h"

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
