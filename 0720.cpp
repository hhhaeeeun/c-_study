#include<stdio.h>
#include<wchar.h>
#include<assert.h>
typedef struct MyStyle {
	int a;
	float f;
}MYST;


//함수 오버로딩 
//인자의 타입or개수로 구별이 가능함
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

	if (_iBufferSize < iDsetLen + iSrcLen + 1) //null문자까지 계산
	{
		assert(nullptr);//예외처리
	}
	//문자열 이어붙이기
	//1. Dest의 null 찾기
	//2. Src를 iSrcLen 만큼 이어붙이기
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
//1. front와 back의 문자 끝까지 전부 비교한다.
//2. 앞에가 모두 같은경우 긴게 우열이 낮음
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

	//*(iArr + 5) == iArr[5] 같은 표현
	

	//함수 오버로딩
	Test(10);
	Test(10.f);

	//문자열 이어붙이기

	wchar_t szString[100] = L"abc";
	//wcscat_s(szString, 100, L"def");
	//wcscat_s(szString, 100, L"ghi"); 

	StrCat(szString, 100, L"def");
	StrCat(szString, 100, L"ghi");

	//같으면 0, 뒤에가 더 우열이 높으면 1, 앞에가 더 우열이 높으면 -1
	int iRet = wcscmp(L"abc", L"abcc");
	//printf("%d\n", iRet);
	iRet = StrCmp(L"cbccc", L"abcc");
	//printf("%d\n", iRet);



	//구조체와 포인터
	MYST s = {};

	MYST* pST = &s;
	(*pST).a = 10;
	(*pST).f = 3.14f;

	pST->a = 10;
	pST->f = 3.14f;

	return 0;
}