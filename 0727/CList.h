#pragma once
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
	CList();
	~CList();
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