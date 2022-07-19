#include<stdio.h>
#include<iostream>


int Factorial(int _iCnt)
{
	int result = 1;

	for (int j = 2; j < _iCnt + 1; ++j)
	{
		result *= j;
	}
	 
	return result;
}

int Factorial_Re(int _iCnt)
{
	if (_iCnt == 1)
	{
		return 1;
	}
	return _iCnt * Factorial_Re(_iCnt - 1);
}

int Fibonacci(int _iCnt)
{
	if (_iCnt == 1 || _iCnt == 2)
	{
		return 1;
	}
	int iPriv1 = 1;
	int iPriv2 = 1;
	int iValue = 0;
	for (int i = 0; i < _iCnt - 2; i++)
	{
		iValue = iPriv1 + iPriv2;
		iPriv2 = iPriv1;
		iPriv1 = iValue;
	}
	
	return iValue;
}

int Fibonacci_Re(int _iCnt)
{
	if (_iCnt == 1 || _iCnt == 2)
	{
		return 1;
	}	
	return (Fibonacci_Re(_iCnt - 1) + Fibonacci_Re(_iCnt - 2));
}


typedef struct _tagMyST
{ 
	int a;
	float f;
}MYST;

typedef struct _tagBIG
{
	MYST k;
	int i;
	float c;
}BIG;


typedef int INT;

int main()
{
	MYST t;

	BIG b;
	b.k.a = 10;


	int iValue = 0;
	iValue = sizeof(MYST);


	t.a = 10;
	t.f = 3.f;

	printf("%d\n", iValue);
	return 0;
} 
