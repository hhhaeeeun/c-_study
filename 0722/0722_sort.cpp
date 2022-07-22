#include "Arr.h"
#include "LinkedList.h"
#include <time.h>
#include <iostream>

void BubbleSort(int* _pData, int _iCount)
{
	if (_iCount <= 1)
	{
		return;
	}
	int iLoop = _iCount - 1;
	while (true)
	{
		bool bFinish = true;
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int tmp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = tmp;

				bFinish = false;
			}
		}
		if (bFinish)
			break;
		--iLoop;
	}
}
void Test()
{

}

int main()
{

	//함수포인터
	//반환, 주소, 인자
	void(*pFunc)(void) = nullptr;
	pFunc = Test;

	//Test함수 호출
	pFunc();
	

	tArr s = {};
	InitArr(&s);


	srand(time(nullptr));

	for (int i = 0; i < 10; ++i)
	{
		int tmp = rand() % 100 + 1;
		PushBack(&s, tmp);
	}
	for (int i = 0; i < s.iCount; ++i)
		printf("%d ", s.pInt[i]);
	printf("\n");

	//함수포인터로 정렬함수 사용
	Sort(&s,&BubbleSort);

	for (int i = 0; i < s.iCount; ++i)
		printf("%d ", s.pInt[i]);
	printf("\n");




	ReleaseArr(&s);
	return 0;

}

//1. 가변배열
//스스로 복습

//2. 가변배열 안에 넣은 데이터 정렬 
// - 버블 정렬