#include <iostream>
#include <map>

using std::map;
using std::make_pair;



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







	return 0; 

} 