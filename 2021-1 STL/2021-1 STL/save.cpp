#include "save.h"

// google coding convention
void Save(std::string_view fileName)
{
	// � ������ �����ϴ��� ȭ�鿡 ���
	std::cout << "����: " << fileName << ", ũ��: " << std::filesystem::file_size(fileName) << std::endl;

	std::ofstream out("3�� 11��(��).txt", std::ios::app);
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