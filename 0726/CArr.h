#pragma once
class CArr
{
private:
	int*			m_pInt;
	int			m_iCount;
	int			m_iMaxCount;

public:
	void Push_back(int _Data);
	void resize(int _iResizeCount);

	int& operator[] (int idx);


public:
	//�����ڿ� �Ҹ��ڴ� public���� �����ؾ� ��
	CArr();
	~CArr();
};


//�ּ� ����						: Ctrl + k , c 
//������ �ּ� ����		: Ctrl + k , u
//Alt Drag
//Alt Enter							: ���Ǹ����
//Ctal+tap							: ���� �� �̵�

