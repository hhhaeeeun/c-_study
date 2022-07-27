#pragma once

#include<assert.h>
template<typename T>
class CArr
{
private:
	T*			m_pData;
	int			m_iCount;
	int			m_iMaxCount;

public:
	void Push_back(const T& _Data);
	void resize(int _iResizeCount);
	T& operator[] (int idx);


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
template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	//m_pInt = (int*)malloc(sizeof(int) * 2);
	m_pData = new T[2];
}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
	m_iCount = 0;
	m_iMaxCount = 0;
}
template<typename T>
void CArr<T>::Push_back(const T& _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}
	//������ �߰�
	m_pData[m_iCount++] = _Data;
}
template<typename T>
void CArr<T>::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	//1. _iResizeCount ��ŭ ���� �Ҵ�
	T* pNew = new T[_iResizeCount];

	//2. ���� ������ ����
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	//3. ���� �޸� ����
	delete[] m_pData;

	//4. �迭�� ���� �Ҵ�� ������ ����Ű�� ��
	m_pData = pNew;

	//5. MaxCount ������ ����
	m_iMaxCount = _iResizeCount;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}
