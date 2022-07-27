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
	//생성자와 소멸자는 public으로 생성해야 함
	CArr();
	~CArr();
};


//주석 설정						: Ctrl + k , c 
//지정한 주석 해제		: Ctrl + k , u
//Alt Drag
//Alt Enter							: 정의만들기
//Ctal+tap							: 파일 간 이동
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
		//재할당
		resize(m_iMaxCount * 2);
	}
	//데이터 추가
	m_pData[m_iCount++] = _Data;
}
template<typename T>
void CArr<T>::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	//1. _iResizeCount 만큼 공간 할당
	T* pNew = new T[_iResizeCount];

	//2. 기존 데이터 복사
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	//3. 기존 메모리 해제
	delete[] m_pData;

	//4. 배열이 새로 할당된 공간을 가리키게 함
	m_pData = pNew;

	//5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}
