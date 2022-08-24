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

#define MAN 1
#define WOMAN 2

//열거형
enum MY_TYPE
{
	TYPE_1,	//0
	TYPE_2,	//1
	TYPE_3,	//2
	TYPE_4 = 100,
	TYPE_5, //101
};

int a = TYPE_3;
//a = 2

enum class OTHER_TYPE
{
	TYPE_7,	//0
	TYPE_1,	//1

};


int b = TYPE_1;
//b = 0;
int c = (int)OTHER_TYPE::TYPE_1;
//c = 1;

#define CLASS_1 0
#define CLASS_2 1

int d = CLASS_1;
//int d = 0;
//전처리기
//디버깅 시 0 으로 보임(값으로 보임)
//define을 다시 찾아야 함
//디버깅 불가

//enum
//디버깅에도 TYPE_1로 보일 수 있게 함
//타입 정보를 인식하고 있음

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
//최적화 요청
//코드를 복사해서 (호출하지 않고) 동작하도록 사용
//template class : 헤더에서 구현
//함수를 호출하는 쪽에 함수 내용을 복사함
//함수 호출비용이 절감됨
//코드가 긴 함수를 inline으로 작성하여도 여러번 복사하는것이 로드가 더 걸리는 경우에는 인라인으로 복사되지 않음(오히려 손해)
//1~2줄의 짧은 코드는 복사(inline) 처리됨
//get, setting 함수 inline (헤더에 구현)
int main()
{
	//이진탐색
	//1. 정렬되어있는 데이터에 적용가능
	//2. 문제를 절반씩 줄여나감


	//이진탐색트리 
	//1. 이진탐색을 사용 할 수 있게 고안된 이진트리 
	//2. 데이터 입력 시 O(logN) 효율
	//3. 탐색 효율은 O(logN)
	//4. 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
	//	-자가균형 기능 (AVL tree, Red/Black tree)


	//Red/Black tree
	//동적할당, 힙 메모리 영역 사용
	set<int> setInt;
	
	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	//ROM 주소를 줌
	const wchar_t* pStr = L"문자열";
	

	//2개의 타입 지정
	//<키, 값>
	map<int, float> mapData;


	map<const wchar_t*, tStdInfo> stdMap;
	tStdInfo info1(L"홍길동", 18, MAN);
	tStdInfo info2(L"김하은", 25, WOMAN);

	stdMap.insert(make_pair(L"홍길동", info1));
	stdMap.insert(make_pair(L"김하은", info2));


	//맵의 키 값을 문자열의 주소로 저장함
	//문자열 그 자체로 비교하는 것이 아님
	//문자를 비교하여 찾고싶은 경우에는 문자열 클래스를 넣어주어야 함
	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = stdMap.find(L"홍길동");

	const wchar_t* tmp = (*mapiter).first;
	tStdInfo temp = (*mapiter).second;

	//mapiter->first
	//mapiter->second 

	//없는 값을 찾으면 end iterator로 반환됨
	mapiter = stdMap.find(L"김하은");
	_wsetlocale(LC_ALL, L"korean");
	//데이터를 찾지 못함 
	if (mapiter == stdMap.end())
	{
		wcout <<  L"데이터를 찾을 수 없다." << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		if (MAN == mapiter->second.gender)
		{
			wcout << L"성별 : 남자" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"성별 : 여자" << endl;
		}
		else
		{
			wcout << L"성별 : 알 수 없음" << endl;
		}
	
		
	}	
	
	//문자를 비교하여 찾고싶은 경우에는 문자열 클래스를 넣어주어야 함
	//비교연산자가 구현이 되어있는 클래스만 가능
	map<wstring, tStdInfo> mapStdInfo;


	wstring str;
	//배열초기화, 문자를 넣음 (읽기메모리 주소가 아님)
	//자신의 공간 안에 문자를 삽입하는 = 오퍼레이터가 존재함
	//문자를 추가하는 += 오퍼레이터도 존재함
	str = L"abcdef";
	str += L"ghijk";
	str += L"lmnop";

	wcout << str << endl;

	//별도의 공간에 동적할당 사용
	//가변배열과 유사 (vector<wchar_t>)
	str = L"abcdefghijklmnop";
	str[1] = L'c';

	wstring str2;

	// ==, < , > 오퍼레이터가 모두 존재
	//맵에서 유용하게 비교 연산자를 사용할 수 있음
	if (str == str2)
	{
		//자신의 문자열을 비교 
		//주소값을 확인하는 것이 아님

	}


	CBST<int, int> bstint;
	

	tPair<int, int> pair;
	pair.first = 100;
	bstint.insert(pair);
	pair.first = 150;
	bstint.insert(pair);
	pair.first = 50;
	bstint.insert(pair);


	wcout << a << endl;
	wcout << b << endl;
	wcout << c << endl;
	return 0; 

} 