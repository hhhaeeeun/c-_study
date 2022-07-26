#pragma once
class CArr
{
private:
	int*			m_pInt;
	int			m_iCount;
	int			m_iMaxCount;

public:
	void Push_back(int _Data);
	void resize(int _iResizeCount);

	int& operator[] (int idx);


public:
	//생성자와 소멸자는 public으로 생성해야 함
	CArr();
	~CArr();
};


//주석 설정						: Ctrl + k , c 
//지정한 주석 해제		: Ctrl + k , u
//Alt Drag
//Alt Enter							: 정의만들기
//Ctal+tap							: 파일 간 이동

