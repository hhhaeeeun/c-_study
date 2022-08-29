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
public:
	CParent()
		:m_i(0)
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
public:
	//클래스 생성자 각자 초기화 하기(자신의 멤버변수만 초기화)
	//생성자 호출 순서 : 
	CChild()
		//:CParent() //부모 생성자 호출 가능//자동호출됨 먼저!//거꾸로 적어도 같음
		//,m_f(0.f)
		//m_i(0) //불가능
		:m_f(0.f)
		,CParent()
	{
		//가능
		//m_i = 0;
		cout << "자식 생성자 호출" << endl;
	}
	~CChild()
	{}
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




	return 0;
}