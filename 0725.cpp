#include <iostream>
#include "Arr.h"
struct tMy
{

};

class CMy
{

private :
	int m_i;
	float m_f;
public:
	void SetInt(int i)
	{
		m_i = i;
	}

	//대입 연산자

	 CMy& operator = (const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this;
	}
	CMy& operator + (const CMy& _Other)
	{
		m_i += _Other.m_i;
		m_f += _Other.m_f;

		return *this;
	}
	void print_m_i()
	{
		printf("m_i : %d\n", m_i);
	}
public:
	//생성자
	CMy()
		: m_i(100)
		, m_f(0.f)
	{
		//m_i = 100;
		//m_f = 0.f;
	}
	//소멸자
	~CMy()
	{

	}
};


int main()
{
	//C++ 클래스 특징
	//접근 제한 지정자
	//private, protected(상속), public
	
	//생성자, 소멸자 
	//객체 생성, 소멸 시 자동으로 호출
	//직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐 
	
	//멤버함수
	//해당 클래스가 사용하는 전용 함수
	//해당 클래스의 객체(instance)가 필요함
	//int(자료형) a(객체)
	//멤버함수를 객체를 통해서 호출하면, 해당 객체의 주소가 this 포인터로 전달된다.

	{
		//자료형* 변수명;            포인터 변수 선언
		//*포인터변수;                 포인터 주소 역참조
		//&변수;                              변수의 주소값
		//자료형& 변수명;;          레퍼런스 변수 선언


		//C++에 추가된 기능
		//포인터와 유사
		//원본을 참조한다.
		//참조변수를 통해서 직접적으로 원본을 수정 할 수 있다. 

		int a = 10;

		int* p = &a;
		*p = 100;

		int& iRef = a;
		iRef = 100;
		//레퍼런스 변수 장점
		//한번 참조 이후 변경이 불가능 int* const p = &a 와 같음
		//역참조 없이 값을 수정할 수 있음
		//호출방식이 다름
		//주소를 받는 것이 아니라 그 자체가 됨

		const int* p2 = &a;
		//*p2 = 100;

		const int& iRefConst = a;
		//const int* const p2 = &a; 와 같음
		//iRefConst = 100;
	}

	tArr arr = {};
	InitArr(&arr);
	PushBack(&arr, 10);
	arr.iCount = 100;
	ReleaseArr(&arr);

	CMy c;
	c.SetInt(10);

	CMy c2;
	c2.SetInt(100);
	c2.print_m_i();
	CMy c3;
	c3.SetInt(1000);

	c2 = c2 + c3;
	c2.print_m_i();


	return 0;
}