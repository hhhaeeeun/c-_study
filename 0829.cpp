#include <iostream>

using std::cout;
using std::endl;


class CParent
{
//protected : ��ӹ��� class�� ������ �����ϵ��� ����
//private : ��� �޾Ƶ� ���� ������ �Ұ���
//public : ��� ���� ����
protected:
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}
public:
	//�⺻ ������
	CParent()
		:m_i(0)
	{
		cout << "�θ� ������ ȣ��" << endl;
	}

	CParent(int _a)
		:m_i(_a)
	{
		cout << "�θ� ������ ȣ��" << endl;
	}


	~CParent()
	{}
};


class CChild : public CParent
{
private:
	float m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 10;
	}
public:
	//Ŭ���� ������ ���� �ʱ�ȭ �ϱ�(�ڽ��� ��������� �ʱ�ȭ)
	//������ ȣ�� ���� : 
	CChild()
		//:CParent() //�θ� ������ ȣ�� ����//���� �ʾƵ� �θ� Ŭ������ �����ڰ� ���� �ڵ�ȣ���!//�Ųٷ� ��� ����
		//,m_f(0.f)
		//m_i(0) //�Ұ���
		:m_f(0.f)
		,CParent(1000)
	{
		//����
		//m_i = 0;
		cout << "�ڽ� ������ ȣ��" << endl;
	}
	~CChild()
	{}
};

void FuncA()
{
	cout << "Func A" << endl;
}


void FuncB()
{
	FuncA();

	cout << "Func B" << endl;
}
int main()
{

	//FunB�� ȣ��Ǿ�����
	//�Լ� �Ϸ� ���� ������ A->B
	//ȣ������� B->A
	FuncB();

	//������(���) ȣ�⵵ ����������
	//��������� �θ�->�ڽ�
	//ȣ������� �ڽ�->�θ�

	//��ü���� ��� Ư¡
	//1. ĸ��ȭ(���м�)
	//2. ���
	//3. ������
	//4. �߻�ȭ


	CParent parent;
	//CChild = CParent + CChild
	CChild child;
	parent.SetInt(10);
	child.SetInt(10);

	//���
	//�ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ������ ����� �ʱ�ȭ �� �� ����.
	//������ ������� : �θ� -> �ڽ�
	//������ ȣ����� : �ڽ� -> �θ�
	


	return 0;
}