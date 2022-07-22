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
		//���� ���� ������ ��带 ã��
		//�ش� ����� NextNode�� �� Node�� �ּҸ� ����
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
	//Head��尡 null�̿��� �������
	pNode->pNextNode = _pList->pHeadNode;
	_pList->pHeadNode = pNode;
	++_pList->iCount;
}

//��͹��� free
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
//�ݺ������� free
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
