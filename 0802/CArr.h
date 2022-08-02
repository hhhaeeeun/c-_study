#pragma once
#include <assert.h>
template <typename T>
class CArr
{
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	void Push_Back(const T& _Data);
	void resize(int iResizeCount);
	CArr();
	~CArr();
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idex);
	T* data() { return m_pData; }
	T& at(int idx) { return m_pData[idx]; }

};

template<typename T>
void CArr<T>::Push_Back(const T& _Data)
{
	if (m_iCount >= m_iMaxCount)
	{
		resize(m_iMaxCount + 2);
	}
	m_pData[m_iCount++] = _Data;	
}

template<typename T>
inline void CArr<T>::resize(int iResizeCount)
{
	if (m_iMaxCount >= iResizeCount)
		assert(nullptr);
	T* pNew = new T[iResizeCount];
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}
	delete[] m_pData;
	m_pData = pNew;
	m_iMaxCount = iResizeCount;
}

template<typename T>
CArr<T>::CArr()
	:m_pData(nullptr)
	,m_iCount(0)
	,m_iMaxCount(2)
{
	m_pData = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
	m_iCount;
	m_iMaxCount;
}

template<typename T>
T& CArr<T>::operator[](int Idx)
{
	return m_pData[Idx];
	//return *(m_pData + Idx);
}
