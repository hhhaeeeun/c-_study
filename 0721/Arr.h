#pragma once

typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;


//�Լ� ���� �����
//ctrl + '+' + '.'

//�迭 �ʱ�ȭ
void InitArr(tArr* _pArr);

//������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

//�迭 �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);