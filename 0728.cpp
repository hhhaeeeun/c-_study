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
	//인덱스 접근 오퍼레이터를 제공함 (가변배열)
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
	//인덱스 접근 오퍼레이터가 없음
	//만들 수 있지만 연속된 메모리를 갖지 않기 떄문
	listInt.size();

	//iterator(inner class)
	list<int>::iterator iter = listInt.begin();
	int iData = *iter;

	
	//iterator
}

//함수포인터 복습
//(반환값)(*함수포인터명)(입력값)