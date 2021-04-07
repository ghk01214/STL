//������������������������������������������������������������
// 4�� 8�� ����� (6�� 2��)
// 
// vector<int>���� ¦���� �����Ѵ�
// vector<int> �߰��� ���Ҹ� �߰��� ����
//������������������������������������������������������������

#include "pch.h"
#include "save.h"
#include <memory>
#include <random>

// [����] "Dog ����ü"�� ���̳ʸ� ���� ����Ǿ� �ִ� Dog 10000 ��ü�� �о��
// id ������������ �����ؼ� ����϶�

std::uniform_int_distribution<> uid;
std::default_random_engine dre;

using namespace std::literals::string_literals;

class Dog
{
private:
	std::string name;
	int id;
	static int cnt;
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
public:
	Dog() : id{ uid(dre) }
	{
		name = "Dog"s;
		name += std::to_string(cnt);

		++cnt;
	}
	~Dog() {}
};

int Dog::cnt = { 1 };

std::ostream& operator<<(std::ostream& os, const Dog& dog)
{
	os << "�̸�: " << dog.name << ", ���̵�: " << dog.id;

	return os;
}

int main()
{
	std::ifstream in{ "Dog ����ü" };

	std::unique_ptr<Dog[]> dogs{ new Dog[10000] };

	in.read((char*)dogs.get(), sizeof(Dog) * 10000);

	for (int i = 0; i < 10000; ++i)
	{
		std::cout << dogs[i] << std::endl;
	}

	//Save("main.cpp");
}