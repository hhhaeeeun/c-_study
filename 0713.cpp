#include<stdio.h>
#include"common.h"
#include"func.h" //extern

/*
//변수의 종류
1. 지역 변수
2. 전역 변수
3. 정적 변수(static)
4. 외부 변수(extern)

//메모리 영역
1. 스택 영역
2. 데이터 영역
3. 읽기 전용(코드, ROM)
4. 힙 영역

*/


//전역변수
int g_i = 0; // Data 영역
//Data 영역 특징
//프로그램 시작 시 생성
//프로그램 종료 시 해제


//정적변수
static int g_iStatic = 0;   


int main()
{

	//지역변수

	Add(10, 20);

	giExtern = 500;
	

	//포인터 변수
	//4바이트 변수에서 포인터로 변경 
	//int 변수를 가리키는 변수가 됨
	//해당 포인터가 전달된 주소를 해석하는 단위

	int i = 100;
	int* pInt = nullptr; 
	pInt = &i;

	float f = 3.f;
	//주소로 접근


	pInt = (int*) & f;
	i= *pInt;

	pInt += 1;
	//+4 증가됨(다음위치로)

	/*
	pInt = new int[100];

	pInt[10] = 100;
	delete[] pInt;
	*/

	//배열의 특징
	//1. 메모리가 연속적인 구조이다.
	//2. 배열의 이름은 배열의 시작 주소이다.

	int iArr[10] = {};
	
	//iArr[1] = *(iArr + 1);
	//같은표현

	*(iArr + 1) = 10;
	//iArr[1] = 10;

	*(iArr) = 10;


	int a;
	scanf_s("%d", &a);



	printf("%d\n", (int)sizeof(pInt));
	printf("%d\n", a);
	return 0;

} 