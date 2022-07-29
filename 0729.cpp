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
	//���� ǥ��
	//vector�� iterator�� ���� �ʿ� ���� ������ �� ����
	//�迭 ���� ���ٵ� �����ϱ� ����
	*veciter = 100;
	vecInt[0] = 100;

	//���� ���� ���� ������ �� iterator�� ���ڷ� ����
	//vecInt.erase()

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_front(20);


	//list�� Ư�� �ε��� ������ ��ȿ����
	//iterator�� ��ȸ�ϸ鼭 �����ؾ� ��
	list<int>::iterator listiter = listInt.begin();

	cout << "����" << endl;
	//listInt.end() ���������� �ϳ� �� �����̱� ������ end()������ ����ϸ� ��� ���� ��µ�
	//list ����ü�� ��ȸ��
	for (listiter = listInt.begin(); listiter != listInt.end(); ++listiter)
	{
		cout << *listiter << endl;
	}
	cout << "��" << endl;
}