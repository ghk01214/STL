#include "save.h"

// google coding convention
void Save(std::string_view fileName)
{
	// 어떤 파일을 저장하는지 화면에 출력
	std::cout << "저장: " << fileName << ", 크기: " << std::filesystem::file_size(fileName) << std::endl;

	std::ofstream out("5월 06일(목).txt", std::ios::app);
	std::ifstream in(fileName);

	//파일을 기록한 시간도 표시
	time_t t = std::time(nullptr);

	//시간 기록 지역 변경
	out.imbue(std::locale("korean"));

	out << "━━━━━━━━━━━━━━━━━━━━" << std::endl;
	out << "저장시간: " << std::put_time(localtime(&t), "%c %A") << std::endl;
	out << "━━━━━━━━━━━━━━━━━━━━" << std::endl;

	//파일의 끝을 알려주기 위해서 char 형이 아니라 int 형으로 받아온다
	int c;

	while ((c = in.get()) != EOF)
	{
		out.put(c);
	}

	out << std::endl << std::endl;

	//RAII
	/*in.close();
	out.close();*/
}

/*
using namespace std::chrono_literals;

	// 스톱워치 시작
	//std::chrono::steady_clock::timepoint begin = std::chrono::steady_clock::now();
	auto begin = std::chrono::steady_clock::now();
	std::this_thread::sleep_for(333ms);

	// 스톱워치 끝

	std::cout << "경과 시간(밀리초) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << std::endl;
	*/