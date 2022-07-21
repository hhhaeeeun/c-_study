#include <iostream>
#include "Arr.h"

//변수
//1. 지역 (스택)
//2. 전역, 정적, 외부(데이터)


//메모리영역
//데이터
//ROM
//힙 영역(동적할당)


int main()
{
	int* pInt = (int*)malloc(100);
	//(int*)로 강제 캐스팅
	//malloc의 리턴은 void*
	//요청한 만큼 메모리를 리턴할 뿐임
	//순수한 주소의 개념

	float* pF = (float*)malloc(4);
	int* pI = (int*)pF;

	*pF = 2.4f;
	int i = *pI;
	//실수값은 2.4로 저장하였지만 int타입으로 읽으면 다른 숫자로 표현됨

	//동적 할당
	//1. 런타임 중에 대응 가능
	//2. 사용자가 직접 관리해야 함(해제)
	/*
	pInt[0] =0xff;
	++pInt;
	pInt[0] = 0xff;
	*/
	free(pInt);
	free(pF);

	//객체(Instance) 
	//int,
	//int a; 
	//int 자료형, a 객체

	//가변배열


	tArr s;
	InitArr(&s);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s, i);
	}

	ReleaseArr(&s);
}