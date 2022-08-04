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
	T& at(int idx) { return m_pData[idx]; }
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	class iterator;
	//���۷����� ���� �����Ͱ� �ִ� ��쿡 ��������� 
	//�� ��쿡�� ���������� �����ϱ� ������ 
	//���۷���Ÿ���� ������� ����
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	void clear();
public:
	//�����ڿ� �Ҹ��ڴ� public���� �����ؾ� ��
	CArr();
	~CArr();
	//class ���� ���� class ����
	//inner class
	//���� �����͸� ����Ű�� ���� ����
	//���� class�� template��
	//inner class�� ���Ե� class�� private ��� ������ ������
	class iterator
	{
	private:
		CArr* m_pArr; //iterator�� ����ų �����͸� �����ϴ� �����迭 �ּ�
		T* m_pData;
		int m_iIdx;
		bool m_bValid;


	public:
		T& operator* ()
		{
			//iterator�� �˰��ִ� �����ּҿ� �����迭�� �˰��ִ� �ּҰ� �޶������ ����ó��
			//iterator�� end iterator �� ��� ����ó��
			if (m_pData != m_pArr->m_pData || -1 == m_iIdx || false == m_bValid)
				assert(nullptr);
			return m_pData[m_iIdx];
		}
		//���� ++ �Լ�
		iterator& operator++ ()
		{
			//end iterator
			//�ּҰ� �����
			if (m_pData != m_pArr->m_pData || -1 == m_iIdx|| false == m_bValid)
				assert(nullptr);

			//iterator�� ������ �����͸� ����Ű�� �ִ� ��� 
			if (m_iIdx == m_pArr->size() - 1)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		//���� ++ �Լ�
		//int ���ڸ� �ۼ��Ͽ� ������ �з���
		iterator operator++(int)
		{
			//���������� �����ϰ� ���� ���� ++ ��
			//*this Ȯ�� 
			iterator copy_iter = *this;
			++(*this);
			return copy_iter;

		}
		//����
		iterator& operator-- ()
		{
			//begin iterator
			//�ּҰ� �����
			if (m_pData != m_pArr->m_pData || 0 == m_iIdx || false == m_bValid)
				assert(nullptr);

			//iterator�� end()�� ����Ű�� �ִ� ��� 
			if (m_iIdx == -1)
			{
				m_iIdx = m_pArr->capacity() - 1;
			}
			else
			{
				--m_iIdx;
			}

			return *this;
		}
		//����
		iterator operator--(int)
		{
			//���������� �����ϰ� ���� ���� -- ��
			//*this Ȯ�� 
			iterator copy_iter = *this;
			--(*this);
			return copy_iter;
		}

		bool operator == (const iterator& iter)
		{
			if ((m_iIdx == iter.m_iIdx) && (m_pData == iter.m_pData))
				return true;
			else
				return false;
		}
		bool operator != (const iterator& iter)
		{
			/*
			if (m_iIdx == iter.m_iIdx && m_pData == iter->m_pData)
				return false;
			else
				return true;
				*/
				//==operator�� ����� �ݴ�� ���
			return !(*this == iter);
		}


	public:
		iterator()
			:m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{

		}
		iterator(CArr* _pArr, T* _pData, int iIdx)
			:m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(iIdx)
			, m_bValid(false)
		{
			if (m_pArr != nullptr && 0 <= m_iIdx)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}
		friend class CArr;
	};
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

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	/*
	iterator iter;
	iter.m_pData = this->m_pData;
	iter.m_iIdx = 0;
	*/
	/*
	iterator iter(m_pData, 0);
	return iter;
	*/
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); //�����Ͱ� ���� ��� begin() == end()

	//�ӽð�ü �������ڸ��� ��ȯ
	return iterator(this, this->m_pData, 0);
}
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	//iterator�� CArr�� �ּҸ� �Է¹ޱ� ������ this�� ����
	return iterator(this, this->m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	//�ܺ� class�� ���� class�� private�� ������ �� ����
	//���� class�� �ܺ� class�� private�� ������ �� ����
	//ģ�������ϸ� ������ private�� ���� ����
	//��� Ŭ������ ģ�������ϸ� ���� private�� ���Ŭ�������� ������
	

	//iterator�� ����Ű�� ����� ȣ��� CArr�� �ٸ�
	//CArr����ü ���İ˻�, end iterator�� ���
	if ((_iter.m_pArr != this) || (_iter.m_iIdx >= this->m_iCount))
	{
		assert(nullptr);
	}
	if (end() == _iter)
		assert(nullptr);

	//iterator�� ����Ű�� �����͸� �迭 ������ ����
	_iter.m_iIdx;
	for (int i = _iter.m_iIdx; i < m_iCount - 1; ++i)
		m_pData[i] = m_pData[i + 1];

	--m_iCount;

	//���� iterator ��� �Ұ� ó�� 
	//_iter(this, m_pData, _iter.m_iIdx);
	//iterator�� ���� �������̱� ������ �ּҰ��� �־����� �ʾƵ� ���� Ŭ������ ����Ǹ� ���� ����� �ּҸ� ������
	//const���� �ּҰ��� �����ϴ� ���� �ƴϱ� ������ �������
	//���� �Լ��� const�� �ƴ� ������ ����� iterator�� ����ó���� ���ֱ� ���� (m_bValid)
	_iter.m_bValid = false;

	return iterator(this, this->m_pData, _iter.m_iIdx);
}

template<typename T>
void CArr<T>::clear()
{
	m_iCount = 0;
}
