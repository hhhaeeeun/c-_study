#include <vector>
#include <list>
#include<iostream>
#include"CArr.h"

using std::vector;
using std::list;
using std::cout;
using std::wcout;
using std::cin;
using std::endl;


//class의 자동으로 생성되는 영역 
//생성자, 소멸자
//대입연산자
//복사생성자
//생성자를 하나라도 작성하면 기본생성자를 자동으로 생성해주지 않음 
//오류날 수 있으니 꼭 따로 작성해야함
//의문 : 소멸자는?
class CTest
{
private:
	int m_i;

public:
	//대입연산자
	CTest& operator = (const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}
	//기본생성자
	CTest()
		:m_i(0)
	{

	}
	//복사생성자
	CTest(const CTest& _other)
		:m_i(_other.m_i)
	{

	}
};

int main()
{
	CArr<int> myvector;

	myvector.Push_back(1);
	myvector.Push_back(2);
	myvector.Push_back(3);

	CArr<int>::iterator CArrIter = myvector.begin();

	for (; CArrIter != myvector.end(); ++CArrIter)
	{
		cout << *CArrIter << endl;
	}
	CTest t1;
	CTest t2(t1);

	//복사생성자가 아니고 대입operator인데
	//생성자(init) 후 대입연산이 아니고 컴파일러가 복사생성자를 자동으로 호출해줌
	CTest t3 = t1;
}