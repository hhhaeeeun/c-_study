#include <iostream>
#include"Arr.h"
#include "CArr.h"

//�Լ� ���ø�
template<typename T>
T Add(T a, T b)
{
	return a + b;
}


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

	//CArr<int> carr;
	//carr.Push_back(10);
	//carr.Push_back(20);
	//carr.Push_back(30);

	//int iData = carr[1];
	//carr[1] = 40;

	int i = Add<int>(10, 20);


	CArr<float> carr;
	carr.Push_back(10.15f);
	carr.Push_back(20.45f);
	carr.Push_back(30.242f);

	float fData = carr[1];
	return 0;
}