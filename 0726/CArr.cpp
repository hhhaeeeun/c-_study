#include "CArr.h"
#include <assert.h>


void CArr::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	//1. _iResizeCount ��ŭ ���� �Ҵ�
	int* pNew = new int[_iResizeCount];

	//2. ���� ������ ����
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}

	//3. ���� �޸� ����
	delete[] m_pInt;

	//4. �迭�� ���� �Ҵ�� ������ ����Ű�� ��
	m_pInt = pNew;

	//5. MaxCount ������ ����
	m_iMaxCount = _iResizeCount;
}
int& CArr::operator[](int idx)
{
	return m_pInt[idx];
}
void CArr::Push_back(int _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2); 
	}
	//������ �߰�
	m_pInt[m_iCount++] = _Data;
}
CArr::CArr()
	: m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	//m_pInt = (int*)malloc(sizeof(int) * 2);
	m_pInt = new int[2];
}

CArr::~CArr()
{
	delete[] m_pInt;
	m_iCount = 0;
	m_iMaxCount = 0;
}
