#include <vector>
#include <list>
#include<iostream>
#include"CArr.h"

using std::vector;
using std::list;
using std::cout;
using std::wcout;
using std::cin;
using std::endl;


//class�� �ڵ����� �����Ǵ� ���� 
//������, �Ҹ���
//���Կ�����
//���������
//�����ڸ� �ϳ��� �ۼ��ϸ� �⺻�����ڸ� �ڵ����� ���������� ���� 
//������ �� ������ �� ���� �ۼ��ؾ���
//�ǹ� : �Ҹ��ڴ�?
class CTest
{
private:
	int m_i;

public:
	//���Կ�����
	CTest& operator = (const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}
	//�⺻������
	CTest()
		:m_i(0)
	{

	}
	//���������
	CTest(const CTest& _other)
		:m_i(_other.m_i)
	{

	}
};

int main()
{
	CArr<int> myvector;

	myvector.Push_back(1);
	myvector.Push_back(2);
	myvector.Push_back(3);

	CArr<int>::iterator CArrIter = myvector.begin();

	for (; CArrIter != myvector.end(); ++CArrIter)
	{
		cout << *CArrIter << endl;
	}
	CTest t1;
	CTest t2(t1);

	//��������ڰ� �ƴϰ� ����operator�ε�
	//������(init) �� ���Կ����� �ƴϰ� �����Ϸ��� ��������ڸ� �ڵ����� ȣ������
	CTest t3 = t1;
}