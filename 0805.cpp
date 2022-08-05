#include<iostream>
#include"CList.h"


using std::cout;
using std::endl;


int main()
{
	CList<int> mylist;
	mylist.PushBack(100);
	mylist.PushBack(200);
	mylist.PushBack(300);

	CList<int>::iterator iter = mylist.begin();
	
	*iter = 150;
	++iter;
	iter = mylist.insert(iter, 5000);
	iter = mylist.erase(iter);

	for (iter = mylist.begin(); iter != mylist.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}