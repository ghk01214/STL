#pragma once
//#define ����

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
	std::string		sName;				// �̸�
	int				iScore;				// ����
	int				iId;				// ���̵�
	size_t			tSize;				// Ȯ���� �޸� ����Ʈ ��
	char*			cAddress;			// Ȯ���� �޸��� ���۹���
private:
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
};

