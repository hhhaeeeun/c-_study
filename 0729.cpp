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

	cout << vecInt[0] << endl;
	cout << vecInt[1] << endl;
	cout << vecInt.at(0) << endl;
	cout << vecInt.at(1) << endl;

	vector<int>::iterator veciter = vecInt.begin();
	//같은 표현
	//vector는 iterator가 굳이 필요 없게 느껴질 수 있음
	//배열 형태 접근도 가능하기 때문
	*veciter = 100;
	vecInt[0] = 100;

	//벡터 내부 값을 삭제할 때 iterator를 인자로 받음
	//vecInt.erase()

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_front(20);


	//list는 특정 인덱스 접근이 비효율적
	//iterator로 순회하면서 접근해야 함
	list<int>::iterator listiter = listInt.begin();

	cout << "시작" << endl;
	//listInt.end() 마지막보다 하나 더 다음이기 때문에 end()전까지 출력하면 모든 값이 출력됨
	//list 구조체의 순회법
	for (listiter = listInt.begin(); listiter != listInt.end(); ++listiter)
	{
		cout << *listiter << endl;
	}
	cout << "끝" << endl;
}