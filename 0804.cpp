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

int main()
{
	//vector::erase
	vector<int> vecInt;

	vecInt.push_back(100);
	vecInt.push_back(200);
	vecInt.push_back(300);
	vecInt.push_back(400);

	vector<int>::iterator veciter = vecInt.begin();

	//vecInt.erase(veciter);

	//������ iterator�� �����ϸ� ������ �߻���
	//int i = *veciter;
	//�ٽ� �ʱⰪ�� ����Ų �� ����ϰų� ���ϰ��� �޾ƾ߿� �t
	veciter = vecInt.erase(++veciter);
	int i = *veciter;
	cout << i << endl;
	veciter = vecInt.begin();



	vecInt.clear();

	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i + 1);
	}
	veciter = vecInt.begin();
	/*
	for (int i = 0; i < 10; ++i)
	{
		if (i + 1 % 2 == 0)
		{
			vecInt.erase(veciter);
		}
		++veciter;
	}
	*/
	//¦�� �� ����
	for (; veciter != vecInt.end(); )
	{
		if (*veciter % 2 == 0)
		{
			//�ڵ� ++�̱� ������ for������ ++�ϸ� �ȵ�
			veciter = vecInt.erase(veciter);
		}
		else
		{
			++veciter;
		}
	}
	veciter = vecInt.begin();
	for (; veciter != vecInt.end(); ++veciter)
		cout << *veciter << endl;

	CArr<int> a; 
	a.Push_back(10);
	a.Push_back(20);
	a.Push_back(30);
	a.Push_back(40);
	CArr<int>::iterator iter = a.begin();
	
	iter = a.erase(iter);

	int u = *iter;


	return 0;
}