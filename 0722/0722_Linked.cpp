#include<iostream>
#include "LinkedList.h"

int main()
{
	tLinkedList List = {};
	InitList(&List);

	void(*pFunc)(tLinkedList*, int) = nullptr;
	//pFunc = PushBack;
	pFunc = PushFront;


	pFunc(&List, 100);
	pFunc(&List, 200);
	pFunc(&List, 300);

	tNode* pNode = List.pHeadNode;
	while (pNode)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}

	ReleaseList(&List);
	return 0;
}

//�����迭�� ���� ����Ʈ�� ����
//Ư�� n��° ��ġ�� Index ������ ����� o(n)
//�����迭�� �����ּ� + n���� �ѹ��� ���ٰ��� 

//�����迭�� ���� ����Ʈ�� ����
//�� �տ� �����͸� �Է��ϱ� ���� o(1)
//�����迭�� ��� �ڷ� ��ĭ�� �����ؾ� �� o(n)