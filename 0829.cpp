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

	//virtual �����Լ� ȭ
	virtual void OutPut()
	{
		cout << "Parent" << endl;
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

	//��ӹ��� �θ�Ŭ������ �Լ��� ������(�������̵�) ��
	void OutPut()
	{
		cout << "Child" << endl;
	}

	void NewFunc()
	{
		cout << "new function" << endl;
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
	{
		//�ڽ� �Ҹ� ������
		//�θ� �Ҹ��� ȣ�� !
	}
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
	//�����ڴ� �ڽ� ������ ȣ����ڸ��� �θ���� ����
	//������ ������� : �θ� -> �ڽ�
	//������ ȣ����� : �ڽ� -> �θ�
	
	//�����ε� vs �������̵�
	//�����ε� : �Լ����� ������ ���ڰ� �ٸ� (Ÿ��or����)
	//�������̵� : ���ڰ� ���Ƶ� �ڽ��ʿ��� ������ ����

	parent.OutPut();
	//�ڽ��� OutPut�� ȣ��
	//�������̵�
	child.OutPut();
	//�θ��� OutPut�� ȣ�� ����
	//�����Լ����� �θ��� OutPut ȣ���� ������
	child.CParent::OutPut();


	//�Ҹ���
	//�Ҹ��ڴ� �ڽ� �Ҹ� �� �ϰ� �θ�ȣ���Ͽ� �Ҹ� �� �� �ڽ����� ���ƿͼ� ����
	//�Ҹ��� ������� : �ڽ� -> �θ� 
	//�Ҹ��� ȣ����� : �ڽ� -> �θ�



	//������
	//���, ������

	//CParent* pParent = &parent;
	//CChild* pChild = &child;


	CParent* pParent = &child;
	//���� �ȳ�
	//�޸𸮿� �θ�->�ڽ� ������ �����Ǿ�����
	//�θ� Ŭ���� �����ͷ� ���� �� ����
	//CChild* pChild = &parent;
	//���� ��

	pParent->OutPut();
	//child�� �ּҸ� �޾Ƶ� parent��ü�� OutPut�Լ��� ȣ����
	//child�� �������̵� �� �Լ��� ȣ���� �� ����

	//virtual �����Լ�ȭ �ϸ� parent �����ͷ� �ڽ��� �������̵� �� �Լ� ȣ�� ����
	//������, �����Լ�
	//�����Լ��� �����ϸ� ���ʿ� �ڽ�Ŭ���� �����ÿ� �θ��� �����Լ� ���̺� �ڽ��� �������̵� �� �Լ��� ��ϵǾ�����


	//�ٿ�ĳ����
	//�ڽĿ��� ���� ������ �Լ��� �����ϰ� ���� ���
	//����ĳ���� or dynamic cast ����
	((CChild*)pParent)->NewFunc();
	//���� ���ɼ��� ����
	CChild* pChild = dynamic_cast<CChild*>(pParent);
	//���� ó�� ����!
	if (nullptr != pChild)
	{
		pChild->NewFunc();
	}
	//RTTI(Run Time Identification or Information


	//�߻�ȭ
	//���� ��ü�� ������ ������ Ŭ������ �ƴ�, ����� ���ؼ� �����ؾ��� ������ �����ϴ� ��� �������� ������� Ŭ����
	//virtual , = 0 (1�� �̻��� ���� �����Լ��� �����ϸ� �߻�Ŭ������ �ȴ�)

	return 0;
}