#include "CArr.h"
#include <assert.h>


void CArr::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	//1. _iResizeCount 만큼 공간 할당
	int* pNew = new int[_iResizeCount];

	//2. 기존 데이터 복사
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}

	//3. 기존 메모리 해제
	delete[] m_pInt;

	//4. 배열이 새로 할당된 공간을 가리키게 함
	m_pInt = pNew;

	//5. MaxCount 변경점 적용
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
		//재할당
		resize(m_iMaxCount * 2); 
	}
	//데이터 추가
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
