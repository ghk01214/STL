//������������������������������������������������������������
// 3�� 11�� ����� (2�� 2��)
// 
// ���� ���� ������ �ٷ�� - int���� ����
// ������ �ø��� �ڷᰡ ����Ǵ� ��İ� ������ �����Ѵ�.
// ���� ���� �ڷḦ �����ϴ� ����� �˾ƺ���
// 
// sort() ���� �ٽ� - ����� ����/��Ƚ�� ���� ���캸��
// ��ü�� ���� ����� �ݺ�
// 
// �˰��� �ð����
// ����Ʈ ������
// 
// ������ ����� class ����� �α�
//������������������������������������������������������������

#include "pch.h"
#include "save.h"
#include <thread>
#include <chrono>

// [����] 

int main()
{
	using namespace std::chrono_literals;

	// �����ġ ����
	//std::chrono::steady_clock::timepoint begin = std::chrono::steady_clock::now();
	auto begin = std::chrono::steady_clock::now();
	std::this_thread::sleep_for(333ms);

	// �����ġ ��

	std::cout << "��� �ð�(�и���) : " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << std::endl;
	//Save("main.cpp");
}