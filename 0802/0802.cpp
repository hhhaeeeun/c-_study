#include<iostream>
#include "CArr.h"
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
	CArr<int> t;

	vector<int> vecInt;
	vecInt.push_back(1);
	vecInt[0] = 10;

	vector<int>::iterator iter = vecInt.begin();
	int i = *iter;
}