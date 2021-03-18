//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// 3월 18일 목요일 (3주 2일)
//
// 
// 
// 앞으로 사용할 관찰용 class(자원을 확보하는) 만들어 두기
//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#include "pch.h"
#include "save.h"
#include <random>

// [문제] int num을 인자로 받아 메모리를 num 바이트 할당받아
// 임의의 알파벳 소문자로 채우는 클래스 String을 구현하라
//
// 다음 main()이 의도대로 실행되게 하자

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> uid('a', 'z');

class String
{
private:
	int cnt;
	char* alphabet;

	friend std::ostream& operator<<(std::ostream& os, const String s);
public:
	String(int num) : cnt{ num }, alphabet{ new char[num] }
	{
		//std::unique_ptr<char[]> alphabet{ new char[num] };

		for (int i = 0; i < num; ++i)
		{
			alphabet[i] = uid(dre);
		}
	}
	~String() { delete[] alphabet; }

	size_t size()
	{

	}
};

std::ostream& operator<<(std::ostream& os, const String s)
{
	for (int i = 0; i < s.cnt; ++i)
		os << i + 1 << ". " << s.alphabet[i] << std::endl;

	return os;
}

int main()
{
	String s[10]{ 20, 21, 3, 14, 12, 7, 5, 8, 32, 2 };

	// 길이 오름차순으로 정렬하라
	std::sort(std::begin(s), std::end(s), [](const String& a, const String& b)
		{
			return a.size() < b.size();
		});
	
	for (String& s : s)
		std::cout << s << std::endl;

	//Save("main.txt");
}