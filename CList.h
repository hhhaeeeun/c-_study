#pragma once
#include <assert.h>
template<typename T>
struct tListNode
{
	T iData;
	tListNode<T>* pPrev;
	tListNode<T>* pNext;


	tListNode()
		:iData()
		,pPrev(nullptr)
		, pNext(nullptr)
	{

	}

	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		:iData(_data)
		,pPrev(_pPrev)
		,pNext(_pNext)
	{

	}
};

template<typename T>
class CList
{
private:
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;
	int					m_iCount;


public:
	void PushBack(const T& _iData);
	void PushFront(const T& _iData);
	int size() { return m_iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _Data);
public:
	CList();
	~CList();


	class iterator {
	private:
		CList<T>* m_pList;
		tListNode<T>* m_pNode;
		bool m_bValid;



	public:
		T& operator* ()
		{
			return m_pNode->iData;
		}

		bool operator ==(const iterator& _otheriterator)
		{
			if (m_pList == _otheriterator.m_pList && m_pNode == _otheriterator.m_pNode)
			{
				return true;
			}
			else
				return false;
		}

		bool operator !=(const iterator& _otheriterator)
		{
			return !(*this == _otheriterator);
		}
		//전위
		iterator& operator ++()
		{
			if (nullptr == m_pNode || !m_bValid)
				assert(nullptr);
			m_pNode = m_pNode->pNext;
			return *this;
		}
		//후위
		iterator operator ++(int)
		{
			if (nullptr == m_pNode || !m_bValid)
				assert(nullptr);

			iterator copyiter(*this);
			++(*this);
			return copyiter;

		}
		//전위
		iterator& operator --()
		{
			if (this->m_pList->m_pHead == m_pNode || !m_bValid)
				assert(nullptr);
			m_pNode = m_pNode->pPrev;
			return *this;
		}
		//후위
		iterator operator --(int)
		{
			if (this->m_pList->m_pHead == m_pNode || !m_bValid)
				assert(nullptr);

			iterator copyiter(*this);
			--(*this);
			return copyiter;
		}
	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			,m_bValid(false)
		{

		}

		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr!= _pNode)
				m_bValid = true;
		}
		//가르키던 클래스가 소멸하는 경우에 원본을 지우지 않음
		~iterator()
		{

		}


		friend class CList;
	};


};



template<typename T>
void CList<T>::PushBack(const T& _iData)
{
	tListNode<T>* pNewNode = new tListNode<T>(_iData, nullptr, nullptr);
	
	if (m_pHead == nullptr)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
		m_pTail = pNewNode;
	}
	++m_iCount;
}

template<typename T>
 void CList<T>::PushFront(const T& _iData)
{
	tListNode<T>* pNewNode = new tListNode<T>(_iData, nullptr, nullptr);
	if (m_pHead == nullptr)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		pNewNode->pNext = m_pHead;
		m_pHead->pPrev = pNewNode;
		m_pHead = pNewNode;
	}
	++m_iCount;
}

 template<typename T>
 inline typename CList<T>::iterator CList<T>::begin()
 {
	 return iterator(this, this->m_pHead);
 }

 template<typename T>
 inline typename CList<T>::iterator CList<T>::end()
 {
	 return iterator(this, nullptr);
 }

 template<typename T>
 inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
 {
	 tListNode<T>* tmpNode = _iter.m_pNode->pPrev;
	 _iter.m_pNode->pPrev->pNext = _iter.m_pNode->pNext;
	 _iter.m_pNode->pNext->pPrev = _iter.m_pNode->pPrev;

	 delete(_iter.m_pNode);
	 _iter.m_pNode = tmpNode;
	 return iterator(this, _iter.m_pNode);
 }

 template<typename T>
 inline typename CList<T>::iterator CList<T>::insert(const iterator & _iter, const T& _Data)
 {
	 if (end() == _iter)
		 assert(nullptr);
	 tListNode<T>* pNewNode = new tListNode<T>(_Data, nullptr, nullptr);

	 //현재가 헤드노드인경우 헤드노드를 변경
	 if (_iter.m_pNode == m_pHead)
	 {
		 _iter.m_pNode->pPrev = pNewNode;
		 m_pHead = pNewNode;
	 }
	 else
	 {
		 //아닌경우 끼워넣기
		 _iter.m_pNode->pPrev->pNext = pNewNode;
		 pNewNode->pPrev = _iter.m_pNode->pPrev;
		 _iter.m_pNode->pPrev = pNewNode;
	 }
	 pNewNode->pNext = _iter.m_pNode;
	 
	 ++m_iCount;

	 return iterator(this, pNewNode);
 }

 template<typename T>
CList<T>::CList()
	:m_pHead(nullptr)
	,m_pTail(nullptr)
	,m_iCount(0)
{
}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;
	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNext;
	}
}