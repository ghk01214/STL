#pragma once
//#define 관찰

class Player
{
public:
	std::string ReturnName() const { return sName; }
	int ReturnScore() const { return iScore; }
	int ReturnId() const { return iId; }
	size_t ReturnSize() const { return tSize; }
	char* ReturnAddress() const { return cAddress; }
public:
	void Write(std::ostream& os);
private:
	std::string		sName;				// 이름
	int				iScore;				// 점수
	int				iId;				// 아이디
	size_t			tSize;				// 확보한 메모리 바이트 수
	char*			cAddress;			// 확보한 메모리의 시작번지
private:
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
};

