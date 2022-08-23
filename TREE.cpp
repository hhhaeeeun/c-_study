#include <iostream>
#include <map>
#include<set>

using std::cout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

#define MAN 1
#define WOMAN 2

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


	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = stdMap.find(L"ȫ�浿");

	const wchar_t* tmp = (*mapiter).first;
	tStdInfo temp = (*mapiter).second;

	//mapiter->first
	//mapiter->second 

	//���� ���� ã���� end iterator�� ��ȯ��
	mapiter = stdMap.find(L"���浿");

	//�����͸� ã�� ���� 
	if (mapiter == stdMap.end())
	{
	
		cout << "�����͸� ã�� �� ����." << endl;
	}

	return 0; 

} 