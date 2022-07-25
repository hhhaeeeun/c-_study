#include <iostream>
#include "Arr.h"
struct tMy
{

};

class CMy
{

private :
	int m_i;
	float m_f;
public:
	void SetInt(int i)
	{
		m_i = i;
	}

	//���� ������

	 CMy& operator = (const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this;
	}
	CMy& operator + (const CMy& _Other)
	{
		m_i += _Other.m_i;
		m_f += _Other.m_f;

		return *this;
	}
	void print_m_i()
	{
		printf("m_i : %d\n", m_i);
	}
public:
	//������
	CMy()
		: m_i(100)
		, m_f(0.f)
	{
		//m_i = 100;
		//m_f = 0.f;
	}
	//�Ҹ���
	~CMy()
	{

	}
};


int main()
{
	//C++ Ŭ���� Ư¡
	//���� ���� ������
	//private, protected(���), public
	
	//������, �Ҹ��� 
	//��ü ����, �Ҹ� �� �ڵ����� ȣ��
	//���� ������ ������ �⺻ ������, �⺻ �Ҹ��ڰ� ������� 
	
	//����Լ�
	//�ش� Ŭ������ ����ϴ� ���� �Լ�
	//�ش� Ŭ������ ��ü(instance)�� �ʿ���
	//int(�ڷ���) a(��ü)
	//����Լ��� ��ü�� ���ؼ� ȣ���ϸ�, �ش� ��ü�� �ּҰ� this �����ͷ� ���޵ȴ�.

	{
		//�ڷ���* ������;            ������ ���� ����
		//*�����ͺ���;                 ������ �ּ� ������
		//&����;                              ������ �ּҰ�
		//�ڷ���& ������;;          ���۷��� ���� ����


		//C++�� �߰��� ���
		//�����Ϳ� ����
		//������ �����Ѵ�.
		//���������� ���ؼ� ���������� ������ ���� �� �� �ִ�. 

		int a = 10;

		int* p = &a;
		*p = 100;

		int& iRef = a;
		iRef = 100;
		//���۷��� ���� ����
		//�ѹ� ���� ���� ������ �Ұ��� int* const p = &a �� ����
		//������ ���� ���� ������ �� ����
		//ȣ������ �ٸ�
		//�ּҸ� �޴� ���� �ƴ϶� �� ��ü�� ��

		const int* p2 = &a;
		//*p2 = 100;

		const int& iRefConst = a;
		//const int* const p2 = &a; �� ����
		//iRefConst = 100;
	}

	tArr arr = {};
	InitArr(&arr);
	PushBack(&arr, 10);
	arr.iCount = 100;
	ReleaseArr(&arr);

	CMy c;
	c.SetInt(10);

	CMy c2;
	c2.SetInt(100);
	c2.print_m_i();
	CMy c3;
	c3.SetInt(1000);

	c2 = c2 + c3;
	c2.print_m_i();


	return 0;
}