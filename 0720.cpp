#include<stdio.h>
#include<wchar.h>
#include<assert.h>
typedef struct MyStyle {
	int a;
	float f;
}MYST;


//�Լ� �����ε� 
//������ Ÿ��or������ ������ ������
void Test(int a)
{


}
void Test(float a)
{

}
unsigned int GetLength(const wchar_t* _pStr)
{
	int i = 0;
	while ('\0' != (*_pStr))
	{
		++i;
		++_pStr;
	}
	/*
	while ('\0' != _pStr[i])
	{
		++i;
	}
	*/
	return i;
}
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDsetLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pDest);

	if (_iBufferSize < iDsetLen + iSrcLen + 1) //null���ڱ��� ���
	{
		assert(nullptr);//����ó��
	}
	//���ڿ� �̾���̱�
	//1. Dest�� null ã��
	//2. Src�� iSrcLen ��ŭ �̾���̱�
	int i = 0;
	while (iSrcLen + 1 != i)
	{
		*(_pDest + iDsetLen + i) = *(_pSrc + i);
		++i;
	}
	/*
	for (int i = 0; i < iSrcLen + 1; ++i)
	{
		_pDest[iDsetLen + i] = _pSrc[i];
	}
	*/
}
//1. front�� back�� ���� ������ ���� ���Ѵ�.
//2. �տ��� ��� ������� ��� �쿭�� ����
int StrCmp(const wchar_t* _pFront, const wchar_t* _pBack)
{
	int iFrontLen = GetLength(_pFront);
	int iBackLen = GetLength(_pBack);

	int sLen = 0;
	iFrontLen > iBackLen ? sLen = iBackLen : sLen = iFrontLen;
	//sLen = iFrontLen > iBackLen ? iBackLen : iFrontLen;
	for (int i = 0; i < sLen +1; ++i)
	{
		if (_pFront[i] > _pBack[i])
		{
			return 1;
		}
		else if (_pFront[i] < _pBack[i])
		{
			return -1;
		}
	}
	return 0;
}
int main()
{

	wchar_t szName[10] = L"Raimond";
	int iLen = 0;

	iLen = GetLength(szName);
	//printf("%d\n", iLen);
	iLen = wcslen(szName);
	//printf("%d\n", iLen);

	//*(iArr + 5) == iArr[5] ���� ǥ��
	

	//�Լ� �����ε�
	Test(10);
	Test(10.f);

	//���ڿ� �̾���̱�

	wchar_t szString[100] = L"abc";
	//wcscat_s(szString, 100, L"def");
	//wcscat_s(szString, 100, L"ghi"); 

	StrCat(szString, 100, L"def");
	StrCat(szString, 100, L"ghi");

	//������ 0, �ڿ��� �� �쿭�� ������ 1, �տ��� �� �쿭�� ������ -1
	int iRet = wcscmp(L"abc", L"abcc");
	//printf("%d\n", iRet);
	iRet = StrCmp(L"cbccc", L"abcc");
	//printf("%d\n", iRet);



	//����ü�� ������
	MYST s = {};

	MYST* pST = &s;
	(*pST).a = 10;
	(*pST).f = 3.14f;

	pST->a = 10;
	pST->f = 3.14f;

	return 0;
}