#include<stdio.h>


int main()
{
	const int cint = 100;
	//volatile const int cint = 100;
	//위와 같이 하면 레지스터 최적화를 사용하지 않음(volatile 옵션)
	

	int* pint = nullptr;

	//const 값에 억지로 접근하여 값을 변경
	pint = (int*) & cint;
	(*pint) = 300;
	

	//값이 바뀌어서 300으로 출력됨
	printf("%d\n", *pint);
	//레지스터 값을 가져오기 때문에 100으로 출력됨
	printf("%d\n", cint);
	//결론 : 상수로 처리해도 변수 공간은 할당됨
}