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

//가변배열에 비해 리스트의 단점
//특정 n번째 위치의 Index 접근이 어려움 o(n)
//가변배열은 시작주소 + n으로 한번에 접근가능 

//가변배열에 비해 리스트의 장점
//맨 앞에 데이터를 입력하기 쉬움 o(1)
//가변배열은 모두 뒤로 한칸씩 복사해야 함 o(n)