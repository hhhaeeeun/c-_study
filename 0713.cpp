#include<stdio.h>
#include"common.h"
#include"func.h" //extern

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
	

	//������ ����
	//4����Ʈ �������� �����ͷ� ���� 
	//int ������ ����Ű�� ������ ��
	//�ش� �����Ͱ� ���޵� �ּҸ� �ؼ��ϴ� ����

	int i = 100;
	int* pInt = nullptr; 
	pInt = &i;

	float f = 3.f;
	//�ּҷ� ����


	pInt = (int*) & f;
	i= *pInt;

	pInt += 1;
	//+4 ������(������ġ��)

	/*
	pInt = new int[100];

	pInt[10] = 100;
	delete[] pInt;
	*/

	//�迭�� Ư¡
	//1. �޸𸮰� �������� �����̴�.
	//2. �迭�� �̸��� �迭�� ���� �ּ��̴�.

	int iArr[10] = {};
	
	//iArr[1] = *(iArr + 1);
	//����ǥ��

	*(iArr + 1) = 10;
	//iArr[1] = 10;

	*(iArr) = 10;


	int a;
	scanf_s("%d", &a);



	printf("%d\n", (int)sizeof(pInt));
	printf("%d\n", a);
	return 0;

} 