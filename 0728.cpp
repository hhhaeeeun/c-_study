#include "CList.h"
#include <vector>
#include <list>
#include<iostream>

using std::vector;
using std::list;
using std::cout;
using std::wcout;
using std::cin;
using std::endl;

int main()
{
	
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);

	vecInt[0] = 100;
	//vecInt.at(1);
	//�ε��� ���� ���۷����͸� ������ (�����迭)
	vecInt[1];
	vecInt.data();
	int a = vecInt.size();
	vecInt.capacity();

	for (size_t i = 0; i<vecInt.size(); ++i)
	{		cout << vecInt[i] << endl;
	}


	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(100);
	//�ε��� ���� ���۷����Ͱ� ����
	//���� �� ������ ���ӵ� �޸𸮸� ���� �ʱ� ����
	listInt.size();

	//iterator(inner class)
	list<int>::iterator iter = listInt.begin();
	int iData = *iter;

	
	//iterator
}

//�Լ������� ����
//(��ȯ��)(*�Լ������͸�)(�Է°�)