#include <iostream>
#include "Arr.h"

//����
//1. ���� (����)
//2. ����, ����, �ܺ�(������)


//�޸𸮿���
//������
//ROM
//�� ����(�����Ҵ�)


int main()
{
	int* pInt = (int*)malloc(100);
	//(int*)�� ���� ĳ����
	//malloc�� ������ void*
	//��û�� ��ŭ �޸𸮸� ������ ����
	//������ �ּ��� ����

	float* pF = (float*)malloc(4);
	int* pI = (int*)pF;

	*pF = 2.4f;
	int i = *pI;
	//�Ǽ����� 2.4�� �����Ͽ����� intŸ������ ������ �ٸ� ���ڷ� ǥ����

	//���� �Ҵ�
	//1. ��Ÿ�� �߿� ���� ����
	//2. ����ڰ� ���� �����ؾ� ��(����)
	/*
	pInt[0] =0xff;
	++pInt;
	pInt[0] = 0xff;
	*/
	free(pInt);
	free(pF);

	//��ü(Instance) 
	//int,
	//int a; 
	//int �ڷ���, a ��ü

	//�����迭


	tArr s;
	InitArr(&s);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s, i);
	}

	ReleaseArr(&s);
}