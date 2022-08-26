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



int main()
{


	CBST<int, int> bstint;
	//Pair<int, int> pair;

	
	//pair.first = 100;
	//bstint.insert(pair);
	//pair.first = 150;
	//bstint.insert(pair);
	//pair.first = 50;
	//bstint.insert(pair);

	bstint.insert(make_bstpair(100, 0));	//								100
	bstint.insert(make_bstpair(150, 0));	//					50					150
	bstint.insert(make_bstpair(50, 0));//		25			75			125			175
	bstint.insert(make_bstpair(25, 0));
	bstint.insert(make_bstpair(75, 0));
	bstint.insert(make_bstpair(125, 0));
	bstint.insert(make_bstpair(175, 0));

	CBST<int, int>::iterator bstiter = bstint.find(100);
	/*
	if (bstiter == bstint.end())
	{
		//데이터가 없음
	}
	*/

	//연산자 operator
	//!=, ==, ++, -- , ->
	for (bstiter = bstint.begin(); bstiter != bstint.end(); ++bstiter)
	{
		wcout << bstiter->first << bstiter->second << endl;
	}

	bstiter = bstint.erase(bstiter);



	map<int, int> mapInt;


	mapInt.insert(make_pair(100, 100));
	map<int,int>::iterator mapiter = mapInt.find(100);
	if (mapiter == mapInt.end())
	{
		//데이터가 없음
	}



	return 0;
}

