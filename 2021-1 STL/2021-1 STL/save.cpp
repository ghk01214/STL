#include "save.h"

// google coding convention
void Save(std::string_view fileName)
{
	// � ������ �����ϴ��� ȭ�鿡 ���
	std::cout << "����: " << fileName << ", ũ��: " << std::filesystem::file_size(fileName) << std::endl;

	std::ofstream out("5�� 06��(��).txt", std::ios::app);
	std::ifstream in(fileName);

	//������ ����� �ð��� ǥ��
	time_t t = std::time(nullptr);

	//�ð� ��� ���� ����
	out.imbue(std::locale("korean"));

	out << "����������������������������������������" << std::endl;
	out << "����ð�: " << std::put_time(localtime(&t), "%c %A") << std::endl;
	out << "����������������������������������������" << std::endl;

	//������ ���� �˷��ֱ� ���ؼ� char ���� �ƴ϶� int ������ �޾ƿ´�
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

	// �����ġ ����
	//std::chrono::steady_clock::timepoint begin = std::chrono::steady_clock::now();
	auto begin = std::chrono::steady_clock::now();
	std::this_thread::sleep_for(333ms);

	// �����ġ ��

	std::cout << "��� �ð�(�и���) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << std::endl;
	*/