#include <iostream>
#include"Arr.h"
#include "CArr.h"


int main()
{

	//����ü --> Ŭ���� 
	//��ü���� ��� Ư¡
	
	//1. ĸ��ȭ
	//����� �����ϱ� ���� �ʿ��� ��� ����, ����, ���м�
	//��� �Լ���

	//2. ���

	//3. ������ 
	
	//4. �߻�ȭ 
	 
	//����ü ���� �������� --> Ŭ���� ����

	//C++ �����Ҵ� new, delete
	//new, delete�� ������, �Ҹ��� ȣ���� ���Ե�

	tArr arr = {};

	InitArr(&arr);

	PushBack(&arr, 10);
	PushBack(&arr, 20);
	PushBack(&arr, 30);

	ReleaseArr(&arr);

	CArr carr;
	carr.Push_back(10);
	carr.Push_back(20);
	carr.Push_back(30);

	int iData = carr[1];
	carr[1] = 40;

	return 0;
}