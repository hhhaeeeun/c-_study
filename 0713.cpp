#include<stdio.h>
#include"common.h"
#include"func.h"

/*
//������ ����
1. ���� ����
2. ���� ����
3. ���� ����(static)
4. �ܺ� ����(extern)

//�޸� ����
1. ���� ����
2. ������ ����
3. �б� ����(�ڵ�, ROM)
4. �� ����

*/


//��������
int g_i = 0; // Data ����
//Data ���� Ư¡
//���α׷� ���� �� ����
//���α׷� ���� �� ����


//��������
static int g_iStatic = 0;   


int main()
{

	//��������

	Add(10, 20);

	giExtern = 500;


	return 0;

}