#include<iostream>
#include <wchar.h>
#include "CList.h"
namespace MYSPACE
{
	int g_int;
}
namespace OTHERSPACE
{
	int g_int;
}
//using namespace std;
using std::cout;
using std::wcout;
using std::cin;
using std::endl;

void MyEndlL()
{
	wprintf(L"\n");
}

class CMyOStream
{

public:
	//template<typename T>
	CMyOStream& operator << (int _idata)
	{
		wprintf(L"%d", _idata);
		return *this;
	}

	CMyOStream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}
	CMyOStream& operator >> (int& _pString)
	{
		scanf_s("%d", &_pString);
		return *this;
	}
	CMyOStream& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}

};

CMyOStream mycout;
int main()
{
	CList<int> list;


	for (int i = 0; i < 4; ++i)
	{
		list.PushBack(i);
	}

	//C printf
	//ostream���� ���� extern ����(����������)
	//<< ������ �����ε�
	cout << "�ȳ�" << 10 << endl;

	//C scanf
	//istream���� ���� extern ����(����������)
	int iInput = 0;

	MYSPACE::g_int = 10;
	OTHERSPACE::g_int = 100;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	mycout << 10 << MyEndlL;
	mycout << L"�ѱ�" << MyEndlL;;

	int a = 0;
	mycout >> a;
	mycout << a;
	return 0;
	 
}  