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

	//삭제된 iterator에 접근하면 오류가 발생함
	//int i = *veciter;
	//다시 초기값을 가리킨 후 사용하거나 리턴값을 받아야와 햠
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
	//짝수 값 삭제
	for (; veciter != vecInt.end(); )
	{
		if (*veciter % 2 == 0)
		{
			//자동 ++이기 때문에 for문에서 ++하면 안됨
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