#include<stdio.h>
#include<wchar.h>

void Output(const int* pI)
{
	int i = *pI;
	//*pI = 100;
	//���� ������ �Ұ���

	int* pInt = (int*)pI;
	*pInt = 1000;
	//������ ����
	
}
int main()
{
	const int cint = 100;
	//volatile const int cint = 100;
	//���� ���� �ϸ� �������� ����ȭ�� ������� ����(volatile �ɼ�)


	int* pint = nullptr;

	//const ���� ������ �����Ͽ� ���� ����
	pint = (int*)&cint;
	(*pint) = 300;


	//���� �ٲ� 300���� ��µ�
	printf("%d\n", *pint);
	//�������� ���� �������� ������ 100���� ��µ�
	printf("%d\n", cint);
	//��� : ����� ó���ص� ���� ������ �Ҵ��


	const int i = 100;

	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	//a ���� ���� �ٲ�
	pInt = nullptr;
	//������ ���� �ٲ�


	const int* pConstInt = &a;
	//*pConstInt = 100;
	//���� ������ �� �ִ� Lvalue ���� �մϴ�.
	// �ش� ���� rvalue���� �ǹ�
	//const �����ʹ� ���� �����͸� ������ �� ����
	//��� : const int�� ����Ű�� ������(�ش� ���� const ȭ)

	int b = 0;
	pConstInt = &b;



	int* const pIntConst = &a;
	*pIntConst = 400;

	//pIntConst = &b;
	//���� ������ �� �ִ� Lvalue ���� �մϴ�.
	// �ش� ���� rvalue���� �ǹ�
	//const �����ʹ� �ʱⰪ�� ������ �� ����
	//��� : ������ ��ü�� const�� ������ �Ұ�����



	const int* const pConstIntConst = nullptr;
	//�ʱ�ȭ �� ����Ų ��� ����Ŵ, ����Ű�� ���� ������ �Ұ�

	int const* p = &a;
	//*p = 0
	//����

	{
		int a = 0;
		const int* pInt = &a;
		a = 100;

		int* p = &a;
		*p = 200;

		//a�� 0���� 100���� 200�� ��
	}

	a = 100;
	Output(&a);
	//���� �����Ͱ� �ʹ� Ŀ�� ���������� ���� �����ϱ� ���� �� �ּҸ� ���������� ���� ������ ����



	void* pVoid = nullptr;
	//��� �ڷ����� �ּҸ� ���� �޾Ƶ� ������ ���� ����
	// ������ �ڷ����� ������ ����
	//�ڷ� �ؼ��� �Һи���
	//������ �Ұ���(�ؼ��� �ȵǱ� ������)
	//�ּҿ��굵 �ȵ�

	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;

		/*
		*pVoid;
		pVoid + 1;
		�� �� �Ұ���
		*/
		
	}

	{
		//����
		char c = 49;
		wchar_t wc = 49;
		short s = 49;

		c = '1';
		bool b = 1;
		
		wc = '59';
		int i = 0;

	}

	{
		//���� 
		//char(1), wchar(2)
		char c = 'a';
		wchar_t wc = 'a';

		char szChar[7] = "abcdef";
		wchar_t szWChar[7] = L"abcdef";
		//wchar_t szWChar[7] = { 97, 98, 99, 100, 101, 102, };
		//���� ����
		//���ڴ� �������� 0�� ���ԵǾ�����

		short arrShort[10] = { 97, 98, 99, 100, 101, 102, };
		//short arrShort[10] = L"abcdef";
		//�Ұ���


		const wchar_t* pChar = L"abcdef";
		//���ڿ��� ��ü�� �ּҰ��� �����ϴ� ��
		//������ ������ �ּҰ��� ����
		//�б����� �޸𸮸� �����ϰ� ����
	}

	{
		wchar_t szName[10] = L"Raimond";

		int iLen = wcslen(szName);
		printf("%d\n", iLen);
	}

	
}




//�Լ� ���� Ȯ�� ����Ű
// Ctrl + Shift + Space