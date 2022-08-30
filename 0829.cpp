#include <iostream>

using std::cout;
using std::endl;


class CParent
{
//protected : 상속받은 class만 접근이 가능하도록 선언
//private : 상속 받아도 직접 접근이 불가능
//public : 모두 접근 가능
protected:
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	//virtual 가상함수 화
	virtual void OutPut()
	{
		cout << "Parent" << endl;
	}
public:
	//기본 생성자
	CParent()
		:m_i(0)
	{
		cout << "부모 생성자 호출" << endl;
	}

	CParent(int _a)
		:m_i(_a)
	{
		cout << "부모 생성자 호출" << endl;
	}


	~CParent()
	{}
};


class CChild : public CParent
{
private:
	float m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 10;
	}

	//상속받은 부모클래스의 함수를 재정의(오버라이딩) 함
	void OutPut()
	{
		cout << "Child" << endl;
	}

	void NewFunc()
	{
		cout << "new function" << endl;
	}

public:
	//클래스 생성자 각자 초기화 하기(자신의 멤버변수만 초기화)
	//생성자 호출 순서 : 
	CChild()
		//:CParent() //부모 생성자 호출 가능//적지 않아도 부모 클래스의 생성자가 먼저 자동호출됨!//거꾸로 적어도 같음
		//,m_f(0.f)
		//m_i(0) //불가능
		:m_f(0.f)
		,CParent(1000)
	{
		//가능
		//m_i = 0;
		cout << "자식 생성자 호출" << endl;
	}
	~CChild()
	{
		//자식 소멸 끝나고
		//부모 소멸자 호출 !
	}
};

void FuncA()
{
	cout << "Func A" << endl;
}


void FuncB()
{
	FuncA();

	cout << "Func B" << endl;
}
int main()
{

	//FunB가 호출되었지만
	//함수 완료 기준 순서는 A->B
	//호출순서는 B->A
	FuncB();

	//생성자(상속) 호출도 마찬가지로
	//실행순서는 부모->자식
	//호출순서는 자식->부모

	//객체지향 언어 특징
	//1. 캡슐화(은닉성)
	//2. 상속
	//3. 다형성
	//4. 추상화


	CParent parent;
	//CChild = CParent + CChild
	CChild child;
	parent.SetInt(10);
	child.SetInt(10);

	//상속
	//자식 or 부모 클래스는 상속관계에서 다른 클래스의 멤버를 초기화 할 수 없다.
	//생성자는 자식 생성자 호출되자마자 부모부터 생성
	//생성자 실행순서 : 부모 -> 자식
	//생성자 호출순서 : 자식 -> 부모
	
	//오버로딩 vs 오버라이딩
	//오버로딩 : 함수명이 같지만 인자가 다름 (타입or개수)
	//오버라이딩 : 인자가 같아도 자식쪽에서 재정의 가능

	parent.OutPut();
	//자식의 OutPut을 호출
	//오버라이딩
	child.OutPut();
	//부모의 OutPut을 호출 가능
	//가상함수여도 부모의 OutPut 호출이 가능함
	child.CParent::OutPut();


	//소멸자
	//소멸자는 자식 소멸 다 하고 부모호출하여 소멸 한 후 자식으로 돌아와서 종료
	//소멸자 실행순서 : 자식 -> 부모 
	//소멸자 호출순서 : 자식 -> 부모



	//다형성
	//상속, 포인터

	//CParent* pParent = &parent;
	//CChild* pChild = &child;


	CParent* pParent = &child;
	//오류 안남
	//메모리에 부모->자식 순으로 구성되어있음
	//부모 클래스 포인터로 받을 수 있음
	//CChild* pChild = &parent;
	//오류 남

	pParent->OutPut();
	//child의 주소를 받아도 parent객체의 OutPut함수를 호출함
	//child의 오버라이딩 된 함수를 호출할 수 없음

	//virtual 가상함수화 하면 parent 포인터로 자식의 오버라이딩 된 함수 호출 가능
	//다형성, 가상함수
	//가상함수로 선언하면 애초에 자식클래스 생성시에 부모의 가상함수 테이블에 자식의 오버라이딩 된 함수가 등록되어있음


	//다운캐스팅
	//자식에서 새로 생성된 함수에 접근하고 싶은 경우
	//강제캐스팅 or dynamic cast 가능
	((CChild*)pParent)->NewFunc();
	//오류 가능성이 높음
	CChild* pChild = dynamic_cast<CChild*>(pParent);
	//오류 처리 가능!
	if (nullptr != pChild)
	{
		pChild->NewFunc();
	}
	//RTTI(Run Time Identification or Information


	//추상화
	//실제 객체를 생성할 목작의 클래스가 아닌, 상속을 통해서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
	//virtual , = 0 (1개 이상의 순수 가상함수를 포함하면 추상클래스가 된다)

	return 0;
}