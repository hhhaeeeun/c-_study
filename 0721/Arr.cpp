#include "Arr.h"
#include <iostream>


void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void Reallocate(tArr* _pArr)
{
	//1. 기존공간보다 2배 큰 공간 할당
	_pArr->iMaxCount *= 2;
	int* pNew = (int*)malloc(sizeof(int) * _pArr->iMaxCount);

	//2. 기존 데이터 복사
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}
	
	//3. 기존 메모리 해제
	free(_pArr->pInt);

	//4. 배열이 새로 할당된 공간을 가리키게 함
	_pArr->pInt = pNew;
}

//데이터 추가함수
void PushBack(tArr* _pArr, int _iData)
{
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		//재할당
		Reallocate(_pArr);
	}
	//데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData;
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}
