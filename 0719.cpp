#include<stdio.h>

void Output(const int* pI)
{
	int i = *pI;
	//*pI = 100;
	//값의 변경이 불가함

	int* pInt = (int*)pI;
	*pInt = 1000;
	//억지로 변경
	
}
int main()
{
	const int cint = 100;
	//volatile const int cint = 100;
	//위와 같이 하면 레지스터 최적화를 사용하지 않음(volatile 옵션)


	int* pint = nullptr;

	//const 값에 억지로 접근하여 값을 변경
	pint = (int*)&cint;
	(*pint) = 300;


	//값이 바뀌어서 300으로 출력됨
	printf("%d\n", *pint);
	//레지스터 값을 가져오기 때문에 100으로 출력됨
	printf("%d\n", cint);
	//결론 : 상수로 처리해도 변수 공간은 할당됨


	const int i = 100;

	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	//a 변수 값이 바뀜
	pInt = nullptr;
	//포인터 값이 바뀜


	const int* pConstInt = &a;
	//*pConstInt = 100;
	//식이 수정할 수 있는 Lvalue 여야 합니다.
	// 해당 값은 rvalue임을 의미
	//const 포인터는 원본 데이터를 수정할 수 없음
	//결론 : const int를 가리키는 포인터(해당 값이 const 화)

	int b = 0;
	pConstInt = &b;



	int* const pIntConst = &a;
	*pIntConst = 400;

	//pIntConst = &b;
	//식이 수정할 수 있는 Lvalue 여야 합니다.
	// 해당 값은 rvalue임을 의미
	//const 포인터는 초기값을 수정할 수 없음
	//결론 : 포인터 자체가 const라서 수정이 불가능함



	const int* const pConstIntConst = nullptr;
	//초기화 시 가리킨 대상만 가리킴, 가리키는 원본 수정도 불가

	int const* p = &a;
	//*p = 0
	//오류

	{
		int a = 0;
		const int* pInt = &a;
		a = 100;

		int* p = &a;
		*p = 200;

		//a가 0에서 100에서 200이 됨
	}

	a = 100;
	Output(&a);
	//전달 데이터가 너무 커서 지역변수를 새로 생성하기 싫을 때 주소를 전달하지만 원본 수정을 방지



	void* pVoid = nullptr;
	//모든 자료형의 주소를 전달 받아도 오류가 나지 않음
	// 원본의 자료형을 정하지 않음
	//자료 해석이 불분명함
	//역참조 불가능(해석이 안되기 때문에)
	//주소연산도 안됨

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
		둘 다 불가능
		*/
		
	}


	
}




//함수 원형 확인 단축키
// Ctrl + Shift + Space