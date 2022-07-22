#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		//현재 가장 마지막 노드를 찾기
		//해당 노드의 NextNode에 새 Node의 주소를 전달
		tNode* next = _pList->pHeadNode;
		while (next->pNextNode)
		{
			next = next->pNextNode;
		}
		next->pNextNode = pNode;
	}
	++_pList->iCount;
}

void PushFront(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	//Head노드가 null이여도 상관없음
	pNode->pNextNode = _pList->pHeadNode;
	_pList->pHeadNode = pNode;
	++_pList->iCount;
}

//재귀버전 free
/*
void ReleaseNode(tNode* _pNode)
{
	if (_pNode == nullptr)
		return;
	ReleaseNode(_pNode->pNextNode);
	free(_pNode);
}
void ReleaseList(tLinkedList* _pList)
{
	ReleaseNode(_pList->pHeadNode);
}
*/
//반복문버전 free
void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeletNode = _pList->pHeadNode;
	tNode* pNext = nullptr;
	while (pDeletNode)
	{
		pNext = pDeletNode->pNextNode;
		free(pDeletNode);
		pDeletNode = pNext;
	}
}
