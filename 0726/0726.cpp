#include <iostream>
#include"Arr.h"
#include "CArr.h"


int main()
{

	//구조체 --> 클래스 
	//객체지향 언어 특징
	
	//1. 캡슐화
	//기능을 수행하기 위해 필요한 멤버 선언, 묶음, 은닉성
	//멤버 함수들

	//2. 상속

	//3. 다형성 
	
	//4. 추상화 
	 
	//구조체 버전 가변베열 --> 클래스 버전

	//C++ 동적할당 new, delete
	//new, delete에 생성자, 소멸자 호출이 포함됨

	tArr arr = {};

	InitArr(&arr);

	PushBack(&arr, 10);
	PushBack(&arr, 20);
	PushBack(&arr, 30);

	ReleaseArr(&arr);

	CArr carr;
	carr.Push_back(10);
	carr.Push_back(20);
	carr.Push_back(30);

	int iData = carr[1];
	carr[1] = 40;

	return 0;
}