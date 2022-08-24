#include <iostream>
#include <map>
#include<set>

#include <string>
#include "CBST.h"

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;
using std::wstring;

#define MAN 1
#define WOMAN 2

//������
enum MY_TYPE
{
	TYPE_1,	//0
	TYPE_2,	//1
	TYPE_3,	//2
	TYPE_4 = 100,
	TYPE_5, //101
};

int a = TYPE_3;
//a = 2

enum class OTHER_TYPE
{
	TYPE_7,	//0
	TYPE_1,	//1

};


int b = TYPE_1;
//b = 0;
int c = (int)OTHER_TYPE::TYPE_1;
//c = 1;

#define CLASS_1 0
#define CLASS_2 1

int d = CLASS_1;
//int d = 0;
//��ó����
//����� �� 0 ���� ����(������ ����)
//define�� �ٽ� ã�ƾ� ��
//����� �Ұ�

//enum
//����뿡�� TYPE_1�� ���� �� �ְ� ��
//Ÿ�� ������ �ν��ϰ� ����

struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;


	tStdInfo()
		:szName{}
		,age(0)
		,gender(0)
	{
	}
	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		:szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

struct pair
{
	const wchar_t* p;
	tStdInfo info;
};
//inline
//����ȭ ��û
//�ڵ带 �����ؼ� (ȣ������ �ʰ�) �����ϵ��� ���
//template class : ������� ����
//�Լ��� ȣ���ϴ� �ʿ� �Լ� ������ ������
//�Լ� ȣ������ ������
//�ڵ尡 �� �Լ��� inline���� �ۼ��Ͽ��� ������ �����ϴ°��� �ε尡 �� �ɸ��� ��쿡�� �ζ������� ������� ����(������ ����)
//1~2���� ª�� �ڵ�� ����(inline) ó����
//get, setting �Լ� inline (����� ����)
int main()
{
	//����Ž��
	//1. ���ĵǾ��ִ� �����Ϳ� ���밡��
	//2. ������ ���ݾ� �ٿ�����


	//����Ž��Ʈ�� 
	//1. ����Ž���� ��� �� �� �ְ� ��ȵ� ����Ʈ�� 
	//2. ������ �Է� �� O(logN) ȿ��
	//3. Ž�� ȿ���� O(logN)
	//4. Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
	//	-�ڰ����� ��� (AVL tree, Red/Black tree)


	//Red/Black tree
	//�����Ҵ�, �� �޸� ���� ���
	set<int> setInt;
	
	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	//ROM �ּҸ� ��
	const wchar_t* pStr = L"���ڿ�";
	

	//2���� Ÿ�� ����
	//<Ű, ��>
	map<int, float> mapData;


	map<const wchar_t*, tStdInfo> stdMap;
	tStdInfo info1(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	stdMap.insert(make_pair(L"ȫ�浿", info1));
	stdMap.insert(make_pair(L"������", info2));


	//���� Ű ���� ���ڿ��� �ּҷ� ������
	//���ڿ� �� ��ü�� ���ϴ� ���� �ƴ�
	//���ڸ� ���Ͽ� ã����� ��쿡�� ���ڿ� Ŭ������ �־��־�� ��
	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = stdMap.find(L"ȫ�浿");

	const wchar_t* tmp = (*mapiter).first;
	tStdInfo temp = (*mapiter).second;

	//mapiter->first
	//mapiter->second 

	//���� ���� ã���� end iterator�� ��ȯ��
	mapiter = stdMap.find(L"������");
	_wsetlocale(LC_ALL, L"korean");
	//�����͸� ã�� ���� 
	if (mapiter == stdMap.end())
	{
		wcout <<  L"�����͸� ã�� �� ����." << endl;
	}
	else
	{
		wcout << L"�̸� : " << mapiter->second.szName << endl;
		wcout << L"���� : " << mapiter->second.age << endl;
		if (MAN == mapiter->second.gender)
		{
			wcout << L"���� : ����" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"���� : ����" << endl;
		}
		else
		{
			wcout << L"���� : �� �� ����" << endl;
		}
	
		
	}	
	
	//���ڸ� ���Ͽ� ã����� ��쿡�� ���ڿ� Ŭ������ �־��־�� ��
	//�񱳿����ڰ� ������ �Ǿ��ִ� Ŭ������ ����
	map<wstring, tStdInfo> mapStdInfo;


	wstring str;
	//�迭�ʱ�ȭ, ���ڸ� ���� (�б�޸� �ּҰ� �ƴ�)
	//�ڽ��� ���� �ȿ� ���ڸ� �����ϴ� = ���۷����Ͱ� ������
	//���ڸ� �߰��ϴ� += ���۷����͵� ������
	str = L"abcdef";
	str += L"ghijk";
	str += L"lmnop";

	wcout << str << endl;

	//������ ������ �����Ҵ� ���
	//�����迭�� ���� (vector<wchar_t>)
	str = L"abcdefghijklmnop";
	str[1] = L'c';

	wstring str2;

	// ==, < , > ���۷����Ͱ� ��� ����
	//�ʿ��� �����ϰ� �� �����ڸ� ����� �� ����
	if (str == str2)
	{
		//�ڽ��� ���ڿ��� �� 
		//�ּҰ��� Ȯ���ϴ� ���� �ƴ�

	}


	CBST<int, int> bstint;
	

	tPair<int, int> pair;
	pair.first = 100;
	bstint.insert(pair);
	pair.first = 150;
	bstint.insert(pair);
	pair.first = 50;
	bstint.insert(pair);


	wcout << a << endl;
	wcout << b << endl;
	wcout << c << endl;
	return 0; 

} 