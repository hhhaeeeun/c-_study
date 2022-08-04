#pragma once

#include<assert.h>
template<typename T>
class CArr
{
private:
	T*			m_pData;
	int			m_iCount;
	int			m_iMaxCount;

public:
	void Push_back(const T& _Data);
	void resize(int _iResizeCount);
	T& operator[] (int idx);
	T& at(int idx) { return m_pData[idx]; }
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	class iterator;
	//레퍼런스는 기존 데이터가 있는 경우에 사용하지만 
	//이 경우에는 지역변수를 전달하기 때문에 
	//레퍼런스타입을 사용하지 않음
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	void clear();
public:
	//생성자와 소멸자는 public으로 생성해야 함
	CArr();
	~CArr();
	//class 내부 새로 class 생성
	//inner class
	//내부 데이터를 가르키는 변수 생성
	//내부 class도 template임
	//inner class가 포함된 class의 private 멤버 접근이 가능함
	class iterator
	{
	private:
		CArr* m_pArr; //iterator가 가리킬 데이터를 관리하는 가변배열 주소
		T* m_pData;
		int m_iIdx;
		bool m_bValid;


	public:
		T& operator* ()
		{
			//iterator가 알고있는 시작주소와 가변배열이 알고있는 주소가 달라진경우 오류처리
			//iterator가 end iterator 인 경우 오류처리
			if (m_pData != m_pArr->m_pData || -1 == m_iIdx || false == m_bValid)
				assert(nullptr);
			return m_pData[m_iIdx];
		}
		//전위 ++ 함수
		iterator& operator++ ()
		{
			//end iterator
			//주소가 변경됨
			if (m_pData != m_pArr->m_pData || -1 == m_iIdx|| false == m_bValid)
				assert(nullptr);

			//iterator가 마지막 데이터를 가리키고 있는 경우 
			if (m_iIdx == m_pArr->size() - 1)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		//후위 ++ 함수
		//int 인자를 작성하여 후위로 분류함
		iterator operator++(int)
		{
			//지역변수로 리턴하고 실제 값은 ++ 함
			//*this 확인 
			iterator copy_iter = *this;
			++(*this);
			return copy_iter;

		}
		//전위
		iterator& operator-- ()
		{
			//begin iterator
			//주소가 변경됨
			if (m_pData != m_pArr->m_pData || 0 == m_iIdx || false == m_bValid)
				assert(nullptr);

			//iterator가 end()를 가리키고 있는 경우 
			if (m_iIdx == -1)
			{
				m_iIdx = m_pArr->capacity() - 1;
			}
			else
			{
				--m_iIdx;
			}

			return *this;
		}
		//후위
		iterator operator--(int)
		{
			//지역변수로 리턴하고 실제 값은 -- 함
			//*this 확인 
			iterator copy_iter = *this;
			--(*this);
			return copy_iter;
		}

		bool operator == (const iterator& iter)
		{
			if ((m_iIdx == iter.m_iIdx) && (m_pData == iter.m_pData))
				return true;
			else
				return false;
		}
		bool operator != (const iterator& iter)
		{
			/*
			if (m_iIdx == iter.m_iIdx && m_pData == iter->m_pData)
				return false;
			else
				return true;
				*/
				//==operator의 기능을 반대로 사용
			return !(*this == iter);
		}


	public:
		iterator()
			:m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{

		}
		iterator(CArr* _pArr, T* _pData, int iIdx)
			:m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(iIdx)
			, m_bValid(false)
		{
			if (m_pArr != nullptr && 0 <= m_iIdx)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}
		friend class CArr;
	};
};


//주석 설정						: Ctrl + k , c 
//지정한 주석 해제		: Ctrl + k , u
//Alt Drag
//Alt Enter							: 정의만들기
//Ctal+tap							: 파일 간 이동
template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	//m_pInt = (int*)malloc(sizeof(int) * 2);
	m_pData = new T[2];
}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
	m_iCount = 0;
	m_iMaxCount = 0;
}
template<typename T>
void CArr<T>::Push_back(const T& _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//재할당
		resize(m_iMaxCount * 2);
	}
	//데이터 추가
	m_pData[m_iCount++] = _Data;
}
template<typename T>
void CArr<T>::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	//1. _iResizeCount 만큼 공간 할당
	T* pNew = new T[_iResizeCount];

	//2. 기존 데이터 복사
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	//3. 기존 메모리 해제
	delete[] m_pData;

	//4. 배열이 새로 할당된 공간을 가리키게 함
	m_pData = pNew;

	//5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	/*
	iterator iter;
	iter.m_pData = this->m_pData;
	iter.m_iIdx = 0;
	*/
	/*
	iterator iter(m_pData, 0);
	return iter;
	*/
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); //데이터가 없는 경우 begin() == end()

	//임시객체 생성하자마자 반환
	return iterator(this, this->m_pData, 0);
}
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	//iterator가 CArr의 주소를 입력받기 때문에 this를 전달
	return iterator(this, this->m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	//외부 class는 내부 class의 private에 접근할 수 없음
	//내부 class는 외부 class의 private에 접근할 수 있음
	//친구선언하면 서로의 private에 접근 가능
	//상대 클래스를 친구선언하면 나의 private를 상대클래스에게 오픈함
	

	//iterator가 가르키는 대상이 호출된 CArr와 다름
	//CArr구조체 형식검사, end iterator인 경우
	if ((_iter.m_pArr != this) || (_iter.m_iIdx >= this->m_iCount))
	{
		assert(nullptr);
	}
	if (end() == _iter)
		assert(nullptr);

	//iterator가 가리키는 데이터를 배열 내에서 제거
	_iter.m_iIdx;
	for (int i = _iter.m_iIdx; i < m_iCount - 1; ++i)
		m_pData[i] = m_pData[i + 1];

	--m_iCount;

	//이전 iterator 사용 불가 처리 
	//_iter(this, m_pData, _iter.m_iIdx);
	//iterator는 단지 포인터이기 때문에 주소값을 넣어주지 않아도 원래 클래스가 변경되면 같이 변경된 주소를 소지함
	//const여도 주소값을 변경하는 것이 아니기 때문에 상관없음
	//현재 함수가 const가 아닌 이유는 변경된 iterator의 오류처리를 해주기 위함 (m_bValid)
	_iter.m_bValid = false;

	return iterator(this, this->m_pData, _iter.m_iIdx);
}

template<typename T>
void CArr<T>::clear()
{
	m_iCount = 0;
}
