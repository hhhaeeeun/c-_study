#include <iostream>
#include <map>
#include<set>

using std::cout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

#define MAN 1
#define WOMAN 2

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


	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = stdMap.find(L"홍길동");

	const wchar_t* tmp = (*mapiter).first;
	tStdInfo temp = (*mapiter).second;

	//mapiter->first
	//mapiter->second 

	//없는 값을 찾으면 end iterator로 반환됨
	mapiter = stdMap.find(L"엄길동");

	//데이터를 찾지 못함 
	if (mapiter == stdMap.end())
	{
	
		cout << "데이터를 찾을 수 없다." << endl;
	}

	return 0; 

} 