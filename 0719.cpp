#include<stdio.h>


int main()
{
	const int cint = 100;
	//volatile const int cint = 100;
	//���� ���� �ϸ� �������� ����ȭ�� ������� ����(volatile �ɼ�)
	

	int* pint = nullptr;

	//const ���� ������ �����Ͽ� ���� ����
	pint = (int*) & cint;
	(*pint) = 300;
	

	//���� �ٲ� 300���� ��µ�
	printf("%d\n", *pint);
	//�������� ���� �������� ������ 100���� ��µ�
	printf("%d\n", cint);
	//��� : ����� ó���ص� ���� ������ �Ҵ��
}