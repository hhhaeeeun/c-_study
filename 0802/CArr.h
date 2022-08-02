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
	class iterator
	{
	private:
		CArr* m_pArr;
		T* iter;
		int m_iIdx;

	public:
		T& operator*()
		{
			//iterator가 알고있는 시작주소와 가변배열이 알고있는 주소가 달라진경우 오류처리
			//iterator가 end iterator 인 경우 오류처리
			if (iter != m_pArr->m_pData || -1 == m_iIdx)
				assert(nullptr);
			return iter[m_ildx];
		}
		T& operator++()
		{
			return iter + (++m_iIdx);
		}


		iterator()
			:m_pArr(nullptr)
			, iter(nullptr)
			, m_iIdx(-1)
		{

		}
		iterator(CArr* cData, T* pData, int iIdx)
			:m_pArr(cData)
			,iter(pData)
			,m_iIdx(iIdx)
		{

		}

	};
	iterator begin()
	{
		//이너클래스는 부모클래스의 private에 접근할 수 있음
		//생성자로 전달
		//지역변수 생성해서 리턴해도 됨
		return iterator(this, this->m_pData, 0);
	}
	iterator end()
	{
		return iterator(this, m_pData, -1);
	}
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
