//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 4월 8일 목요일 (6주 2일)
// 
// vector<int>에서 짝수만 삭제한다
// vector<int> 중간에 원소를 추가해 본다
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include "pch.h"
#include "save.h"
#include <memory>
#include <random>

// [문제] "Dog 만객체"에 바이너리 모드로 저장되어 있는 Dog 10000 객체를 읽어라
// id 오름차순으로 정렬해서 출력하라

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
	os << "이름: " << dog.name << ", 아이디: " << dog.id;

	return os;
}

int main()
{
	std::ifstream in{ "Dog 만객체" };

	std::unique_ptr<Dog[]> dogs{ new Dog[10000] };

	in.read((char*)dogs.get(), sizeof(Dog) * 10000);

	for (int i = 0; i < 10000; ++i)
	{
		std::cout << dogs[i] << std::endl;
	}

	//Save("main.cpp");
}