//������������������������������������������������������������
// 3�� 25�� ����� (4�� 2��)
// 
// Containers: objects that store other objects
// �ڷᱸ��: �ٸ� ��ü�� �����ϴ� ��ü
// 
// Sequence Containers
// - array
// - vector
// - deque
// - forward_list
// - list
// 
// ���� class�� �̵���� �ڵ� - sort �Լ��� Ȯ��
//������������������������������������������������������������

#include "pch.h"
#include "save.h"
#include "String.h"

// [�ǽ�] main�� ����� �� �ְ� Array�� ���α׷��϶�

template<typename T, int N>
class Array
{
private:
	T data[N]{ 0 };
public:
	Array() {}
public:
	size_t size() const { return N; }

	T* begin() { return data; }
	T* end() { return data + N; }
public:
	T operator[](int idx) const { return data[idx]; }
	T& operator[](int idx) { return data[idx]; }
};

int main()
{
	Array<String, 10> a;

	for (int i = 0; i < a.size(); ++i)
	{
		a[i] = i * i;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << std::endl;
	}

	std::cout << "\n�ݺ��ڷ� ���" << std::endl;
	
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	Save("main.cpp");
}